#include "rendering/SimpleGUI.hpp"
#include <glad/glad.h>
#include <vector>

namespace RenderCore {
namespace Rendering {

void SimpleGUI::RenderDebugPanel(int fps, float camX, float camY, float camZ) {
    printf("FPS: %d | Camera: (%.1f, %.1f, %.1f)\r", fps, camX, camY, camZ);
    fflush(stdout);
}

void SimpleGUI::DrawRect(float x, float y, float width, float height) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

}
}
