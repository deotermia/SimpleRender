#pragma once

namespace RenderCore {
namespace Core {

class Input {
public:
    static void Initialize(void* window);
    static bool IsKeyPressed(int key);
    static bool IsMouseButtonPressed(int button);
    static void GetMousePosition(double& x, double& y);

private:
    static void* s_Window;
    static double s_MouseX, s_MouseY;
};

}
}
