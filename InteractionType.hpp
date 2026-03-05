#pragma once
#include <string>

namespace GameEngine {
    class GameObject;

    class InteractionType {
    public:
        virtual ~InteractionType() = default;
        virtual std::string executeInteraction(GameObject* context, const std::string& options) = 0;
    };
}