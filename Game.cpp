#include "Game.hpp"

namespace GameEngine {
    Game::Game(std::shared_ptr<Scene> scene) : currentScene(scene) {}

    std::unique_ptr<InteractWithObjectController> Game::startUseCase(const std::string& useCaseName) {
        if (useCaseName == "InteractWithObject") {
            // Här delegerar Game ansvaret till controllern (High Cohesion!)
            return std::make_unique<InteractWithObjectController>(currentScene);
        }
        return nullptr;
    }
}