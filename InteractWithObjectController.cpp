#include "InteractWithObjectController.hpp"
#include <stdexcept>

namespace GameEngine {
    InteractWithObjectController::InteractWithObjectController(std::shared_ptr<Scene> scene) 
        : currentScene(scene) {}

    std::shared_ptr<GameObject> InteractWithObjectController::getCurrentTarget() const { return currentTarget; }
    std::shared_ptr<InteractionType> InteractWithObjectController::getCurrentInteraction() const { return currentInteraction; }
    std::string InteractWithObjectController::getCurrentOptions() const { return currentOptions; }

    bool InteractWithObjectController::selectGameObject(const std::string& name) {
        currentTarget = currentScene->getObject(name);
        return currentTarget != nullptr;
    }

    bool InteractWithObjectController::selectInteraction(std::shared_ptr<GameObject> target, const std::string& interactionName) {
        if (!target || !target->hasInteraction(interactionName)) {
            return false;
        }
        currentInteraction = target->getInteraction(interactionName);
        return true;
    }

    bool InteractWithObjectController::setInteractionOptions(const std::string& options) {
        if (!currentInteraction) return false;
        currentOptions = options;
        return true;
    }

    std::string InteractWithObjectController::startInteraction() {
        if (!currentTarget || !currentInteraction) {
            throw std::logic_error("Must select object and interaction first.");
        }
        return currentInteraction->executeInteraction(currentTarget.get(), currentOptions);
    }
}