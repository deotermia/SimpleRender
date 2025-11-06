#include "rendering/TextRenderer.hpp"
#include <iostream>

namespace RenderCore {
namespace Rendering {

void TextRenderer::Initialize() {
}

void TextRenderer::RenderText(const std::string& text, float x, float y, float scale, const glm::vec3& color) {
    std::cout << text << std::endl;
}

}
}
