#include "GameObject.hpp"

namespace GameEngine {
    GameObject::GameObject(const std::string& n) : name(n), isOn(false) {}

    std::string GameObject::getName() const { return name; }
    bool GameObject::getIsOn() const { return isOn; }
    void GameObject::setIsOn(bool state) { isOn = state; }

    void GameObject::addInteraction(const std::string& actionName, std::shared_ptr<InteractionType> interaction) {
        interactions[actionName] = interaction;
    }

    bool GameObject::hasInteraction(const std::string& actionName) const {
        return interactions.find(actionName) != interactions.end();
    }

    std::shared_ptr<InteractionType> GameObject::getInteraction(const std::string& actionName) {
        auto it = interactions.find(actionName);
        if (it != interactions.end()) {
            return it->second;
        }
        return nullptr;
    }
}