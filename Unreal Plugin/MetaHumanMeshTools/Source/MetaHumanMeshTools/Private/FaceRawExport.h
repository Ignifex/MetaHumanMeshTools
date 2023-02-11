// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintEditorLibrary.h"
#include "IDesktopPlatform.h"
#include "FaceRawExport.generated.h"

/**
 * This class contains some blueprint callable functions to export a the raw mesh data of MetaHuman face as json.
 * The raw mesh data is the mesh as it was in the imported FBX, before it is optimized by Unreal.
 * This version of the mesh data is useful if you want to modify and reimport the mesh with identical results.
 * Morph targets are not included in the raw mesh, since support for modifying and exporting normal deltas is variable.
 */
UCLASS()
class UFaceRawExport : public UBlueprintEditorLibrary
{
	GENERATED_BODY()

	/**
	 * Exports the raw mesh data of the given SkeletalMesh to a json file at the given path.
	 */
	UFUNCTION(BlueprintCallable, Category = "MetaHuman Mesh Tools")
	static void FaceRawExport(USkeletalMesh* mesh, FString path);

	/**
	 * A convenient save file dialog, specifically for the json file of the above raw mesh data.
	 * It uses the given mesh filename as an initial file name suggestion.
	 * The last FBX import path is used as the default path and, after saving,
	 * the chosen path is assigned as the new default FBX import path.
	 */
	UFUNCTION(BlueprintCallable, Category = "MetaHuman Mesh Tools")
	static FString SaveFileDialog(const FString& meshFileName);

	/**
	 * This utility function takes the given data array, copies its bytes into a raw buffer and returns it in base64 format.
	 */
	template <class T>
	static FString getBase64EncodedData(const TArray<T>& data);

	/**
	 * This utility function takes the given color array, copies its bytes into a raw buffer and returns it in base64 format.
	 * This function is similar to the above, but it stores the colors in RGBA order, instead of the internal BGRA order of FColor.
	 */
	static FString getBase64EncodedDataColor(const TArray<FColor>& data);
};
