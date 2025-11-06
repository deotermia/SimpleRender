#include "rendering/Shader.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace RenderCore {
namespace Rendering {

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
    : m_ProgramID(0), m_VertexPath(vertexPath), m_FragmentPath(fragmentPath) {}

Shader::~Shader() {
    if (m_ProgramID) glDeleteProgram(m_ProgramID);
}

std::string Shader::LoadShaderSource(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Failed to open shader: " << filepath << std::endl;
        return "";
    }
    std::stringstream stream;
    stream << file.rdbuf();
    return stream.str();
}

uint32 Shader::CompileShader(uint32 type, const std::string& source) {
    uint32 id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);
    
    int success;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(id, 512, nullptr, infoLog);
        std::cerr << "Shader compilation failed:\n" << infoLog << std::endl;
        glDeleteShader(id);
        return 0;
    }
    return id;
}

bool Shader::Compile() {
    std::string vertexSource = LoadShaderSource(m_VertexPath);
    std::string fragmentSource = LoadShaderSource(m_FragmentPath);
    
    if (vertexSource.empty() || fragmentSource.empty()) return false;
    
    uint32 vertexShader = CompileShader(GL_VERTEX_SHADER, vertexSource);
    uint32 fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentSource);
    
    if (!vertexShader || !fragmentShader) return false;
    
    m_ProgramID = glCreateProgram();
    glAttachShader(m_ProgramID, vertexShader);
    glAttachShader(m_ProgramID, fragmentShader);
    glLinkProgram(m_ProgramID);
    
    int success;
    glGetProgramiv(m_ProgramID, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(m_ProgramID, 512, nullptr, infoLog);
        std::cerr << "Shader linking failed:\n" << infoLog << std::endl;
        glDeleteProgram(m_ProgramID);
        m_ProgramID = 0;
        return false;
    }
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return true;
}

void Shader::Use() const {
    glUseProgram(m_ProgramID);
}

} // namespace Rendering
} // namespace RenderCore
