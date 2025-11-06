#pragma once
#include "rendering/Renderer.hpp"
#include "rendering/Shader.hpp"
#include "core/Window.hpp"

namespace RenderCore {
namespace Core {

class Application {
public:
    Application();
    int Run();

private:
    bool Initialize();
    void MainLoop();
    void Shutdown();
    
    Window* m_Window;
    Rendering::Renderer* m_Renderer;
    Rendering::Shader* m_Shader;
    bool m_Running;
};

} // namespace Core
} // namespace RenderCore
