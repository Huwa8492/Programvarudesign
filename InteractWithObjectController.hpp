#pragma once
#include <string>
#include <memory>
#include "Scene.hpp"
#include "GameObject.hpp"
#include "InteractionType.hpp"

namespace GameEngine {
    class InteractWithObjectController {
    private:
        std::shared_ptr<Scene> currentScene;
        std::shared_ptr<GameObject> currentTarget;
        std::shared_ptr<InteractionType> currentInteraction;
        std::string currentOptions;

    public:
        InteractWithObjectController(std::shared_ptr<Scene> scene);

        std::shared_ptr<GameObject> getCurrentTarget() const;
        std::shared_ptr<InteractionType> getCurrentInteraction() const;
        std::string getCurrentOptions() const;

        bool selectGameObject(const std::string& name);
        bool selectInteraction(std::shared_ptr<GameObject> target, const std::string& interactionName);
        bool setInteractionOptions(const std::string& options);
        std::string startInteraction();
    };
}