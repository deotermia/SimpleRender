#pragma once
#include <string>

namespace RenderCore {
namespace Core {

class Window {
public:
    Window(const std::string& title, int width, int height);
    ~Window();
    
    bool Initialize();
    void SwapBuffers();
    void PollEvents();
    bool ShouldClose() const;
    
    void* GetNativeWindow() const { return m_Window; }
    int GetWidth() const { return m_Width; }
    int GetHeight() const { return m_Height; }

private:
    void* m_Window;
    std::string m_Title;
    int m_Width;
    int m_Height;
};

} // namespace Core
} // namespace RenderCore
