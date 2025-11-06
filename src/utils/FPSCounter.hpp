#pragma once

namespace RenderCore {
namespace Utils {

class FPSCounter {
public:
    FPSCounter();
    void Update();
    unsigned int GetFPS() const;

private:
    unsigned int m_FrameCount;
    double m_LastTime;
    unsigned int m_FPS;
};

}
}
