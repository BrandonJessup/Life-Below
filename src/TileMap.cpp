#include "headers/TileMap.h"

#include <string>

TileMap::TileMap()
{
    // TODO
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &_textureSheet;
    target.draw(_vertices, states);
}

bool TileMap::loadTextureSheet(const std::string& filename, const int& columns, const int& total)
{
    // TODO
}