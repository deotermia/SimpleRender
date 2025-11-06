#pragma once
#include "common/types.hpp"

namespace RenderCore {
namespace Rendering {

class Renderer {
public:
    Renderer();
    ~Renderer();
    
    void SetClearColor(float r, float g, float b, float a);
    void Clear();
    void DrawTriangle();

private:
    uint32 m_VAO, m_VBO;
    float m_ClearColor[4];
};

} // namespace Rendering
} // namespace RenderCore
