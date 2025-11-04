#include "Application.hpp"
#include "Window.hpp"
#include "Shader.hpp"
#include "Renderer.hpp"
#include <iostream>

Application::Application()
    : m_Window(nullptr), m_Shader(nullptr), m_Renderer(nullptr), m_Running(false) {}

Application::~Application() {
    Shutdown();
}

bool Application::Initialize() {
    m_Window = new Window("Test Render", 800, 600);
    if (!m_Window->Initialize()) {
        return false;
    }

    m_Shader = new Shader("resources/shaders/basic.vert", "resources/shaders/basic.frag");
    if (!m_Shader->Compile()) {
        return false;
    }

    m_Renderer = new Renderer();

    m_Running = true;
    return true;
}

void Application::MainLoop() {
    while (m_Running && !m_Window->ShouldClose()) {
        m_Window->PollEvents();
        m_Renderer->Clear();
        m_Shader->Use();
        m_Renderer->DrawTriangle();
        m_Window->SwapBuffers();
    }
}

void Application::Shutdown() {
    delete m_Renderer;
    delete m_Shader;
    delete m_Window;
}

int Application::Run() {
    if (!Initialize()) {
        Shutdown();
        return -1;
    }

    MainLoop();
    Shutdown();
    return 0;
}
