#pragma once
#include <memory>
#include "Game.hpp"

namespace GameEngine {
    class ConsoleUI {
    private:
        std::shared_ptr<Game> game;
        void displayMainMenu();
        void handleInteractWithObject();

    public:
        ConsoleUI(std::shared_ptr<Game> gameInstance);
        void run();
    };
}