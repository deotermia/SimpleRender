#pragma once
#include "common/types.hpp"
#include <glm/glm.hpp>

namespace RenderCore {
namespace Rendering {

class Renderer {
public:
    Renderer();
    ~Renderer();
    
    void SetClearColor(float r, float g, float b, float a);
    void Clear();
    void DrawCube(const glm::mat4& model, class Shader* shader, class Camera* camera, class Texture* texture);

private:
    uint32 m_VAO, m_VBO, m_EBO;
    float m_ClearColor[4];
};

}
}
