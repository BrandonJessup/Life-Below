#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <SFML/Graphics.hpp>

#include "EdgePanDirection.h"

class World
{
    public:
        World();
        void frameLogic();
        void draw(sf::RenderWindow& window);
        void setPanDirection(const EdgePanDirection& direction);
        void updatePanDirection(const sf::Vector2u& windowSize, const sf::Event::MouseMoveEvent& mousePosition);
        void resetView();

    private:
        void initializeView();
        void loadTempSprite(); // TEMP

        EdgePanDirection determineEdgePanDirection(const sf::Vector2u& windowSize, const sf::Event::MouseMoveEvent& mousePosition);
        void panView(EdgePanDirection direction);

        sf::View _view;
        sf::Cursor _panCursors[9];
        EdgePanDirection _panDirection;
        sf::Clock _panClock;

        sf::Texture _tempTexture; // TEMP
        sf::Sprite _tempSprite; // TEMP
};

#endif // GAMEWORLD_H