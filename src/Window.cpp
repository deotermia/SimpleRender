#include "Window.hpp"
#include <iostream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

Window::Window(const std::string& title, int width, int height)
    : m_Window(nullptr), m_Title(title), m_Width(width), m_Height(height) {}

Window::~Window() {
    if (m_Window) {
        glfwDestroyWindow(static_cast<GLFWwindow*>(m_Window));
        glfwTerminate();
    }
}

bool Window::Initialize() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);
    if (!m_Window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(static_cast<GLFWwindow*>(m_Window));

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    glfwSetFramebufferSizeCallback(static_cast<GLFWwindow*>(m_Window),
        [](GLFWwindow* window, int width, int height) {
            glViewport(0, 0, width, height);
        });

    return true;
}

void Window::SwapBuffers() {
    glfwSwapBuffers(static_cast<GLFWwindow*>(m_Window));
}

void Window::PollEvents() {
    glfwPollEvents();
}

bool Window::ShouldClose() const {
    return glfwWindowShouldClose(static_cast<GLFWwindow*>(m_Window));
}
