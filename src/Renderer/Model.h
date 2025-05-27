#pragma once
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include"renderer.h"
#include"Mesh.h"
class Model {
public:
	 Model(const std::string& filepath);
	 void cleanUp();
	 void Render(const shader& Shader);
	 
private:
	std::vector<Mesh>meshes;
	Material LoadMaterial(aiMaterial* M) const;
	Mesh processMesh(const aiMesh* mesh, const aiScene* scene);
	void processNode(const aiNode* node,const aiScene* scene);
};