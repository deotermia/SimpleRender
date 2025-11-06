#pragma once
#include <string>
#include <glm/glm.hpp>
#include "common/types.hpp"

namespace RenderCore {
namespace Rendering {

class Shader {
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();
    
    bool Compile();
    void Use() const;
    uint32 GetID() const { return m_ProgramID; }

    void SetUniformMat4(const std::string& name, const glm::mat4& matrix);
    void SetUniform1i(const std::string& name, int value);

private:
    std::string LoadShaderSource(const std::string& filepath);
    uint32 CompileShader(uint32 type, const std::string& source);
    int GetUniformLocation(const std::string& name);
    
    uint32 m_ProgramID;
    std::string m_VertexPath;
    std::string m_FragmentPath;
};

}
}
