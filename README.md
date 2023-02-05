# MetaHuman Mesh Tools

![](/images/MetaHumanMeshToolsIcon512.jpg)

## Introduction

The following describes a workflow for exporting, editing and reimporting MetaHuman meshes using Unreal Engine.

All of these notes are from personal experience and the processes that they rely on subject to change.

This repository also contains an Unreal plugin, which can be used to export and import MetaHuman meshes, and a Blender add-on, for importing a correct version of the face mesh into Blender. The use of these is explained below.

This guide assumes familiarity in working with Unreal, Blender and skeletal meshes.

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

This guide describes how a MetaHuman can be exported from Unreal, imported into Blender, modified, re-exported and re-imported into Unreal.

Most of this process can be done using FBX, but supporting the morph targets of the face mesh through Blender makes the process a bit more cumbersome. Instead of exporting and importing the morph targets as part of the FBX file, this guide takes the approach of leaving them out completely. Instead, they are copied over from the original MetaHuman face mesh in Unreal after re-importing the FBX file. To make this work, this guide assumes the topology of the face mesh is not changed. This allows the vertex order to remain unchanged between the original face mesh asset and the changed version, which makes copying over the morph targets relatively easy.

## Exporting from Unreal

For both exporting from Unreal and reimporting back into Unreal, this guide only considers the base Level of Detail. Methods to recreate LOD levels for the modified mesh are left as an exercise to the reader.

MetaHumans consist of separate meshes for the face, the body and clothing.
- The face mesh can be found under 'MetaHumans / \<YourMetaHuman\> / Face'.
- The body mesh can be found under '\[Male or Female\] / \[Height\] / \[Weight\] / Body'.

You will need to export these as FBX files. When exporting, make sure to uncheck LOD levels and Morph Targets.

For the face mesh, you will need an exact copy of the original FBX data used to import the MetaHuman. This is provided by the Unreal Plugin in this repository. When installed, right-click on the face mesh asset, and select 'Scripted Asset Actions / MetaHuman Mesh Tools / Face Raw Export'. This will result in a json file which can be imported to Blender using the provided Blender add-on.