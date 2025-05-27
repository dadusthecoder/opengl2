#pragma once

#include<GL/glew.h>
#include <GLFW/glfw3.h>
#define GLM_ENABLE_EXPERIMENTAL 
#include<glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> // For transformations like translate, rotate, perspective 
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/matrix_decompose.hpp>


#include<imgui.h>
#include<imgui_impl_opengl3.h>
#include<ImGuizmo.h>
#include<imgui_impl_glfw.h>

#include<iostream>
#include<memory>

#include"Logger.h"
#include"VertexBuffer.h"
#include"IndexBuffer.h"
#include"VertexArray.h"
#include"shader.h"
#include"BufferLayout.h"
#include"Texture.h"

class camera;

#define ASSERT(x) if(!(x))__debugbreak();
#define GlCall(x) \
    GLclearerror(); \
    x; \
    ASSERT(GLlog(#x,__FILE__, __LINE__))

void GLclearerror();
bool GLlog(const char* function, const char* file, const int line);
enum class RenderMode {
    FILL,
    WIREFRAME,
    POINT
};

class renderer
{
private:
    float deltatime = 0, prvtime = 0, curnttime = 0, fps = 0 ;
    unsigned int  count = 0;
    std::unique_ptr<shader>m_FabricShader;
    std::unique_ptr<VertexArray>m_va;
    std::unique_ptr<VertexBuffer>m_vb;
    std::unique_ptr<IndexBuffer>m_ib;
public:
     renderer();
     void Draw(VertexArray& va,IndexBuffer& ib,shader& shader) const ; 
     void Clear(glm::vec3) const ;
     float logfps(GLFWwindow* window);
     void logGlVersion();
     void Rendermode( const RenderMode& Mode);
     void SpaceTime_fabric( camera& Camera );
};
