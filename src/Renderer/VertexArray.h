#pragma once
#include"BufferLayout.h"
class VertexArray
{
private:
     unsigned int m_RenderID;
public:
	VertexArray();
	~VertexArray();
	const void AddLayout(const BufferLayout& layout,const VertexBuffer& vb)const;
	const void Bind()const;
	const void Unbind()const;
};