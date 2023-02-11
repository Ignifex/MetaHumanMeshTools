// Fill out your copyright notice in the Description page of Project Settings.


#include "FaceMorphTargetCopy.h"
#include <Rendering/SkeletalMeshModel.h>


void UFaceMorphTargetCopy::CopyFaceMorphTargets(USkeletalMesh* sourceMesh, USkeletalMesh* targetMesh)
{
	auto sourceModel = sourceMesh->GetImportedModel();
	auto targetModel = targetMesh->GetImportedModel();

	// Check if the two meshes have at least one LOD level
	if (sourceModel->LODModels.Num() < 1 || targetModel->LODModels.Num() < 1)
	{
		UE_LOG(LogScript, Warning, TEXT("CopyFaceMorphTargets: Missing LOD data in supplied meshes!"));
		return;
	}
	// Check if the two meshes have the same number of vertices
	// This is a rough check for topology and vertex order, but also guards against access violations
	if (sourceModel->LODModels[0].NumVertices != targetModel->LODModels[0].NumVertices)
	{
		UE_LOG(LogScript, Warning, TEXT("CopyFaceMorphTargets: Target and reference meshes have mismatching vertex counts!"));
		return;
	}

	// For each morph target in the source mesh
	auto& sourceMorphTargets = sourceMesh->GetMorphTargets();
	TArray<UMorphTarget*> newMorphTargets;
	for (auto morphTarget : sourceMorphTargets)
	{
		// Safety checks: check if it is valid and contains at least one LOD model
		if (!morphTarget)
			continue;
		if (morphTarget->GetMorphLODModels().Num() == 0)
			continue;

		// Create a new morph target for the target mesh with the same name
		UMorphTarget* newMorphTarget = NewObject<UMorphTarget>(targetMesh, morphTarget->GetFName());
		newMorphTarget->BaseSkelMesh = targetMesh;
		newMorphTarget->GetMorphLODModels().AddDefaulted(1);
		// Copy source data into the new morph target
		auto& deltas = morphTarget->GetMorphLODModels()[0].Vertices;
		auto& sections = targetModel->LODModels[0].Sections;
		newMorphTarget->PopulateDeltas(deltas, 0, sections, true, false, 0.0f);

		newMorphTargets.Add(newMorphTarget);
	}

	// Add the new morph target to the target mesh and mark the target mesh as changed
	targetMesh->Modify();
	targetMesh->SetMorphTargets(newMorphTargets);
	targetMesh->InitMorphTargetsAndRebuildRenderData();
}

