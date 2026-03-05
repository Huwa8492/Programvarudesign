#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include "GameObject.hpp"

namespace GameEngine {
    class Scene {
    private:
        std::unordered_map<std::string, std::shared_ptr<GameObject>> gameObjects;

    public:
        void addObject(std::shared_ptr<GameObject> obj);
        std::shared_ptr<GameObject> getObject(const std::string& name);
    };
}