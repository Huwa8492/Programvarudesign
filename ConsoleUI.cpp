#include "ConsoleUI.hpp"
#include <iostream>

namespace GameEngine {
    ConsoleUI::ConsoleUI(std::shared_ptr<Game> gameInstance) : game(gameInstance) {}

    void ConsoleUI::run() {
        bool playing = true;
        while (playing) {
            displayMainMenu();
            std::string choice;
            std::cout << "\nChoose an option: ";
            std::cin >> choice;

            if (choice == "1") {
                handleInteractWithObject();
            } else if (choice == "2") {
                std::cout << "\n[Interact with Character will be implemented here soon!]\n";
            } else if (choice == "3") {
                playing = false;
                std::cout << "\nExiting game...\n";
            } else {
                std::cout << "\nInvalid choice. Try again.\n";
            }
        }
    }

    void ConsoleUI::displayMainMenu() {
        std::cout << "\n=== MAIN MENU ===\n";
        std::cout << "1. Interact with Object\n";
        std::cout << "2. Interact with Character\n";
        std::cout << "3. Quit\n";
    }

    void ConsoleUI::handleInteractWithObject() {
        // 1. Starta use caset via Game
        auto controller = game->startUseCase("InteractWithObject");
        if (!controller) {
            std::cout << "\nError: Could not start Use Case.\n";
            return;
        }

        // 2. Välj objekt (System Event 1)
        std::cout << "\nWhat object do you want to interact with? (e.g., TestLamp): ";
        std::string objName;
        std::cin >> objName;

        if (!controller->selectGameObject(objName)) {
            std::cout << "There is no " << objName << " here.\n";
            return;
        }

        // 3. Välj interaktion (System Event 2)
        std::cout << "What do you want to do with the " << objName << "? (e.g., TurnOn, Look): ";
        std::string interaction;
        std::cin >> interaction;

        if (!controller->selectInteraction(controller->getCurrentTarget(), interaction)) {
            std::cout << "You can't " << interaction << " the " << objName << ".\n";
            return;
        }

        // 4. Utför interaktionen (System Event 4) och printa resultatet
        try {
            std::string result = controller->startInteraction();
            std::cout << "\n--> " << result << "\n";
        } catch (const std::exception& e) {
            std::cout << "\nFailed: " << e.what() << "\n";
        }
    }
}