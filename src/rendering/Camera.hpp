#pragma once
#include <glm/glm.hpp>

namespace RenderCore {
namespace Rendering {

class Camera {
public:
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f));

    glm::mat4 GetViewMatrix() const;
    glm::mat4 GetProjectionMatrix(float aspectRatio) const;

    void ProcessMouseMovement(float xOffset, float yOffset);
    void ProcessKeyboard(int direction, float deltaTime);

    glm::vec3 GetPosition() const { return m_Position; }

private:
    void UpdateCameraVectors();

    glm::vec3 m_Position;
    glm::vec3 m_Front;
    glm::vec3 m_Up;
    glm::vec3 m_Right;
    glm::vec3 m_WorldUp;

    float m_Yaw;
    float m_Pitch;
    float m_MovementSpeed;
    float m_MouseSensitivity;
};

}
}
