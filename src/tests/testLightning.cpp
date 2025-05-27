//#include "testLightning.h"
//#include "renderer/camera.h"
//
//
//    testLightning::testLightning():m_speed(0.007f)
//	{   
//		std::vector<vertex> cubeVertices = {
//			// Front face
//			{{-0.5f, -0.5f,  0.5f}, {0.0f, 0.0f}, {0.0f,  0.0f,  1.0f}},
//			{{ 0.5f, -0.5f,  0.5f}, {1.0f, 0.0f}, {0.0f,  0.0f,  1.0f}},
//			{{ 0.5f,  0.5f,  0.5f}, {1.0f, 1.0f}, {0.0f,  0.0f,  1.0f}},
//			{{-0.5f,  0.5f,  0.5f}, {0.0f, 1.0f}, {0.0f,  0.0f,  1.0f}},
//
//			// Back face
//			{{-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f}, {0.0f,  0.0f, -1.0f}},
//			{{ 0.5f, -0.5f, -0.5f}, {1.0f, 0.0f}, {0.0f,  0.0f, -1.0f}},
//			{{ 0.5f,  0.5f, -0.5f}, {1.0f, 1.0f}, {0.0f,  0.0f, -1.0f}},
//			{{-0.5f,  0.5f, -0.5f}, {0.0f, 1.0f}, {0.0f,  0.0f, -1.0f}},
//
//			// Left face
//			{{-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f}, {-1.0f,  0.0f,  0.0f}},
//			{{-0.5f, -0.5f,  0.5f}, {1.0f, 0.0f}, {-1.0f,  0.0f,  0.0f}},
//			{{-0.5f,  0.5f,  0.5f}, {1.0f, 1.0f}, {-1.0f,  0.0f,  0.0f}},
//			{{-0.5f,  0.5f, -0.5f}, {0.0f, 1.0f}, {-1.0f,  0.0f,  0.0f}},
//
//			// Right face
//			{{ 0.5f, -0.5f, -0.5f}, {0.0f, 0.0f}, {1.0f,  0.0f,  0.0f}},
//			{{ 0.5f, -0.5f,  0.5f}, {1.0f, 0.0f}, {1.0f,  0.0f,  0.0f}},
//			{{ 0.5f,  0.5f,  0.5f}, {1.0f, 1.0f}, {1.0f,  0.0f,  0.0f}},
//			{{ 0.5f,  0.5f, -0.5f}, {0.0f, 1.0f}, {1.0f,  0.0f,  0.0f}},
//
//			// Top face
//			{{-0.5f,  0.5f, -0.5f}, {0.0f, 0.0f}, {0.0f,  1.0f,  0.0f}},
//			{{ 0.5f,  0.5f, -0.5f}, {1.0f, 0.0f}, {0.0f,  1.0f,  0.0f}},
//			{{ 0.5f,  0.5f,  0.5f}, {1.0f, 1.0f}, {0.0f,  1.0f,  0.0f}},
//			{{-0.5f,  0.5f,  0.5f}, {0.0f, 1.0f}, {0.0f,  1.0f,  0.0f}},
//
//			// Bottom face
//			{{-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f}, {0.0f, -1.0f,  0.0f}},
//			{{ 0.5f, -0.5f, -0.5f}, {1.0f, 0.0f}, {0.0f, -1.0f,  0.0f}},
//			{{ 0.5f, -0.5f,  0.5f}, {1.0f, 1.0f}, {0.0f, -1.0f,  0.0f}},
//			{{-0.5f, -0.5f,  0.5f}, {0.0f, 1.0f}, {0.0f, -1.0f,  0.0f}},
//		};
//
//		std::vector<vertex> groundVertices = {
//			   {{-5.0f,  0.0f, -5.0f}, {0.0f, 0.0f}, {0.0f,  1.0f,  0.0f}},
//	           {{ 5.0f,  0.0f, -5.0f}, {1.0f, 0.0f}, {0.0f,  1.0f,  0.0f}},
//	           {{ 5.0f,  0.0f,  5.0f}, {1.0f, 1.0f}, {0.0f,  1.0f,  0.0f}},
//	           {{-5.0f,  0.0f,  5.0f}, {0.0f, 1.0f}, {0.0f,  1.0f,  0.0f}}
//		};
//
//
//		std::vector<unsigned int>ind=
//		{
//			// Front face
//			0, 1, 2,  2, 3, 0,
//			// Back face
//			4, 5, 6,  6, 7, 4,
//			// Left face
//			8, 9, 10, 10, 11, 8,
//			// Right face
//			12, 13, 14, 14, 15, 12,
//			// Top face
//			16, 17, 18, 18, 19, 16,
//			// Bottom face
//			20, 21, 22, 22, 23, 20,
//		};
//
//		std::vector<unsigned int> inds
//		{
//			 0, 1, 2,  2, 3, 0
//		};
//
//	    viewp = glm::vec3(0.0, 0.0, 0.0);
//	    lightp = glm::vec3(-4.0, 5.0, 1.0);
//	    lightc = glm::vec3(1.0f, 1.10f, 1.0f);
//	    backc = glm::vec3(0.0, 0.0, 0.0);
//		cube = glm::translate(glm::mat4(1.0f),  lightp); 
//		cube2 = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//		floor = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -1.0f, 0.0f));
//		m_shader =  std::make_unique<shader>("res/shaders/bsc.shader");
//		m_shader->Bind();
//		m_shader->setuniform1i("u_Texture", 0);
//		
//		m_texture1 = std::make_unique<Texture>("res/images/surface.png");
//		m_texture2 = std::make_unique<Texture>("res/images/tnt.png");
//		m_camera   = std::make_unique<camera>(800.0f,800.0f,viewp);
//		m_render   = std::make_unique<renderer>();
//		m_render->logGlVersion();
//		m_Mesh = std::make_unique<Mesh>(groundVertices,inds);
//		m_Mesh2 = std::make_unique<Mesh>(cubeVertices, ind);
//	}
//
//	testLightning::~testLightning()
//	{
//      
//	}
//
//
//	void testLightning::onRender()
//	{
//		m_render->Clear(backc);
//		m_shader->setuniform4matf("u_matm", floor);
//		m_shader->setuniform1i("u_usec", 0);
//		m_texture1->Bind(0);
//		m_Mesh->render(*m_shader);
//
//		m_shader->setuniformvec3("lightp", lightp);
//		m_shader->setuniformvec3("u_color", lightc);
//		cube = glm::translate(glm::mat4(1.0f), lightp);
//		m_shader->setuniform4matf("u_matm", cube);
//		m_shader->setuniform1i("u_usec", 1);
//		m_Mesh2->render(*m_shader);
//
//		cube2 = glm::rotate(cube2, glm::radians(0.5f), glm::vec3(1.0, 1.0, 0.0));
//		m_shader->setuniform4matf("u_matm", cube2);
//		m_shader->setuniform1i("u_usec", 0);
//		m_texture2->Bind(0);
//		m_Mesh2->render(*m_shader);
//	}
//
//	void testLightning::onUpdate(GLFWwindow* window)
//	{
//		//m_camera->nputs(window,m_speed,40.0f);
//		m_render->logfps(window);
//	}
//
//	void testLightning::onImguiRnder()
//
//	{
//		ImGui_ImplOpenGL3_NewFrame();
//		ImGui_ImplGlfw_NewFrame();
//		ImGui::NewFrame();
//		ImGui::Begin("Hello, world!");
//		ImGui::SliderFloat("speed",&m_speed,0.0f,0.5f);
//		ImGui::SliderFloat3("Light Position", &lightp[0],-10.0f,10.0f);
//		ImGui::ColorEdit3("Light Color", &lightc[0]);
//		ImGui::ColorEdit3("BackGround Color", &backc[0]);
//		ImGui::End();
//		ImGui::Render();
//		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
//	}
//
