# MetaHuman Mesh Tools

![](/MetaHumanMeshToolsIcon512.jpg)

## Introduction

The following describes a workflow for exporting, editing and reimporting MetaHuman meshes using Unreal Engine.

All of these notes are from personal experience and the processes that they rely on is subject to change. This guide assumes familiarity in working with Unreal, MetaHumans, Blender and skeletal meshes.

This repository also contains an Unreal plugin, which can be used to export and import MetaHuman meshes, and a Blender add-on, for importing a correct version of the face mesh into Blender. The use of these is explained below.

### Installation instructions

The Unreal plugin requires a working version of Visual Studio to be set up alongside Unreal Engine. See [this page](https://docs.unrealengine.com/5.1/en-US/setting-up-visual-studio-development-environment-for-cplusplus-projects-in-unreal-engine/) for more details.

To install the Unreal plugin for a single project, create a new folder called 'Plugins' and copy the contents of the 'Unreal Plugin' folder of this repository into it. When you next open your project, Unreal will ask you whether it should rebuild the plugin. Choose yes to continue (this may take a minute). The plugin should be enabled by default in your plugins setup.

To install the Blender add-on, follow the instructions on [this page](https://docs.blender.org/manual/en/latest/editors/preferences/addons.html) under Installing add-ons. Use the 'import_unreal_metahuman_mesh.py' file found in the 'Blender Add-on' folder of this repository.

## On modifying MetaHumans

MetaHumans in Unreal can be modified almost completely, with only a few notable restrictions:
- MetaHuman faces are animated using RigLogic, which adds a DNAAsset blob of data to the face mesh. This data is not modifiable through the editor and cannot be trivially copied over. This animation data overrides the facial bones, meaning the bone structure of the face cannot be changed. The face can be scaled, however, by setting the scale of the head (or neck) bone as the default pose for the body skeleton. This is described in more detail later.  
Unreal has released [MetaHuman DNA Calibration](https://github.com/EpicGames/MetaHuman-DNA-Calibration) tools to modify DNA files, so even this restriction it not absolute.
- The normal and tangent logic of the face relies on the vertex colors stored in the face mesh. These should be retained.
- The face mesh uses blend shapes or morph targets to add further detail to and correct for deformation during facial animation. These should be retained. These blend shapes contain both position and normal deltas. Blend shapes with normal adjustments are not supported by Blender and will be lost upon import and export. This limitation is one of the primary motivations for the tools provided here.
- The textures can be freely changed and can be assigned to a copy of the default material. It is also possible to swap the materials completely, but bear in mind that the default material contains logic to drive a set of albedo and normal maps. These contain additional details for wrinkles to match the facial animation.

Most of the animation for MetaHuman faces is driven by bones. Without straying too far from the original and its bone layout, it is entirely possible to modify the mesh in modelling software like Blender and retain good facial animation.

The body meshes only use regular skeletal deformation. This makes working with them similar to any other skeletal mesh.

## Workflow overview

This guide describes how a MetaHuman can be exported from Unreal, imported into Blender, modified, reexported and reimported into Unreal.

Most of this process can be done using FBX, but supporting the morph targets of the face mesh through Blender makes the process a bit more cumbersome. Instead of exporting and importing the morph targets as part of the FBX file, this guide takes the approach of leaving them out completely. Instead, they are copied over from the original MetaHuman face mesh in Unreal after reimporting the FBX file. To make this work, this guide assumes the topology of the face mesh is not changed. This allows the vertex order to remain exactly the same between the original face mesh asset and the changed version, which makes copying over the morph targets relatively easy and accurate.

### Exporting from Unreal

For both exporting from Unreal and reimporting back into Unreal, this guide only considers the base Level of Detail. Methods to recreate LOD levels for the modified mesh are left as an exercise to the reader.

MetaHumans consist of separate meshes for the face, the body and clothing.
- The face mesh can be found under 'MetaHumans / \<YourMetaHuman\> / Face'.
- The body mesh can be found under '\<Male or Female\> / \<Height\> / \<Weight\> / Body'.

You will need to export these as FBX files. When exporting, make sure to uncheck LOD levels and Morph Targets.

For the face mesh, you will need an exact copy of the original FBX data used to import the MetaHuman. This is provided by the Unreal Plugin in this repository. When installed, right-click on the face mesh asset and select 'Scripted Asset Actions / MetaHuman Mesh Tools / Face Raw Export'. This will result in a raw json file which can be imported to Blender using the provided Blender add-on.

### Importing into Blender

Basic importing:

- For both the face and the body, import from the FBX as normal.
- Select the 'root' armature object and unparent it (alt-P), keeping the transform. Remove the old parent object. This should leave just the armature and a single child mesh. Note that the armature for the face and body are different and must both be kept.

For the face geometry:

- Remove the imported face mesh, but keep the armature.
- Import the Unreal MetaHuman Mesh (.json) file.
- Parent the new face mesh under the armature and add an armature modifier to it, pointing to its parent.

With this setup, you are already set to export. For your first try, it is recommended to skip modifying your MetaHuman and continue with exporting from Blender.

### Exporting from Blender

To export, simply export to FBX as normal. There are a few important points to check:
- The face and body are exported separately.
- For both the face and body, you should only export a single mesh and its armature. It may help to export these as your active selection.
- The armature object should not have a parent and must be named 'root'. If you have both a face and body armature in the same scene, these cannot have the same name, so you will always need to check and adjust the name before exporting.
- The mesh should have an armature modifier, pointing to its parent, as the last modifier on the stack. Any modifiers before this will be applied automatically on export.

### Importing into Unreal

Importing into Unreal is done by creating a copy of the original MetaHuman mesh and overriding the mesh geometry with the given FBX. You will also be creating a copy of the blueprint for the entire MetaHuman.
- First, copy either the face or body mesh to your own asset. It is recommended to place these copies outside of the default MetaHumans folder, since the contents of that folder are managed by the Quixel Bridge plugin.
- Open the copy to change its settings
  - Under LOD Settings, set the 'Number of LODs' to 1 and click 'Apply Changes' below it.
  - Under Import Settings, uncheck 'Update Skeleton Reference Pose', check 'Use T0 As Ref Pose' and set the Import Rotation to all 0.
  - Save the asset.
- Click Reimport Base Mesh and select the FBX file containing your adjusted MetaHuman mesh.
  - This step should not prompt any material assignment issues. If anything should go wrong, check the exported material names against the 'Slot Names' under Material Slots. It is likely faster to recreate your mesh copy asset instead of attempting to fix the material assignments by hand.
  - The new MetaHuman mesh should have the same number of Verts as the original, but the bone influences may vary a bit.
  - The newly imported mesh does not yet have morph targets applied, but the display of these in the asset viewer is not immediately updated. Reopening the window shows they are now missing.
  
For body meshes, you are already done. For face meshes, the morph targets still need to be transferred from the original MetaHuman mesh.
- Right click on your new face mesh asset and select 'Scripted Asset Actions / MetaHuman Mesh Tools / Face Morph Target Copy'. A dialog window will open.
- Set the original MetaHuman face mesh as the Source Mesh and click OK.
- The face should now be fully ready and should animate like the original.
  - The copying of the morph targets may fail if the number of vertices in the mesh assets changed. This may happen due to minor differences in vertex position, which can cause different merges of overlapping vertices. If this should fail, a warning is printed to the Output Log.
  - A quick check whether the morph targets work is by closing the MetaHuman's eyes. The line where the eyelid is folded back when the eye is opened should dissappear when it closes.
  
Next, you will need to create your own copy of the MetaHuman blueprint to assign your meshes to it.
- Copy the blueprint from 'MetaHumans / \<YourMetaHuman\> / BP_\<YourMetaHuman\>' to your own asset. Again, it is recommended to place this copy outside of the default MetaHumans folder.
- Open the blueprint and find the Body or Face listed in the Components. Simply assign your mesh as their 'Skeletal Mesh Asset', save and compile.

Grooms, the assets for hair, bind to the face geometry. If you change the face, you will need to create a copy of the groom's Binding Asset.
- Navigate to each of your used groom components, and click the Browse button below the Binding Asset to select the asset file. Create another copy outside the MetaHumans folder.
- Open your new Binding Asset, assign the original MetaHuman face mesh as the 'Source Skeletal Mesh' and assign your own face mesh as the 'Target Skeletal Mesh'
- Assign your new Bindind Asset in your MetaHuman blueprint.