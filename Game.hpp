#pragma once
#include <string>
#include <memory>
#include "InteractWithObjectController.hpp"
#include "Scene.hpp"

namespace GameEngine {
    class Game {
    private:
        std::shared_ptr<Scene> currentScene;

    public:
        Game(std::shared_ptr<Scene> scene);

        std::unique_ptr<InteractWithObjectController> startUseCase(const std::string& useCaseName);
    };
}