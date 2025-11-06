#include "core/Application.hpp"
#include "core/Window.hpp"
#include "rendering/Renderer.hpp"
#include "rendering/Shader.hpp"
#include "rendering/Camera.hpp"
#include "rendering/Texture.hpp"
#include "rendering/DebugRenderer.hpp"
#include "scene/Scene.hpp"
#include "scene/GameObject.hpp"
#include "utils/Logger.hpp"
#include "utils/FPSCounter.hpp"
#include "core/Input.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <memory>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace RenderCore {
namespace Core {

Application::Application() 
    : m_Window(nullptr), m_Renderer(nullptr), m_Shader(nullptr), 
      m_DebugShader(nullptr), m_Camera(nullptr), m_Texture(nullptr), 
      m_Scene(nullptr), m_FPSCounter(nullptr), m_Running(false),
      m_ShowDebugInfo(true) {}

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
    Utils::Logger::Info("Initializing application...");

    m_Window = new Window("3D Render Engine", 800, 600);
    if (!m_Window->Initialize()) {
        Utils::Logger::Error("Failed to initialize window");
        return false;
    }

    Input::Initialize(m_Window->GetNativeWindow());

    m_Shader = new Rendering::Shader("resources/shaders/basic.vert", "resources/shaders/basic.frag");
    if (!m_Shader->Compile()) {
        Utils::Logger::Error("Failed to compile shaders");
        return false;
    }

    m_DebugShader = new Rendering::Shader("resources/shaders/debug.vert", "resources/shaders/debug.frag");
    if (!m_DebugShader->Compile()) {
        Utils::Logger::Warning("Failed to compile debug shader");
    }

    m_Renderer = new Rendering::Renderer();
    m_Camera = new Rendering::Camera();
    m_FPSCounter = new Utils::FPSCounter();
    
    m_Texture = new Rendering::Texture("resources/textures/texture.jpg");
    if (m_Texture->GetWidth() == 0) {
        Utils::Logger::Warning("Failed to load texture");
    }

    m_Scene = new Scene::Scene();
    
    auto testCube = std::make_shared<Scene::GameObject>("TestCube");
    testCube->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    m_Scene->AddGameObject(testCube);

    glEnable(GL_DEPTH_TEST);
    
    Utils::Logger::Info("Application initialized successfully");
    m_Running = true;
    return true;
}

void Application::ProcessInput(float deltaTime) {
    if (Input::IsKeyPressed(GLFW_KEY_ESCAPE)) {
        m_Running = false;
    }

    if (Input::IsKeyPressed(GLFW_KEY_W)) {
        m_Camera->ProcessKeyboard(0, deltaTime);
    }
    if (Input::IsKeyPressed(GLFW_KEY_S)) {
        m_Camera->ProcessKeyboard(1, deltaTime);
    }
    if (Input::IsKeyPressed(GLFW_KEY_A)) {
        m_Camera->ProcessKeyboard(2, deltaTime);
    }
    if (Input::IsKeyPressed(GLFW_KEY_D)) {
        m_Camera->ProcessKeyboard(3, deltaTime);
    }

    static double lastX = 400, lastY = 300;
    double x, y;
    Input::GetMousePosition(x, y);
    
    float xOffset = x - lastX;
    float yOffset = lastY - y;
    lastX = x;
    lastY = y;

    m_Camera->ProcessMouseMovement(xOffset, yOffset);
}

void Application::RenderDebugInfo() {
    if (m_DebugShader) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        m_DebugShader->Use();
        Rendering::DebugRenderer::DrawGrid(m_DebugShader, m_Camera);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    
    if (m_ShowDebugInfo) {
        if (m_FPSCounter) {
            std::string fpsText = "FPS: " + std::to_string(m_FPSCounter->GetFPS());
            std::cout << fpsText << std::endl;
        }
        
        glm::vec3 camPos = m_Camera->GetPosition();
        std::string posText = "Camera: (" + 
                             std::to_string((int)camPos.x) + ", " +
                             std::to_string((int)camPos.y) + ", " +
                             std::to_string((int)camPos.z) + ")";
        std::cout << posText << std::endl;
    }
}

void Application::MainLoop() {
    float lastTime = 0.0f;
    
    while (m_Running && !m_Window->ShouldClose()) {
        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        if (m_FPSCounter) {
            m_FPSCounter->Update();
        }

        ProcessInput(deltaTime);
        m_Window->PollEvents();
        m_Renderer->Clear();
        
        m_Scene->Update(deltaTime);
        
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::rotate(model, currentTime, glm::vec3(0.5f, 1.0f, 0.0f));
        
        m_Renderer->DrawCube(model, m_Shader, m_Camera, m_Texture);
        
        RenderDebugInfo();
        
        m_Window->SwapBuffers();
    }
}

void Application::Shutdown() {
    Utils::Logger::Info("Shutting down application...");
    
    if (m_Scene) delete m_Scene;
    if (m_Texture) delete m_Texture;
    if (m_Camera) delete m_Camera;
    if (m_Renderer) delete m_Renderer;
    if (m_Shader) delete m_Shader;
    if (m_DebugShader) delete m_DebugShader;
    if (m_FPSCounter) delete m_FPSCounter;
    if (m_Window) delete m_Window;
    
    Utils::Logger::Info("Application shutdown complete");
}

}
}
