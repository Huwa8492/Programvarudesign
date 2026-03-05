#include "Interactions.hpp"
#include "GameObject.hpp"

namespace GameEngine {
    std::string TurnOn::executeInteraction(GameObject* context, const std::string& options) {
        context->setIsOn(true);
        return context->getName() + " is now turned ON.";
    }

    std::string TurnOff::executeInteraction(GameObject* context, const std::string& options) {
        context->setIsOn(false);
        return context->getName() + " is now turned OFF.";
    }

    std::string Look::executeInteraction(GameObject* context, const std::string& options) {
        std::string state = context->getIsOn() ? "ON" : "OFF";
        return "You look at the " + context->getName() + ". It is currently " + state + ".";
    }
}