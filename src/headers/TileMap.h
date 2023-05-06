#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>

#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
    public:
        bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
        bool loadFromFile(const std::string& tileset, sf::Vector2u tileSize, const std::string& levelLayout);

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        std::vector<std::vector<int>> generateTilesFromFile(const std::string& file);

        sf::VertexArray _vertices;
        sf::Texture _tileset;
};

#endif // TILEMAP_H