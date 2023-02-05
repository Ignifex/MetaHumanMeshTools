import os
import json
import struct
import base64
import bpy
import mathutils
from bpy.props import StringProperty


bl_info = {
	"name": "Import Unreal MetaHuman Mesh (.json)",
	"author": "Simon Zaaijer",
	"version": (1, 0, 0),
	"blender": (2, 80, 0),
	"location": "File > Import > Unreal MetaHuman Mesh",
	"description": "Import Unreal MetaHuman Mesh in raw format (.json)",
	"category": "Import-Export",
}


class UnrealMetaHumanMesh(object):
	@staticmethod
	def loadFile(filepath):
		# Load the entire file content and parse the json into file_data
		file = open(filepath, "r")
		modelname = bpy.path.display_name(filepath)
		file_data = json.loads(file.read())
		file.close()
		
		# Create a new mesh with the name of the file
		newmesh = bpy.data.meshes.new(name = modelname)
		
		# Unpack vertex and face data
		num_vertices = file_data["num_vertices"]
		num_faces = file_data["num_faces"]
		
		vertices = []
		faces = []
		
		# The raw mesh data is packed in binary and stored as base64
		# For vertex positions and normals, the y coordinate is negated compared to Unreal
		# For the UV coordinates, the V coordinate is flipped
		
		# Unpack positions and faces
		vertices_data = base64.b64decode(file_data["vertices"])
		for i in range(num_vertices):
			x = struct.unpack_from("<f", vertices_data, i * 12 + 0)[0]
			y = -struct.unpack_from("<f", vertices_data, i * 12 + 4)[0]
			z = struct.unpack_from("<f", vertices_data, i * 12 + 8)[0]
			vertices.append((x, y, z))
		faces_data = base64.b64decode(file_data["face_indices"])
		for i in range(num_faces):
			v1 = struct.unpack_from("<i", faces_data, i * 12 + 0)[0]
			v2 = struct.unpack_from("<i", faces_data, i * 12 + 4)[0]
			v3 = struct.unpack_from("<i", faces_data, i * 12 + 8)[0]
			faces.append([v1, v2, v3])
		
		# MetaHuman meshes do not have any hard edges, so set all faces to smooth
		newmesh.from_pydata(vertices, [], faces)
		for p in newmesh.polygons:
			p.use_smooth = True
		
		# Unpack uvs
		uvs_data = base64.b64decode(file_data["uvs"])
		newmesh.uv_layers.new(name = "UVMap")
		for fi in range(num_faces):
			p = newmesh.polygons[fi]
			lii = 0
			for li in p.loop_indices:
				u = struct.unpack_from("<f", uvs_data, ((fi * 3 + lii) * 2 + 0) * 4)[0]
				v = 1.0 - struct.unpack_from("<f", uvs_data, ((fi * 3 + lii) * 2 + 1) * 4)[0]
				newmesh.uv_layers[0].data[li].uv = mathutils.Vector((u, v))
				lii += 1
		
		# Unpack normals
		# MetaHuman faces use custom normals across the entire mesh
		normals_data = base64.b64decode(file_data["normals"])
		normals = []
		for i in range(num_faces * 3):
			normals.append(struct.unpack_from("<f", normals_data, (i * 3 + 0) * 4)[0])
			normals.append(-struct.unpack_from("<f", normals_data, (i * 3 + 1) * 4)[0])
			normals.append(struct.unpack_from("<f", normals_data, (i * 3 + 2) * 4)[0])
		newmesh.normals_split_custom_set(tuple(zip(*(iter(normals),) * 3)))
		newmesh.use_auto_smooth = True
		
		# MetaHuman uses vertex colors to guide tangent computation
		colors_data = base64.b64decode(file_data["colors"])
		color_attribute = newmesh.color_attributes.new('Col', 'BYTE_COLOR', 'CORNER')
		for i in range(num_faces * 3):
			for c in range(4):
				color_attribute.data[i].color[c] = struct.unpack_from("<B", colors_data, (i * 4 + c))[0] / 255.0
		
		# Create materials
		# Use the original material names to help with importing back into Unreal
		# If a material with that name already exists, just assign it instead of creating a new one
		for material_name in file_data["material_names"]:
			if material_name not in bpy.data.materials:
				bpy.data.materials.new(name = material_name)
			newmesh.materials.append(bpy.data.materials[material_name])
		# Assign materials
		materials_data = base64.b64decode(file_data["materials"])
		materials = []
		for i in range(num_faces):
			mat_index = struct.unpack_from("<i", materials_data, i * 4)[0]
			newmesh.polygons[i].material_index = mat_index
			
		# Finalize the mesh data
		newmesh.update()
		# Create an object for the mesh and give it the same name
		newobject = bpy.data.objects.new(modelname, newmesh)
		
		# Bone influences are stored in the object, so create them after the mesh
		# Create a vertex group for each bone
		bone_names = file_data["bone_names"]
		influences_per_bone = [0] * len(bone_names)
		for bone_name in bone_names:
			newobject.vertex_groups.new(name = bone_name)
		# Assign influences for each affected vertex
		num_bone_influences = file_data["num_bone_influences"]
		bone_influences_data = base64.b64decode(file_data["bone_influences"])
		for i in range(num_bone_influences):
			w = struct.unpack_from("<f", bone_influences_data, i * 12 + 0)[0]
			vi = struct.unpack_from("<i", bone_influences_data, i * 12 + 4)[0]
			bi = struct.unpack_from("<i", bone_influences_data, i * 12 + 8)[0]
			newobject.vertex_groups[bi].add([vi], w, 'ADD')
			influences_per_bone[bi] += 1
		# Remove unused vertex groups
		bi = 0
		for bone_name in bone_names:
			if influences_per_bone[bi] == 0:
				newobject.vertex_groups.remove(newobject.vertex_groups[bone_name])
			bi += 1
		
		# Set the scale of the mesh to match the default FBX importer behavior
		newobject.scale = mathutils.Vector((0.01, 0.01, 0.01))
		
		# Link the object to the active collection / scene
		bpy.context.collection.objects.link(newobject)



class IMPORT_OT_unreal_metahuman_mesh(bpy.types.Operator):
	bl_idname = "import_scene.unreal_metahuman_mesh"
	bl_description = 'Import Unreal MetaHuman Mesh in raw format (.json)'
	bl_label = "Import Unreal MetaHuman Mesh"
	bl_space_type = 'PROPERTIES'
	bl_region_type = 'WINDOW'
	bl_options = {'UNDO'}
	
	filepath: StringProperty(
			name="input file",
			subtype='FILE_PATH'
			)

	filename_ext = ".json"

	filter_glob: StringProperty(
			default="*.json",
			options={'HIDDEN'},
			)
	
	def execute(self, context):
		UnrealMetaHumanMesh.loadFile(self.filepath)

		return {'FINISHED'}

	def invoke(self, context, event):
		wm = context.window_manager
		wm.fileselect_add(self)
		
		return {'RUNNING_MODAL'}

def menu_func(self, context):
	self.layout.operator(IMPORT_OT_unreal_metahuman_mesh.bl_idname, text="Unreal MetaHuman Mesh (.json)")
	
def register():
	bpy.utils.register_class(IMPORT_OT_unreal_metahuman_mesh)
	bpy.types.TOPBAR_MT_file_import.append(menu_func)


def unregister():
	bpy.utils.unregister_class(IMPORT_OT_unreal_metahuman_mesh)
	bpy.types.TOPBAR_MT_file_import.remove(menu_func)


if __name__ == "__main__":
    register()
