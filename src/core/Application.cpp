#include "core/Application.hpp"
#include "core/Window.hpp"
#include "rendering/Renderer.hpp"
#include "rendering/Shader.hpp"
#include <iostream>

namespace RenderCore {
namespace Core {

Application::Application() 
    : m_Window(nullptr), m_Renderer(nullptr), m_Shader(nullptr), m_Running(false) {}

int Application::Run() {
    if (!Initialize()) {
        Shutdown();
        return -1;
    }
    
    MainLoop();
    Shutdown();
    return 0;
}

bool Application::Initialize() {
    m_Window = new Window("Triangle", 800, 600);
    if (!m_Window->Initialize()) return false;

    m_Shader = new Rendering::Shader("resources/shaders/basic.vert", "resources/shaders/basic.frag");
    if (!m_Shader->Compile()) return false;

    m_Renderer = new Rendering::Renderer();
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

} // namespace Core
} // namespace RenderCore
