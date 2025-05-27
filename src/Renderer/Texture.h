#pragma once
#include<string>
#include"stb_image.h"
#include"renderer.h"
class Texture 
{
private :
	unsigned int m_RenderID;
    int m_height, m_width, m_bpp;
	unsigned char* m_localbuffer;
public :
	Texture(const std::string& filepath );
	GLuint GetTextureID();
	void cleanUp();
	void Bind(unsigned int slot)   const ;
	void Unbind() const ;
};