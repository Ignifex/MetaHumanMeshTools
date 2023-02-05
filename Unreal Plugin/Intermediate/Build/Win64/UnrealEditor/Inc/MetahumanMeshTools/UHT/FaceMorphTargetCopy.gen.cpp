// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MetaHumanMeshTools/Private/FaceMorphTargetCopy.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFaceMorphTargetCopy() {}
// Cross Module References
	BLUEPRINTEDITORLIBRARY_API UClass* Z_Construct_UClass_UBlueprintEditorLibrary();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMesh_NoRegister();
	METAHUMANMESHTOOLS_API UClass* Z_Construct_UClass_UFaceMorphTargetCopy();
	METAHUMANMESHTOOLS_API UClass* Z_Construct_UClass_UFaceMorphTargetCopy_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MetaHumanMeshTools();
// End Cross Module References
	DEFINE_FUNCTION(UFaceMorphTargetCopy::execCopyFaceMorphTargetsUsingReference)
	{
		P_GET_OBJECT(USkeletalMesh,Z_Param_originalSourceMesh);
		P_GET_OBJECT(USkeletalMesh,Z_Param_vertexPositionReferenceMesh);
		P_GET_OBJECT(USkeletalMesh,Z_Param_targetMesh);
		P_FINISH;
		P_NATIVE_BEGIN;
		UFaceMorphTargetCopy::CopyFaceMorphTargetsUsingReference(Z_Param_originalSourceMesh,Z_Param_vertexPositionReferenceMesh,Z_Param_targetMesh);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFaceMorphTargetCopy::execCopyFaceMorphTargets)
	{
		P_GET_OBJECT(USkeletalMesh,Z_Param_sourceMesh);
		P_GET_OBJECT(USkeletalMesh,Z_Param_targetMesh);
		P_FINISH;
		P_NATIVE_BEGIN;
		UFaceMorphTargetCopy::CopyFaceMorphTargets(Z_Param_sourceMesh,Z_Param_targetMesh);
		P_NATIVE_END;
	}
	void UFaceMorphTargetCopy::StaticRegisterNativesUFaceMorphTargetCopy()
	{
		UClass* Class = UFaceMorphTargetCopy::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CopyFaceMorphTargets", &UFaceMorphTargetCopy::execCopyFaceMorphTargets },
			{ "CopyFaceMorphTargetsUsingReference", &UFaceMorphTargetCopy::execCopyFaceMorphTargetsUsingReference },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargets_Statics
	{
		struct FaceMorphTargetCopy_eventCopyFaceMorphTargets_Parms
		{
			USkeletalMesh* sourceMesh;
			USkeletalMesh* targetMesh;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_sourceMesh;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_targetMesh;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargets_Statics::NewProp_sourceMesh = { "sourceMesh", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FaceMorphTargetCopy_eventCopyFaceMorphTargets_Parms, sourceMesh), Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargets_Statics::NewProp_targetMesh = { "targetMesh", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FaceMorphTargetCopy_eventCopyFaceMorphTargets_Parms, targetMesh), Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargets_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargets_Statics::NewProp_sourceMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargets_Statics::NewProp_targetMesh,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargets_Statics::Function_MetaDataParams[] = {
		{ "Category", "MetaHuman Mesh Tools" },
		{ "Comment", "/**\n\x09 * Copies morph targets from the given source mesh to the target mesh, matching vertices by topology.\n\x09 * Matching by topology means it assumes the vertex order remains unchanged.\n\x09 * This variant of morph target copying is the safest, but requires that the order of vertices of both meshes matches perfectly.\n\x09 * If a mismatch between the two meshes is found, this function will display a warning and do nothing.\n\x09 * Copying is only done for LOD level 0.\n\x09 */" },
		{ "ModuleRelativePath", "Private/FaceMorphTargetCopy.h" },
		{ "ToolTip", "Copies morph targets from the given source mesh to the target mesh, matching vertices by topology.\nMatching by topology means it assumes the vertex order remains unchanged.\nThis variant of morph target copying is the safest, but requires that the order of vertices of both meshes matches perfectly.\nIf a mismatch between the two meshes is found, this function will display a warning and do nothing.\nCopying is only done for LOD level 0." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargets_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFaceMorphTargetCopy, nullptr, "CopyFaceMorphTargets", nullptr, nullptr, sizeof(Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargets_Statics::FaceMorphTargetCopy_eventCopyFaceMorphTargets_Parms), Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargets_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargets_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargets_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargets_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargets()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargets_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargetsUsingReference_Statics
	{
		struct FaceMorphTargetCopy_eventCopyFaceMorphTargetsUsingReference_Parms
		{
			USkeletalMesh* originalSourceMesh;
			USkeletalMesh* vertexPositionReferenceMesh;
			USkeletalMesh* targetMesh;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_originalSourceMesh;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_vertexPositionReferenceMesh;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_targetMesh;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargetsUsingReference_Statics::NewProp_originalSourceMesh = { "originalSourceMesh", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FaceMorphTargetCopy_eventCopyFaceMorphTargetsUsingReference_Parms, originalSourceMesh), Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargetsUsingReference_Statics::NewProp_vertexPositionReferenceMesh = { "vertexPositionReferenceMesh", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FaceMorphTargetCopy_eventCopyFaceMorphTargetsUsingReference_Parms, vertexPositionReferenceMesh), Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargetsUsingReference_Statics::NewProp_targetMesh = { "targetMesh", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FaceMorphTargetCopy_eventCopyFaceMorphTargetsUsingReference_Parms, targetMesh), Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargetsUsingReference_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargetsUsingReference_Statics::NewProp_originalSourceMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargetsUsingReference_Statics::NewProp_vertexPositionReferenceMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargetsUsingReference_Statics::NewProp_targetMesh,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargetsUsingReference_Statics::Function_MetaDataParams[] = {
		{ "Category", "MetaHuman Mesh Tools" },
		{ "Comment", "/**\n\x09 * Copies morph target from the given source mesh to the target mesh, matching vertices using a reference mesh.\n\x09 * The reference mesh should have the same topology as the target and should have the same vertex positions as the source mesh.\n\x09 * A mapping from the reference to the source mesh is created based on nearest vertex positions, which is then used to copy\n\x09 * morph targets from the source to the same matching vertices in the target mesh.\n\x09 * This version of morph target copying is useful if the target mesh has changes in topology compared to the source.\n\x09 * If a mismatch between the meshes is found, this function will display a warning and do nothing.\n\x09 * Copying is only done for LOD level 0.\n\x09 */" },
		{ "ModuleRelativePath", "Private/FaceMorphTargetCopy.h" },
		{ "ToolTip", "Copies morph target from the given source mesh to the target mesh, matching vertices using a reference mesh.\nThe reference mesh should have the same topology as the target and should have the same vertex positions as the source mesh.\nA mapping from the reference to the source mesh is created based on nearest vertex positions, which is then used to copy\nmorph targets from the source to the same matching vertices in the target mesh.\nThis version of morph target copying is useful if the target mesh has changes in topology compared to the source.\nIf a mismatch between the meshes is found, this function will display a warning and do nothing.\nCopying is only done for LOD level 0." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargetsUsingReference_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFaceMorphTargetCopy, nullptr, "CopyFaceMorphTargetsUsingReference", nullptr, nullptr, sizeof(Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargetsUsingReference_Statics::FaceMorphTargetCopy_eventCopyFaceMorphTargetsUsingReference_Parms), Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargetsUsingReference_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargetsUsingReference_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargetsUsingReference_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargetsUsingReference_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargetsUsingReference()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargetsUsingReference_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UFaceMorphTargetCopy);
	UClass* Z_Construct_UClass_UFaceMorphTargetCopy_NoRegister()
	{
		return UFaceMorphTargetCopy::StaticClass();
	}
	struct Z_Construct_UClass_UFaceMorphTargetCopy_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFaceMorphTargetCopy_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintEditorLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_MetaHumanMeshTools,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UFaceMorphTargetCopy_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargets, "CopyFaceMorphTargets" }, // 1620457428
		{ &Z_Construct_UFunction_UFaceMorphTargetCopy_CopyFaceMorphTargetsUsingReference, "CopyFaceMorphTargetsUsingReference" }, // 2618895402
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFaceMorphTargetCopy_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * This class contains some blueprint callable utility functions to copy Morph Target data from one MetaHuman face mesh to another.\n * The morph targets are not included as part of the raw face mesh export to avoid issues with normal deltas.\n * Instead, the following functions can be used to copy morph targets based on topology or vertex position matching.\n */" },
		{ "IncludePath", "FaceMorphTargetCopy.h" },
		{ "ModuleRelativePath", "Private/FaceMorphTargetCopy.h" },
		{ "ToolTip", "This class contains some blueprint callable utility functions to copy Morph Target data from one MetaHuman face mesh to another.\nThe morph targets are not included as part of the raw face mesh export to avoid issues with normal deltas.\nInstead, the following functions can be used to copy morph targets based on topology or vertex position matching." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFaceMorphTargetCopy_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFaceMorphTargetCopy>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UFaceMorphTargetCopy_Statics::ClassParams = {
		&UFaceMorphTargetCopy::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UFaceMorphTargetCopy_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFaceMorphTargetCopy_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFaceMorphTargetCopy()
	{
		if (!Z_Registration_Info_UClass_UFaceMorphTargetCopy.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UFaceMorphTargetCopy.OuterSingleton, Z_Construct_UClass_UFaceMorphTargetCopy_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UFaceMorphTargetCopy.OuterSingleton;
	}
	template<> METAHUMANMESHTOOLS_API UClass* StaticClass<UFaceMorphTargetCopy>()
	{
		return UFaceMorphTargetCopy::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFaceMorphTargetCopy);
	UFaceMorphTargetCopy::~UFaceMorphTargetCopy() {}
	struct Z_CompiledInDeferFile_FID_MetahumanTools_Plugins_MetaHumanMeshTools_Source_MetaHumanMeshTools_Private_FaceMorphTargetCopy_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MetahumanTools_Plugins_MetaHumanMeshTools_Source_MetaHumanMeshTools_Private_FaceMorphTargetCopy_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UFaceMorphTargetCopy, UFaceMorphTargetCopy::StaticClass, TEXT("UFaceMorphTargetCopy"), &Z_Registration_Info_UClass_UFaceMorphTargetCopy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFaceMorphTargetCopy), 2635316689U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MetahumanTools_Plugins_MetaHumanMeshTools_Source_MetaHumanMeshTools_Private_FaceMorphTargetCopy_h_241921311(TEXT("/Script/MetaHumanMeshTools"),
		Z_CompiledInDeferFile_FID_MetahumanTools_Plugins_MetaHumanMeshTools_Source_MetaHumanMeshTools_Private_FaceMorphTargetCopy_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MetahumanTools_Plugins_MetaHumanMeshTools_Source_MetaHumanMeshTools_Private_FaceMorphTargetCopy_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
