#include "rendering/Camera.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace RenderCore {
namespace Rendering {

Camera::Camera(glm::vec3 position)
    : m_Position(position),
      m_Front(glm::vec3(0.0f, 0.0f, -1.0f)),
      m_WorldUp(glm::vec3(0.0f, 1.0f, 0.0f)),
      m_Yaw(-90.0f),
      m_Pitch(0.0f),
      m_MovementSpeed(2.5f),
      m_MouseSensitivity(0.1f)
{
    UpdateCameraVectors();
}

void Camera::ProcessMouseMovement(float xOffset, float yOffset)
{
    xOffset *= m_MouseSensitivity;
    yOffset *= m_MouseSensitivity;

    m_Yaw += xOffset;
    m_Pitch += yOffset;  // Возвращаем оригинальный знак

    if (m_Pitch > 89.0f) m_Pitch = 89.0f;
    if (m_Pitch < -89.0f) m_Pitch = -89.0f;

    UpdateCameraVectors();
}

void Camera::ProcessKeyboard(int direction, float deltaTime)
{
    float velocity = m_MovementSpeed * deltaTime;
    
    if (direction == 0)
        m_Position += m_Front * velocity;
    if (direction == 1)
        m_Position -= m_Front * velocity;
    if (direction == 2)
        m_Position -= m_Right * velocity;
    if (direction == 3)
        m_Position += m_Right * velocity;
}

void Camera::UpdateCameraVectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    front.y = sin(glm::radians(m_Pitch));
    front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    m_Front = glm::normalize(front);

    m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp));
    m_Up = glm::normalize(glm::cross(m_Right, m_Front));
}

glm::mat4 Camera::GetViewMatrix() const
{
    return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}

glm::mat4 Camera::GetProjectionMatrix(float aspectRatio) const
{
    return glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 100.0f);
}

}
}
