#include "scene/GameObject.hpp"
#include "rendering/Renderer.hpp"
#include "rendering/Shader.hpp"
#include "rendering/Camera.hpp"
#include "rendering/Texture.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace RenderCore {
namespace Scene {

GameObject::GameObject(const std::string& name)
    : m_Name(name), m_Position(0.0f), m_Rotation(0.0f), m_Scale(1.0f) {}

glm::mat4 GameObject::GetTransform() const {
    glm::mat4 transform = glm::mat4(1.0f);
    transform = glm::translate(transform, m_Position);
    transform = glm::rotate(transform, m_Rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    transform = glm::rotate(transform, m_Rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    transform = glm::rotate(transform, m_Rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
    transform = glm::scale(transform, m_Scale);
    return transform;
}

void GameObject::Update(float deltaTime) {
    m_Rotation.y += deltaTime;
}

void GameObject::Render(class Shader* shader, class Camera* camera) {
}

}
}
