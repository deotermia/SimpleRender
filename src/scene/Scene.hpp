#pragma once
#include <vector>
#include <memory>

namespace RenderCore {
namespace Scene {

class Scene {
public:
    Scene();
    void AddGameObject(std::shared_ptr<class GameObject> gameObject);
    void Update(float deltaTime);
    void Render(class Shader* shader, class Camera* camera);

private:
    std::vector<std::shared_ptr<class GameObject>> m_GameObjects;
};

}
}
