#pragma once
#include <string>

class Shader {
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    bool Compile();
    void Use() const;
    unsigned int GetID() const { return m_ProgramID; }

private:
    std::string LoadShaderSource(const std::string& filepath);
    unsigned int CompileShader(unsigned int type, const std::string& source);

    unsigned int m_ProgramID;
    std::string m_VertexPath, m_FragmentPath;
};