void UFaceMorphTargetCopy::CopyFaceMorphTargetsUsingReference(USkeletalMesh* OriginalSourceMesh, USkeletalMesh* VertexPositionReferenceMesh, USkeletalMesh* TargetMesh)
{
	FString testOutput;

	auto sourceModel = OriginalSourceMesh->GetImportedModel();
	auto referenceModel = VertexPositionReferenceMesh->GetImportedModel();
	auto targetModel = TargetMesh->GetImportedModel();

	// Check if the three meshes have at least one LOD level
	if (sourceModel->LODModels.Num() < 1 || referenceModel->LODModels.Num() < 1 || targetModel->LODModels.Num() < 1)
	{
		UE_LOG(LogScript, Warning, TEXT("CopyFaceMorphTargetsUsingReference: Missing LOD data in supplied meshes!"));
		return;
	}
	// Check if the reference and target meshes have the same number of vertices
	// This is a rough check for topology and vertex order, but also guards against access violations
	if (referenceModel->LODModels[0].NumVertices != targetModel->LODModels[0].NumVertices)
	{
		UE_LOG(LogScript, Warning, TEXT("CopyFaceMorphTargetsUsingReference: Target and reference meshes have mismatching vertex counts!"));
		return;
	}
	// Check if the source and reference meshes have the same number of sections
	if (sourceModel->LODModels[0].Sections.Num() != referenceModel->LODModels[0].Sections.Num())
	{
		UE_LOG(LogScript, Warning, TEXT("CopyFaceMorphTargetsUsingReference: Source and reference meshes have mismatching section counts!"));
		return;
	}

	int numSections = sourceModel->LODModels[0].Sections.Num();

	auto sourceVertices = TArray<FSoftSkinVertex>();
	auto referenceVertices = TArray<FSoftSkinVertex>();
	sourceModel->LODModels[0].GetVertices(sourceVertices);
	referenceModel->LODModels[0].GetVertices(referenceVertices);

	auto& sourceIndexBuffer = sourceModel->LODModels[0].IndexBuffer;
	auto& referenceIndexBuffer = referenceModel->LODModels[0].IndexBuffer;

	// Construct a vertex index mapping from the reference to the source
	TMap<uint32, uint32> targetToSourceVertexMap;
	// This (non-unique) inverse map is used to quickly gather all vertices affected by a morph target
	TMultiMap<uint32, uint32> sourceToTargetVertexMap;
	// For each section in the source / reference mesh
	for (int s = 0; s < numSections; ++s)
	{
		auto& sourceSection = sourceModel->LODModels[0].Sections[s];
		auto& referenceSection = referenceModel->LODModels[0].Sections[s];

		// For each vertex in the reference mesh
		for (uint32 rvi = 0; rvi < (uint32)referenceSection.NumVertices; ++rvi)
		{
			// Find the nearest matching vertices in the source mesh
			// This may be more than one vertex if distances are equal (usually overlapping vertices)
			float minDistance = 0.01f; // 0.1 mm as required precision
			TArray<uint32> sviMatches;
			bool foundMatch = false;

			for (uint32 svi = 0; svi < (uint32)sourceSection.NumVertices; ++svi)
			{
				float distance = FVector3f::Distance(sourceSection.SoftVertices[svi].Position, referenceSection.SoftVertices[rvi].Position);
				distance += FVector3f::Distance(sourceSection.SoftVertices[svi].TangentZ, referenceSection.SoftVertices[rvi].TangentZ);
				if (distance == minDistance)
				{
					sviMatches.Add(svi);
				}
				else if (distance < minDistance)
				{
					sviMatches.Empty();
					sviMatches.Add(svi);
					foundMatch = true;
					minDistance = distance;
				}
			}

			if (!foundMatch)
				continue;

			// If one or more vertices were found within the minimum distance, assign them to the mappings
			targetToSourceVertexMap.Add(rvi + sourceSection.BaseVertexIndex, sviMatches[0] + sourceSection.BaseVertexIndex);
			for (uint32 svi : sviMatches)
			{
				sourceToTargetVertexMap.AddUnique(svi + sourceSection.BaseVertexIndex, rvi + sourceSection.BaseVertexIndex);
			}
		}
	}


	// For each morph target in the source mesh
	auto& sourceMorphTargets = OriginalSourceMesh->GetMorphTargets();
	TArray<UMorphTarget*> newMorphTargets;
	for (auto morphTarget : sourceMorphTargets)
	{
		// Safety checks: check if it is valid and contains at least one LOD model
		if (!morphTarget)
			continue;
		if (morphTarget->GetMorphLODModels().Num() == 0)
			continue;

		// Get a list of affected vertices of the morph target, as indices for the target mesh
		TSet<uint32> affectedTargetVertices;
		auto& morphLodModel = morphTarget->GetMorphLODModels()[0];
		for (int32 i = 0; i < morphLodModel.NumVertices; ++i)
		{
			// Check if all vertices in the source morph target have a valid mapping to the reference / target mesh.
			if (!sourceToTargetVertexMap.Contains(morphLodModel.Vertices[i].SourceIdx))
			{
				UE_LOG(LogScript, Warning, TEXT("CopyFaceMorphTargetsUsingReference: Unable to find matching vertex in morph target for: %s"), *FString(sourceVertices[morphLodModel.Vertices[i].SourceIdx].Position.ToString()));
				return;
			}
			affectedTargetVertices.Add(sourceToTargetVertexMap.FindRef(morphLodModel.Vertices[i].SourceIdx));
		}

		// For each of the affected vertices in the target mesh
		TArray<FMorphTargetDelta> deltas;
		for (uint32 v : affectedTargetVertices)
		{
			// Find the corresponding vertex in the source mesh
			uint32 vSource = targetToSourceVertexMap.FindRef(v);
			FMorphTargetDelta delta;
			delta.SourceIdx = v;
			// Find the corresponding delta of the source vertex and copy it over
			for (FMorphTargetDelta& sourceDelta : morphTarget->GetMorphLODModels()[0].Vertices)
			{
				if (sourceDelta.SourceIdx != vSource)
					continue;
				delta.PositionDelta = sourceDelta.PositionDelta;
				delta.TangentZDelta = sourceDelta.TangentZDelta;
				break;
			}

			deltas.Add(delta);
		}

		// Create a new morph target for the target mesh with the same name
		UMorphTarget* newMorphTarget = NewObject<UMorphTarget>(TargetMesh, morphTarget->GetFName());
		newMorphTarget->BaseSkelMesh = TargetMesh;
		newMorphTarget->GetMorphLODModels().AddDefaulted(1);
		// Copy matched source data into the new morph target
		auto& sections = targetModel->LODModels[0].Sections;
		newMorphTarget->PopulateDeltas(deltas, 0, sections, true, false, 0.0f);

		newMorphTargets.Add(newMorphTarget);
	}

	// Add the new morph target to the target mesh and mark the target mesh as changed
	TargetMesh->Modify();
	TargetMesh->SetMorphTargets(newMorphTargets);
	TargetMesh->InitMorphTargetsAndRebuildRenderData();
}