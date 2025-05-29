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
	 std::string m_TextureFilePath;
	const std::string m_ModelFilepath;
	std::vector<Mesh>m_Meshes;
	Material LoadMaterial(aiMaterial* M) const;
	Mesh processMesh(const aiMesh* mesh, const aiScene* scene);
	void processNode(const aiNode* node,const aiScene* scene);
};