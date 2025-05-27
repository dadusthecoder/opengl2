#include "renderer.h"
#include "shader.h"
#include "camera.h"


shader::shader(const std::string& filepath)
    : m_filepath(filepath), m_RenderID(0)
{
    shadersource source = preseshader(filepath);
    m_RenderID = createshader(source.vertextsource, source.fragmentsource);
    LOG(LogLevel::_IMP, "Shader loaded from: " + filepath + " | ID: " + std::to_string(m_RenderID));
}
shader::~shader()
{
    glDeleteProgram(m_RenderID);
    LOG(LogLevel::_IMP, "Shader deleted | ID: " + std::to_string(m_RenderID));
}

void shader::Bind() const
{
    glUseProgram(m_RenderID);
}

void shader::Bind_UseCamera(camera& Camera) 
{
    glUseProgram(m_RenderID);
    setuniform4matf("u_matv",Camera.GetViewMatrix());
    setuniform4matf("u_matp", Camera.GetProjectionMatrix());
    setuniformvec3("u_viewp", Camera.GetCameraPos());
}

void shader::Unbind() const
{
    glUseProgram(0);
}

shadersource shader::preseshader(const std::string& filepath)
{
    m_filepath = filepath;
    std::ifstream stream(filepath);
    std::string line;
    std::stringstream ss[2];

    enum class shadertype { NONE = -1, VERTEX = 0, FRAGMENT = 1 };
    shadertype type = shadertype::NONE;

    while (getline(stream, line)) {
        if (line.find("#shader") != std::string::npos) {
            if (line.find("Vertex") != std::string::npos)
                type = shadertype::VERTEX;
            else
                type = shadertype::FRAGMENT;
        }
        else {
            ss[(int)type] << line << "\n";
        }
    }
    return { ss[0].str(), ss[1].str() };
}

int shader::compileshader(unsigned int typ, const std::string& source)
{
    unsigned int id = glCreateShader(typ);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int len;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
        char* msg = (char*)malloc(len * sizeof(char));
        glGetShaderInfoLog(id, len, &len, msg);
        LOG(LogLevel::_ERROR, "Shader compilation error: " + std::string(msg));
        free(msg);
    }
    else 
    {
        LOG(LogLevel::DEBUG, std::string((typ == GL_VERTEX_SHADER) ? "Vertex" : "Fragment") + " shader compiled successfully.");
    }

    return id;
}

unsigned int shader::createshader(std::string& vertexshader, std::string& fragmentshader)
{
    unsigned int prg = glCreateProgram();
    unsigned int vs = compileshader(GL_VERTEX_SHADER, vertexshader);
    unsigned int fs = compileshader(GL_FRAGMENT_SHADER, fragmentshader);
    glAttachShader(prg, vs);
    glAttachShader(prg, fs);
    glLinkProgram(prg);
    glValidateProgram(prg);
    glDeleteShader(vs);
    glDeleteShader(fs);
    LOG(LogLevel::_IMP, "Shader program linked | Program ID: " + std::to_string(prg));
    return prg;
}

int shader::getuniformlocation(const std::string& name) const
{
    return glGetUniformLocation(m_RenderID, name.c_str());
}

unsigned int shader::setuniform1i(const std::string& name, int value) const
{
    int loc = getuniformlocation(name);
    glUniform1i(loc, value);
    return loc;
}

unsigned int shader::setuniform1f(const std::string& name, float value) const
{
    int loc = getuniformlocation(name);
    glUniform1f(loc, value);
    return loc;
}

unsigned int shader::setuniform4f(const std::string& name, float v0, float v1, float v2, float v3) const
{
    int loc = getuniformlocation(name);
    glUniform4f(loc, v0, v1, v2, v3);
    return loc;
}

unsigned int shader::setuniform4matf(const std::string& name, const glm::mat4& matrix) const
{
    int loc = getuniformlocation(name);
    glUniformMatrix4fv(loc, 1, GL_FALSE, &matrix[0][0]);
    return loc;
}

unsigned int shader::setuniformvec3(const std::string& name, const glm::vec3& vec) const
{
    int loc = getuniformlocation(name);
    glUniform3f(loc, vec.x, vec.y, vec.z);
    return loc;
}

void shader::setmaterial(const Material& material) const
{
    this->setuniformvec3("material.specular" , material.specular);
    this->setuniformvec3("material.ambient"  , material.ambient);
    this->setuniformvec3("material.diffuse"  , material.diffuse);
    this->setuniform1f  ("material.shininess", material.shininess);
    
}

// === New Methods for Debugging ===s

GLuint shader::GetID() const {
    return m_RenderID;
}

const std::string& shader::GetPath() const {
    return m_filepath;
}

void shader::Reload() {

    glDeleteProgram(m_RenderID);
    LOG(LogLevel::_IMP, "Reloading shader from: " + m_filepath);
    shadersource source = preseshader(m_filepath);
    m_RenderID = createshader(source.vertextsource, source.fragmentsource);
}
