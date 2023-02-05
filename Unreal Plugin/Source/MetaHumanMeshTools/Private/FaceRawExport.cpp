// Fill out your copyright notice in the Description page of Project Settings.


#include "FaceRawExport.h"

#include <Rendering/SkeletalMeshModel.h>
#include <Engine/SkeletalMeshEditorData.h>
#include <Misc/FileHelper.h>
#include <Misc/Base64.h>
#include <DesktopPlatformModule.h>
#include <EditorDirectories.h>


void UFaceRawExport::FaceRawExport(USkeletalMesh* mesh, FString path)
{
	FSkeletalMeshImportData MeshImportData;
	auto& MeshBulkData = mesh->MeshEditorDataObject->GetLODImportedData(0);
	MeshBulkData.LoadRawMesh(MeshImportData);

	FString output;

	output += "{\n";

	// Data per vertex
	output += "\t\"num_vertices\": " + FString::Printf(TEXT("%i"), MeshImportData.Points.Num()) + ",\n";
	// Store vertex positions
	output += "\t\"vertices\": \"" + getBase64EncodedData(MeshImportData.Points) + "\",\n";

	// Data per face corner / wedge / loop
	output += "\t\"num_faces\": " + FString::Printf(TEXT("%i"), MeshImportData.Faces.Num()) + ",\n";
	// Store vertex indices, normals, uvs and colors
	TArray<uint32> faceIndices;
	TArray<FVector3f> normals;
	TArray<FVector2f> uvs;
	TArray<FColor> colors;
	faceIndices.Reserve(MeshImportData.Faces.Num() * 3);
	normals.Reserve(MeshImportData.Faces.Num() * 3);
	uvs.Reserve(MeshImportData.Faces.Num() * 3);
	colors.Reserve(MeshImportData.Faces.Num() * 3);
	for (int32 f = 0; f < MeshImportData.Faces.Num(); ++f)
	{
		for (int i = 0; i < 3; ++i)
		{
			faceIndices.Add(MeshImportData.Wedges[MeshImportData.Faces[f].WedgeIndex[i]].VertexIndex);
			normals.Add(MeshImportData.Faces[f].TangentZ[i]);
			uvs.Add(MeshImportData.Wedges[MeshImportData.Faces[f].WedgeIndex[i]].UVs[0]);
			colors.Add(MeshImportData.Wedges[MeshImportData.Faces[f].WedgeIndex[i]].Color);
		}
	}
	output += "\t\"face_indices\": \"" + getBase64EncodedData(faceIndices) + "\",\n";
	output += "\t\"normals\": \"" + getBase64EncodedData(normals) + "\",\n";
	output += "\t\"uvs\": \"" + getBase64EncodedData(uvs) + "\",\n";
	output += "\t\"colors\": \"" + getBase64EncodedDataColor(colors) + "\",\n";

	// Store material indices per face
	TArray<uint32> materials;
	materials.Reserve(MeshImportData.Faces.Num());
	for (int32 f = 0; f < MeshImportData.Faces.Num(); ++f)
		materials.Add(MeshImportData.Faces[f].MatIndex);
	output += "\t\"materials\": \"" + getBase64EncodedData(materials) + "\",\n";
	// Store material names per material index
	output += "\t\"material_names\": [ ";
	for (int i = 0; i < MeshImportData.Materials.Num(); ++i)
	{
		output += "\"" + MeshImportData.Materials[i].MaterialImportName + "\"";
		if (i + 1 < MeshImportData.Materials.Num())
			output += ", ";
	}
	output += "],\n";

	// Store bone influences as weighted vertex + bone index pairs
	output += "\t\"num_bone_influences\": " + FString::Printf(TEXT("%i"), MeshImportData.Influences.Num()) + ",\n";
	output += "\t\"bone_influences\": \"" + getBase64EncodedData(MeshImportData.Influences) + "\",\n";
	// Store bone names per bone index
	output += "\t\"bone_names\": [ ";
	for (int i = 0; i < MeshImportData.RefBonesBinary.Num(); ++i)
	{
		output += "\"" + MeshImportData.RefBonesBinary[i].Name + "\"";
		if (i + 1 < MeshImportData.RefBonesBinary.Num())
			output += ", ";
	}
	output += "]\n";

	output += "}\n";

	FFileHelper::SaveStringToFile(FStringView(output), *path, FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM);
}

FString UFaceRawExport::SaveFileDialog(const FString & meshFileName)
{
	TArray<FString> fileNames;
	const void* ParentWindowWindowHandle = FSlateApplication::Get().FindBestParentWindowHandleForDialogs(nullptr);
	// Grab default path for FBX files
	FString LastUsedPath = FEditorDirectories::Get().GetLastDirectory(ELastDirectory::FBX);
	if (FDesktopPlatformModule::Get()->SaveFileDialog(ParentWindowWindowHandle, "Save MetaHuman Raw Face Mesh: " + meshFileName, LastUsedPath, FPaths::GetBaseFilename(meshFileName), "Raw Face Mesh|*.json", EFileDialogFlags::None, fileNames))
	{
		if (fileNames.Num() == 1)
		{
			// Save path as default for next time
			FEditorDirectories::Get().SetLastDirectory(ELastDirectory::FBX, FPaths::GetPath(fileNames[0]));
			return fileNames[0];
		}
	}
	return "";
}


template <class T>
FString UFaceRawExport::getBase64EncodedData(const TArray<T>& data)
{
	TArray<uint8> rawData;
	int32 rawDataSize = data.Num() * sizeof(T);
	rawData.SetNum(rawDataSize);
	memcpy(rawData.GetData(), data.GetData(), rawDataSize);

	return FBase64::Encode(rawData);
}

FString UFaceRawExport::getBase64EncodedDataColor(const TArray<FColor>& data)
{
	TArray<uint8> rawData;
	for (int i = 0; i < data.Num(); ++i)
	{
		rawData.Add(data[i].R);
		rawData.Add(data[i].G);
		rawData.Add(data[i].B);
		rawData.Add(data[i].A);
	}

	return FBase64::Encode(rawData);
}
