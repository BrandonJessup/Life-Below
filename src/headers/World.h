#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <SFML/Graphics.hpp>

#include "Direction.h"
#include "Tiles.h"

class World
{
    public:
        World();
        void frameLogic();
        void draw(sf::RenderWindow& window);
        void stopPanning();
        bool isPanning();
        void updatePanDirection(const sf::Vector2u& windowSize, const sf::Event::MouseMoveEvent& mousePosition);
        void resetView();

    private:
        void initializeView();
        void loadTempSprite(); // TEMP

        Direction determineEdgePanDirection(const sf::Vector2u& windowSize, const sf::Event::MouseMoveEvent& mousePosition);
        void panView(Direction direction);
        void drawMap(sf::RenderWindow& window);
        void drawEntities(sf::RenderWindow& window);

        sf::View _view;
        sf::Cursor _panCursors[9];
        Direction _panDirection;
        sf::Clock _panClock;
        
        Tiles _tiles;

        sf::Texture _tempTexture; // TEMP
        sf::Sprite _tempSprite; // TEMP
};

#endif // GAMEWORLD_H