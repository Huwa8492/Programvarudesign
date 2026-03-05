#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include "InteractionType.hpp"

namespace GameEngine {
    class GameObject {
    private:
        std::string name;
        bool isOn;
        std::unordered_map<std::string, std::shared_ptr<InteractionType>> interactions;

    public:
        GameObject(const std::string& n);

        std::string getName() const;
        bool getIsOn() const;
        void setIsOn(bool state);

        void addInteraction(const std::string& actionName, std::shared_ptr<InteractionType> interaction);
        bool hasInteraction(const std::string& actionName) const;
        std::shared_ptr<InteractionType> getInteraction(const std::string& actionName);
    };
}