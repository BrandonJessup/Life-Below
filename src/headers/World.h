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
        void updatePanDirection(const sf::Vector2u& windowSize, const sf::Vector2i& mousePosition);
        void resetView();
        void updateKeyPan();
        bool isKeyPanning();

    private:
        void initializeView();
        void loadTempSprite(); // TEMP

        void determineEdgePanDirection(const sf::Vector2u& windowSize, const sf::Vector2i& mousePosition);
        void panView();
        void drawMap(sf::RenderWindow& window);
        void drawEntities(sf::RenderWindow& window);
        Direction cardinalToOrdinal(const Direction& horizontal, const Direction& vertical);

        sf::View _view;
        sf::Cursor _panCursors[9];
        Direction _panDirectionHorizontal;
        Direction _panDirectionVertical;
        sf::Clock _panClockHorizontal;
        sf::Clock _panClockVertical;
        bool _keyPanning;
        
        Tiles _tiles;

        sf::Texture _tempTexture; // TEMP
        sf::Sprite _tempSprite; // TEMP
};

#endif // GAMEWORLD_H