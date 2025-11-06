#include "rendering/DebugRenderer.hpp"
#include "rendering/Shader.hpp"
#include "rendering/Camera.hpp"
#include <glad/glad.h>
#include <vector>

namespace RenderCore {
namespace Rendering {

void DebugRenderer::DrawGrid(Shader* shader, Camera* camera) {
    std::vector<float> gridVertices;
    
    for (int i = -10; i <= 10; i++) {
        gridVertices.insert(gridVertices.end(), {float(i), 0.0f, -10.0f});
        gridVertices.insert(gridVertices.end(), {float(i), 0.0f, 10.0f});
        gridVertices.insert(gridVertices.end(), {-10.0f, 0.0f, float(i)});
        gridVertices.insert(gridVertices.end(), {10.0f, 0.0f, float(i)});
    }

    static unsigned int gridVAO = 0, gridVBO = 0;
    if (gridVAO == 0) {
        glGenVertexArrays(1, &gridVAO);
        glGenBuffers(1, &gridVBO);
        
        glBindVertexArray(gridVAO);
        glBindBuffer(GL_ARRAY_BUFFER, gridVBO);
        glBufferData(GL_ARRAY_BUFFER, gridVertices.size() * sizeof(float), gridVertices.data(), GL_STATIC_DRAW);
        
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    shader->Use();
    shader->SetUniformMat4("view", camera->GetViewMatrix());
    shader->SetUniformMat4("projection", camera->GetProjectionMatrix(800.0f/600.0f));
    
    glm::mat4 model = glm::mat4(1.0f);
    shader->SetUniformMat4("model", model);
    
    glBindVertexArray(gridVAO);
    glDrawArrays(GL_LINES, 0, gridVertices.size() / 3);
    glBindVertexArray(0);
}

}
}
