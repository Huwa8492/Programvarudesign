#include "Scene.hpp"

namespace GameEngine {
    void Scene::addObject(std::shared_ptr<GameObject> obj) {
        if (obj) {
            gameObjects[obj->getName()] = obj;
        }
    }

    std::shared_ptr<GameObject> Scene::getObject(const std::string& name) {
        auto it = gameObjects.find(name);
        if (it != gameObjects.end()) {
            return it->second;
        }
        return nullptr;
    }
}