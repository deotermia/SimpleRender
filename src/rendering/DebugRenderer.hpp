#pragma once
#include <glm/glm.hpp>

namespace RenderCore {
namespace Rendering {

class DebugRenderer {
public:
    static void DrawGrid(class Shader* shader, class Camera* camera);
};

}
}
