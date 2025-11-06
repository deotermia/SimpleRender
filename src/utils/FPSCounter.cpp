#include "utils/FPSCounter.hpp"
#include <GLFW/glfw3.h>

namespace RenderCore {
namespace Utils {

FPSCounter::FPSCounter() 
    : m_FrameCount(0), m_LastTime(0.0), m_FPS(0) {}

void FPSCounter::Update() {
    m_FrameCount++;
    double currentTime = glfwGetTime();
    if (currentTime - m_LastTime >= 1.0) {
        m_FPS = m_FrameCount;
        m_FrameCount = 0;
        m_LastTime = currentTime;
    }
}

unsigned int FPSCounter::GetFPS() const {
    return m_FPS;
}

}
}
