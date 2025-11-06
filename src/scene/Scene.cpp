#include "scene/Scene.hpp"
#include "scene/GameObject.hpp"

namespace RenderCore {
namespace Scene {

Scene::Scene() {}

void Scene::AddGameObject(std::shared_ptr<GameObject> gameObject) {
    m_GameObjects.push_back(gameObject);
}

void Scene::Update(float deltaTime) {
    for (auto& gameObject : m_GameObjects) {
        gameObject->Update(deltaTime);
    }
}

void Scene::Render(class Shader* shader, class Camera* camera) {
    for (auto& gameObject : m_GameObjects) {
        gameObject->Render(shader, camera);
    }
}

}
}
