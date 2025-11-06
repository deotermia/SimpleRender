#pragma once
#include <string>
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

private:
    std::string LoadShaderSource(const std::string& filepath);
    uint32 CompileShader(uint32 type, const std::string& source);
    
    uint32 m_ProgramID;
    std::string m_VertexPath;
    std::string m_FragmentPath;
};

} // namespace Rendering
} // namespace RenderCore
