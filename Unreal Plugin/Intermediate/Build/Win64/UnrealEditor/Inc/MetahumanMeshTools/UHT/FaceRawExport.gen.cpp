// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MetaHumanMeshTools/Private/FaceRawExport.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFaceRawExport() {}
// Cross Module References
	BLUEPRINTEDITORLIBRARY_API UClass* Z_Construct_UClass_UBlueprintEditorLibrary();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMesh_NoRegister();
	METAHUMANMESHTOOLS_API UClass* Z_Construct_UClass_UFaceRawExport();
	METAHUMANMESHTOOLS_API UClass* Z_Construct_UClass_UFaceRawExport_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MetaHumanMeshTools();
// End Cross Module References
	DEFINE_FUNCTION(UFaceRawExport::execSaveFileDialog)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_meshFileName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UFaceRawExport::SaveFileDialog(Z_Param_meshFileName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFaceRawExport::execFaceRawExport)
	{
		P_GET_OBJECT(USkeletalMesh,Z_Param_mesh);
		P_GET_PROPERTY(FStrProperty,Z_Param_path);
		P_FINISH;
		P_NATIVE_BEGIN;
		UFaceRawExport::FaceRawExport(Z_Param_mesh,Z_Param_path);
		P_NATIVE_END;
	}
	void UFaceRawExport::StaticRegisterNativesUFaceRawExport()
	{
		UClass* Class = UFaceRawExport::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FaceRawExport", &UFaceRawExport::execFaceRawExport },
			{ "SaveFileDialog", &UFaceRawExport::execSaveFileDialog },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UFaceRawExport_FaceRawExport_Statics
	{
		struct FaceRawExport_eventFaceRawExport_Parms
		{
			USkeletalMesh* mesh;
			FString path;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_mesh;
		static const UECodeGen_Private::FStrPropertyParams NewProp_path;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFaceRawExport_FaceRawExport_Statics::NewProp_mesh = { "mesh", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FaceRawExport_eventFaceRawExport_Parms, mesh), Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFaceRawExport_FaceRawExport_Statics::NewProp_path = { "path", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FaceRawExport_eventFaceRawExport_Parms, path), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFaceRawExport_FaceRawExport_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFaceRawExport_FaceRawExport_Statics::NewProp_mesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFaceRawExport_FaceRawExport_Statics::NewProp_path,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFaceRawExport_FaceRawExport_Statics::Function_MetaDataParams[] = {
		{ "Category", "MetaHuman Mesh Tools" },
		{ "Comment", "/**\n\x09 * Exports the raw mesh data of the given SkeletalMesh to a json file at the given path.\n\x09 */" },
		{ "ModuleRelativePath", "Private/FaceRawExport.h" },
		{ "ToolTip", "Exports the raw mesh data of the given SkeletalMesh to a json file at the given path." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFaceRawExport_FaceRawExport_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFaceRawExport, nullptr, "FaceRawExport", nullptr, nullptr, sizeof(Z_Construct_UFunction_UFaceRawExport_FaceRawExport_Statics::FaceRawExport_eventFaceRawExport_Parms), Z_Construct_UFunction_UFaceRawExport_FaceRawExport_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFaceRawExport_FaceRawExport_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFaceRawExport_FaceRawExport_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFaceRawExport_FaceRawExport_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFaceRawExport_FaceRawExport()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFaceRawExport_FaceRawExport_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFaceRawExport_SaveFileDialog_Statics
	{
		struct FaceRawExport_eventSaveFileDialog_Parms
		{
			FString meshFileName;
			FString ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_meshFileName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_meshFileName;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFaceRawExport_SaveFileDialog_Statics::NewProp_meshFileName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFaceRawExport_SaveFileDialog_Statics::NewProp_meshFileName = { "meshFileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FaceRawExport_eventSaveFileDialog_Parms, meshFileName), METADATA_PARAMS(Z_Construct_UFunction_UFaceRawExport_SaveFileDialog_Statics::NewProp_meshFileName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UFaceRawExport_SaveFileDialog_Statics::NewProp_meshFileName_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFaceRawExport_SaveFileDialog_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FaceRawExport_eventSaveFileDialog_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFaceRawExport_SaveFileDialog_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFaceRawExport_SaveFileDialog_Statics::NewProp_meshFileName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFaceRawExport_SaveFileDialog_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFaceRawExport_SaveFileDialog_Statics::Function_MetaDataParams[] = {
		{ "Category", "MetaHuman Mesh Tools" },
		{ "Comment", "/**\n\x09 * A convenient save file dialog, specifically for the json file of the above raw mesh data.\n\x09 * It uses the given mesh filename as an initial file name suggestion.\n\x09 * The last FBX import path is used as the default path and, after saving,\n\x09 * the chosen path is assigned as the new default FBX import path.\n\x09 */" },
		{ "ModuleRelativePath", "Private/FaceRawExport.h" },
		{ "ToolTip", "A convenient save file dialog, specifically for the json file of the above raw mesh data.\nIt uses the given mesh filename as an initial file name suggestion.\nThe last FBX import path is used as the default path and, after saving,\nthe chosen path is assigned as the new default FBX import path." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFaceRawExport_SaveFileDialog_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFaceRawExport, nullptr, "SaveFileDialog", nullptr, nullptr, sizeof(Z_Construct_UFunction_UFaceRawExport_SaveFileDialog_Statics::FaceRawExport_eventSaveFileDialog_Parms), Z_Construct_UFunction_UFaceRawExport_SaveFileDialog_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFaceRawExport_SaveFileDialog_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFaceRawExport_SaveFileDialog_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFaceRawExport_SaveFileDialog_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFaceRawExport_SaveFileDialog()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFaceRawExport_SaveFileDialog_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UFaceRawExport);
	UClass* Z_Construct_UClass_UFaceRawExport_NoRegister()
	{
		return UFaceRawExport::StaticClass();
	}
	struct Z_Construct_UClass_UFaceRawExport_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFaceRawExport_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintEditorLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_MetaHumanMeshTools,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UFaceRawExport_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UFaceRawExport_FaceRawExport, "FaceRawExport" }, // 1499946106
		{ &Z_Construct_UFunction_UFaceRawExport_SaveFileDialog, "SaveFileDialog" }, // 3829423875
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFaceRawExport_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * This class contains some blueprint callable functions to export a the raw mesh data of MetaHuman face as json.\n * The raw mesh data is the mesh as it was in the imported FBX, before it is optimized by Unreal.\n * This version of the mesh data is useful if you want to modify and reimport the mesh with identical results.\n * Morph targets are not included in the raw mesh, since support for modifying and exporting normal deltas is variable.\n */" },
		{ "IncludePath", "FaceRawExport.h" },
		{ "ModuleRelativePath", "Private/FaceRawExport.h" },
		{ "ToolTip", "This class contains some blueprint callable functions to export a the raw mesh data of MetaHuman face as json.\nThe raw mesh data is the mesh as it was in the imported FBX, before it is optimized by Unreal.\nThis version of the mesh data is useful if you want to modify and reimport the mesh with identical results.\nMorph targets are not included in the raw mesh, since support for modifying and exporting normal deltas is variable." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFaceRawExport_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFaceRawExport>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UFaceRawExport_Statics::ClassParams = {
		&UFaceRawExport::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFaceRawExport_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFaceRawExport_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFaceRawExport()
	{
		if (!Z_Registration_Info_UClass_UFaceRawExport.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UFaceRawExport.OuterSingleton, Z_Construct_UClass_UFaceRawExport_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UFaceRawExport.OuterSingleton;
	}
	template<> METAHUMANMESHTOOLS_API UClass* StaticClass<UFaceRawExport>()
	{
		return UFaceRawExport::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFaceRawExport);
	UFaceRawExport::~UFaceRawExport() {}
	struct Z_CompiledInDeferFile_FID_MetahumanTools_Plugins_MetaHumanMeshTools_Source_MetaHumanMeshTools_Private_FaceRawExport_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MetahumanTools_Plugins_MetaHumanMeshTools_Source_MetaHumanMeshTools_Private_FaceRawExport_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UFaceRawExport, UFaceRawExport::StaticClass, TEXT("UFaceRawExport"), &Z_Registration_Info_UClass_UFaceRawExport, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFaceRawExport), 604253168U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MetahumanTools_Plugins_MetaHumanMeshTools_Source_MetaHumanMeshTools_Private_FaceRawExport_h_1148621794(TEXT("/Script/MetaHumanMeshTools"),
		Z_CompiledInDeferFile_FID_MetahumanTools_Plugins_MetaHumanMeshTools_Source_MetaHumanMeshTools_Private_FaceRawExport_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MetahumanTools_Plugins_MetaHumanMeshTools_Source_MetaHumanMeshTools_Private_FaceRawExport_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
