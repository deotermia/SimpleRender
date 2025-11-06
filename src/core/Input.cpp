#include "core/Input.hpp"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace RenderCore {
namespace Core {

void* Input::s_Window = nullptr;
double Input::s_MouseX = 0.0;
double Input::s_MouseY = 0.0;

void Input::Initialize(void* window) {
    s_Window = window;
    glfwSetInputMode(static_cast<GLFWwindow*>(window), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    
    glfwGetCursorPos(static_cast<GLFWwindow*>(window), &s_MouseX, &s_MouseY);
}

bool Input::IsKeyPressed(int key) {
    return glfwGetKey(static_cast<GLFWwindow*>(s_Window), key) == GLFW_PRESS;
}

bool Input::IsMouseButtonPressed(int button) {
    return glfwGetMouseButton(static_cast<GLFWwindow*>(s_Window), button) == GLFW_PRESS;
}

void Input::GetMousePosition(double& x, double& y) {
    glfwGetCursorPos(static_cast<GLFWwindow*>(s_Window), &x, &y);
}

}
}
