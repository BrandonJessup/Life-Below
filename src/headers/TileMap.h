#ifndef TILE_MAP_H
#define TILE_MAP_H

#include <string>

#include <SFML/Graphics.hpp>

/*
    Cave as it will be drawn to screen.
*/
class TileMap : public sf::Drawable, public sf::Transformable
{
    public:
        TileMap();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        bool loadTextureSheet(const std::string& filename, const int& columns, const int& total);

        sf::VertexArray _vertices;
        sf::Texture _textureSheet;
};

#endif // TILE_MAP_H