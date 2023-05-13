#ifndef GAME_H
#define GAME_H

#include "Window.h"

#include "World.h"
#include "DevDisplay.h"

class Game
{
    public:
        Game();
        void run();

    private:
        void processEvent(sf::Event& event);
        void frameLogic();

        Window _window;
        World _world;
        // UserInterface _userInterface;
        DevDisplay _devDisplay;
};

#endif // GAME_H