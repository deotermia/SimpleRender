#pragma once
#include <string>

namespace RenderCore {
namespace Rendering {

class SimpleGUI {
public:
    static void RenderDebugPanel(int fps, float camX, float camY, float camZ);

private:
    static void DrawRect(float x, float y, float width, float height);
};

}
}
