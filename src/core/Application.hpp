#pragma once
#include "rendering/Renderer.hpp"
#include "rendering/Shader.hpp"
#include "rendering/Camera.hpp"
#include "rendering/Texture.hpp"
#include "scene/Scene.hpp"
#include "core/Window.hpp"

namespace RenderCore {
namespace Utils {
    class FPSCounter;
}

namespace Core {

class Application {
public:
    Application();
    int Run();

private:
    bool Initialize();
    void MainLoop();
    void Shutdown();
    void ProcessInput(float deltaTime);
    void RenderDebugInfo();
    
    Window* m_Window;
    Rendering::Renderer* m_Renderer;
    Rendering::Shader* m_Shader;
    Rendering::Shader* m_DebugShader;
    Rendering::Camera* m_Camera;
    Rendering::Texture* m_Texture;
    Scene::Scene* m_Scene;
    Utils::FPSCounter* m_FPSCounter;
    bool m_Running;
    bool m_ShowDebugInfo;
};

}
}
