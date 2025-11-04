#include "Shader.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
    : m_VertexPath(vertexPath), m_FragmentPath(fragmentPath), m_ProgramID(0) {}

Shader::~Shader() {
    if (m_ProgramID) {
        glDeleteProgram(m_ProgramID);
    }
}

std::string Shader::LoadShaderSource(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Failed to open shader file: " << filepath << std::endl;
        return "";
    }

    std::stringstream stream;
    stream << file.rdbuf();
    return stream.str();
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source) {
    unsigned int id = glCreateShader(type);
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

    if (vertexSource.empty() || fragmentSource.empty()) {
        return false;
    }

    unsigned int vertexShader = CompileShader(GL_VERTEX_SHADER, vertexSource);
    unsigned int fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentSource);

    if (!vertexShader || !fragmentShader) {
        return false;
    }

    m_ProgramID = glCreateProgram();
    glAttachShader(m_ProgramID, vertexShader);
    glAttachShader(m_ProgramID, fragmentShader);
    glLinkProgram(m_ProgramID);

    int success;
    glGetProgramiv(m_ProgramID, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(m_ProgramID, 512, nullptr, infoLog);
        std::cerr << "Shader program linking failed:\n" << infoLog << std::endl;
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
