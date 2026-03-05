#pragma once
#include "InteractionType.hpp"
#include <string>

namespace GameEngine {
    class TurnOn : public InteractionType {
    public:
        std::string executeInteraction(GameObject* context, const std::string& options) override;
    };

    class TurnOff : public InteractionType {
    public:
        std::string executeInteraction(GameObject* context, const std::string& options) override;
    };

    class Look : public InteractionType {
    public:
        std::string executeInteraction(GameObject* context, const std::string& options) override;
    };
}