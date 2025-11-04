#pragma once

class Window;
class Shader;
class Renderer;

class Application {
public:
    Application();
    ~Application();
    int Run();

private:
    bool Initialize();
    void MainLoop();
    void Shutdown();

    Window* m_Window;
    Shader* m_Shader;
    Renderer* m_Renderer;
    bool m_Running;
};
