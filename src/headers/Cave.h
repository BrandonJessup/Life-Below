#ifndef CAVE_H
#define CAVE_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "Tile.h"
#include "TileMap.h"

/*
    Layout of cave, and interface to alter it.
*/
class Cave : public sf::Drawable, public sf::Transformable
{
    public:
        Cave();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        std::vector<std::vector<Tile>> _tiles;
        TileMap _tileMap;
};

#endif // CAVE_H