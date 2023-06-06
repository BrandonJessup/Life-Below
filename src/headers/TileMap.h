#ifndef TILE_MAP_H
#define TILE_MAP_H

#include <string>

#include <SFML/Graphics.hpp>

class TileMap
{
    public:
        TileMap();
        void draw(sf::RenderWindow& window);

    private:
        bool loadTextureSheet(const std::string& filename, const int& columns, const int& total);

        sf::VertexArray _vertices;
        sf::Texture _textureSheet;
};

#endif // TILE_MAP_H