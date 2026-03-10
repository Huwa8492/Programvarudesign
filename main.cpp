#include "Game.hpp"
#include "ConsoleUI.hpp"
#include "Scene.hpp"
#include "GameObject.hpp"
#include "Interactions.hpp"
#include <memory>

using namespace GameEngine;

int main() {
    // 1. Sätt upp startscenen med en TestLamp
    auto startScene = std::make_shared<Scene>();
    auto lamp = std::make_shared<GameObject>("TestLamp");
    
    lamp->addInteraction("TurnOn", std::make_shared<TurnOn>());
    lamp->addInteraction("TurnOff", std::make_shared<TurnOff>());
    lamp->addInteraction("Look", std::make_shared<Look>());
    
    startScene->addObject(lamp);

    // 2. Skapa spelet
    auto game = std::make_shared<Game>(startScene);

    // 3. Skicka spelet till vår nyskapade UI-modul
    ConsoleUI ui(game);
    
    // 4. Starta spelloopen!
    ui.run();

    return 0;
}