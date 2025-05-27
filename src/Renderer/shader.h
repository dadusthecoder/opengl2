#pragma once


#include <cstdlib>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

class camera;

struct Material {
	glm::vec3 specular;
	glm::vec3 ambient;
	glm::vec3 diffuse;
	float shininess;
};
struct shadersource
{
	std::string vertextsource;
	std::string fragmentsource;
};

class shader 

{
public:
	shader(const std::string& filepath);
   ~shader();
   void Bind()const;
   void Bind_UseCamera(camera& Camera) ;
   void Unbind()const ;
   GLuint GetID() const;
   const std::string& GetPath() const;
   void Reload();
   unsigned int setuniform1i(const std::string& name,int value) const;
   unsigned int setuniform1f(const std::string& name,float value ) const;
   unsigned int setuniform4f(const std::string& name,float v0, float v1, float v2, float v3) const;
   unsigned int setuniform4matf(const std::string& name,const glm::mat4& matrix) const;
   unsigned int setuniformvec3(const std::string& name, const glm::vec3& vec) const;
   void setmaterial(const Material& material) const;

private:
   unsigned int m_RenderID;
   std::string m_filepath;
   shadersource preseshader(const std::string& filepath);
   unsigned int createshader(std::string& vertexshader, std::string& fragmentshader);
   int          compileshader(unsigned int typ, const std::string& source);
   int          getuniformlocation( const std::string&) const;
};