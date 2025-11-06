#pragma once
#include <string>
#include <glm/glm.hpp>

namespace RenderCore {
namespace Rendering {

class TextRenderer {
public:
    static void Initialize();
    static void RenderText(const std::string& text, float x, float y, float scale, const glm::vec3& color);
};

}
}
