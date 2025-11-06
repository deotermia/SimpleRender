#pragma once
#include <string>
#include <glm/glm.hpp>
#include <memory>

namespace RenderCore {
namespace Scene {

class GameObject {
public:
    GameObject(const std::string& name);
    
    void SetPosition(const glm::vec3& position) { m_Position = position; }
    void SetRotation(const glm::vec3& rotation) { m_Rotation = rotation; }
    void SetScale(const glm::vec3& scale) { m_Scale = scale; }
    
    const glm::vec3& GetPosition() const { return m_Position; }
    const glm::vec3& GetRotation() const { return m_Rotation; }
    const glm::vec3& GetScale() const { return m_Scale; }
    
    glm::mat4 GetTransform() const;
    
    void Update(float deltaTime);
    void Render(class Shader* shader, class Camera* camera);

private:
    std::string m_Name;
    glm::vec3 m_Position;
    glm::vec3 m_Rotation;
    glm::vec3 m_Scale;
};

}
}
