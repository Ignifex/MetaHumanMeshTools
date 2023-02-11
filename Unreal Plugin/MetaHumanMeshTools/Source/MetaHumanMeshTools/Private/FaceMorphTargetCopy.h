// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintEditorLibrary.h"
#include "FaceMorphTargetCopy.generated.h"

/**
 * This class contains some blueprint callable utility functions to copy Morph Target data from one MetaHuman face mesh to another.
 * The morph targets are not included as part of the raw face mesh export to avoid issues with normal deltas.
 * Instead, the following functions can be used to copy morph targets based on topology or vertex position matching.
 */
UCLASS()
class UFaceMorphTargetCopy : public UBlueprintEditorLibrary
{
	GENERATED_BODY()

	/**
	 * Copies morph targets from the given source mesh to the target mesh, matching vertices by topology.
	 * Matching by topology means it assumes the vertex order remains unchanged.
	 * This variant of morph target copying is the safest, but requires that the order of vertices of both meshes matches perfectly.
	 * If a mismatch between the two meshes is found, this function will display a warning and do nothing.
	 * Copying is only done for LOD level 0.
	 */
	UFUNCTION(BlueprintCallable, Category = "MetaHuman Mesh Tools")
	static void CopyFaceMorphTargets(USkeletalMesh* sourceMesh, USkeletalMesh* targetMesh);

	/**
	 * Copies morph target from the given source mesh to the target mesh, matching vertices using a reference mesh.
	 * The reference mesh should have the same topology as the target and should have the same vertex positions as the source mesh.
	 * A mapping from the reference to the source mesh is created based on nearest vertex positions, which is then used to copy
	 * morph targets from the source to the same matching vertices in the target mesh.
	 * This version of morph target copying is useful if the target mesh has changes in topology compared to the source.
	 * If a mismatch between the meshes is found, this function will display a warning and do nothing.
	 * Copying is only done for LOD level 0.
	 */
	UFUNCTION(BlueprintCallable, Category = "MetaHuman Mesh Tools")
	static void CopyFaceMorphTargetsUsingReference(USkeletalMesh* originalSourceMesh, USkeletalMesh* vertexPositionReferenceMesh, USkeletalMesh* targetMesh);
};
