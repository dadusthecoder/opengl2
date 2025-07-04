
#include"renderer.h"



VertexBuffer::VertexBuffer(unsigned int size,const void* data)
{
	glGenBuffers(1, &m_RenderID);
	glBindBuffer(GL_ARRAY_BUFFER, m_RenderID);
	glBufferData(GL_ARRAY_BUFFER,size,data, GL_STATIC_DRAW);

}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1,&m_RenderID);
}

void VertexBuffer::Bind() const&
{
	glBindBuffer(GL_ARRAY_BUFFER, m_RenderID);
}

void VertexBuffer::Unbind() const&
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
