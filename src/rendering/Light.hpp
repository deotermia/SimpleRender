#pragma once
#include <glm/glm.hpp>

namespace RenderCore {
namespace Rendering {

struct Light {
    glm::vec3 position;
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    
    Light() : position(2.0f, 2.0f, 2.0f),
              ambient(0.2f, 0.2f, 0.2f),
              diffuse(0.5f, 0.5f, 0.5f),
              specular(1.0f, 1.0f, 1.0f) {}
};

}
}
