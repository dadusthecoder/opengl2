#include "renderer.h"
#include "camera.h"

renderer::renderer() {
	const int gridSize = 200;
	const float scale = 1.0f;

	std::vector<float> vertices;
	std::vector<unsigned int> indices;

	// Generate vertices (X, Y, Z)
	for (int z = 0; z < gridSize; ++z) {
		for (int x = 0; x < gridSize; ++x) {
			float xpos = (x - gridSize / 2) * scale;
			float zpos = (z - gridSize / 2) * scale;
			vertices.push_back(xpos);  // X
			vertices.push_back(0.0f);  // Y
			vertices.push_back(zpos);  // Z
		}
	}

	// Generate indices
	for (int z = 0; z < gridSize - 1; ++z) {
		for (int x = 0; x < gridSize - 1; ++x) {
			int topLeft = z * gridSize + x;
			int topRight = topLeft + 1;
			int bottomLeft = (z + 1) * gridSize + x;
			int bottomRight = bottomLeft + 1;

			indices.push_back(topLeft);
			indices.push_back(bottomLeft);
			indices.push_back(topRight);

			indices.push_back(topRight);
			indices.push_back(bottomLeft);
			indices.push_back(bottomRight);
		}
	}

	// VAO/VBO/IBO Setup
	m_va = std::make_unique<VertexArray>();
	m_vb = std::make_unique<VertexBuffer>(vertices.size() * sizeof(float), vertices.data());
	BufferLayout layout;
	layout.push<float>(3); // X, Y, Z
	m_va->AddLayout(layout, *m_vb);
	m_ib = std::make_unique<IndexBuffer>(indices.data(), indices.size());
	m_FabricShader = std::make_unique<shader>("res/shaders/Fabric.shader");
	m_va->Unbind();
}

void GLclearerror()
{
	while (glGetError());
}

bool GLlog(const char* function, const char* file, const int line)
{
	while (GLenum err = glGetError()) {
		LOG(LogLevel::_ERROR, ("!OPENGL ERROR!" + std::to_string(err) + "):" + function + ":" + file + std::to_string(line)));
		return false;
	}
	return true;
}

void renderer::Draw(VertexArray& va, IndexBuffer& ib, shader& shader) const
{
	va.Bind();
	ib.Bind();
	shader.Bind();
	GlCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void renderer::Clear(glm::vec3 backc) const
{
	GlCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
	GlCall(glClearColor(backc.x, backc.y, backc.z, 1.0f));
}

float renderer::logfps(GLFWwindow* window)
{
	curnttime = glfwGetTime();
	deltatime = curnttime - prvtime;
	count++;
	if (deltatime >= 1)
	{
		fps = (1 / deltatime) * count;
		//LOG(LogLevel::_IMP, " FPS: " + std::to_string(fps));
		prvtime = curnttime;
		count = 0;
	}
	return fps;
}

void renderer::logGlVersion()
{
	const char* version = (const char*)glGetString(GL_VERSION);
	if (version) {
		LOG(LogLevel::_INFO, " OpenGL Version: " + std::string(version));
	}
	else {
		LOG(LogLevel::_ERROR, " Failed to get OpenGL version.");
	}
}

void renderer::Rendermode(const RenderMode& Mode)
{
	switch (Mode) {
	case RenderMode::FILL:
		GlCall(glPolygonMode(GL_FRONT_AND_BACK, GL_FILL));
		break;
	case RenderMode::WIREFRAME:
		GlCall(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));
		break;
	case RenderMode::POINT:
		GlCall(glPolygonMode(GL_FRONT_AND_BACK, GL_POINT));
		GlCall(glPointSize(1.0f));
		break;
	}
}

void renderer::SpaceTime_fabric(camera& Camera)
{
	m_va->Bind();
	m_ib->Bind();
	m_FabricShader->Bind_UseCamera(Camera);
	m_FabricShader->setuniform1f("u_Time", glfwGetTime());
	GlCall(glDrawElements(GL_LINES, m_ib->GetCount(), GL_UNSIGNED_INT, nullptr));
	m_FabricShader->Unbind();
}
