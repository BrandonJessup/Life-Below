#include "headers/TileMap.h"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
{
    if (!_tileset.loadFromFile(tileset))
    {
        return false;
    }

    _vertices.setPrimitiveType(sf::Quads);
    _vertices.resize(width * height * 4);

    for (unsigned int i = 0; i < width; ++i)
    {
        for (unsigned int j = 0; j < height; ++j)
        {
            int tileNumber = tiles[i + j * width];

            int tu = tileNumber % (_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (_tileset.getSize().x / tileSize.x);

            sf::Vertex* quad = &_vertices[(i + j * width) * 4];

            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }
    }

    return true;
}

bool TileMap::loadFromFile(const std::string& tileset, sf::Vector2u tileSize, const std::string& levelLayout)
{
    if (!_tileset.loadFromFile(tileset))
    {
        return false;
    }

    std::vector<std::vector<int>> tiles = generateTilesFromFile(levelLayout);
    if (tiles.empty())
    {
        return false;
    }

    int width = tiles.front().size();
    int height = tiles.size();

    _vertices.setPrimitiveType(sf::Quads);
    _vertices.resize(width * height * 4);

    for (unsigned int row = 0; row < height; ++row)
    {
        for (unsigned int col = 0; col < width; ++col)
        {
            int tileNumber = tiles[row][col];

            int tu = tileNumber % (_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (_tileset.getSize().x / tileSize.x);

            sf::Vertex* quad = &_vertices[(col + row * width) * 4];

            quad[0].position = sf::Vector2f(col * tileSize.x, row * tileSize.y);
            quad[1].position = sf::Vector2f((col + 1) * tileSize.x, row * tileSize.y);
            quad[2].position = sf::Vector2f((col + 1) * tileSize.x, (row + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(col * tileSize.x, (row + 1) * tileSize.y);

            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }
    }

    return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &_tileset;
    target.draw(_vertices, states);
}

std::vector<std::vector<int>> TileMap::generateTilesFromFile(const std::string& file)
{
    std::vector<std::vector<int>> tiles;

    std::ifstream fileStream(file, std::ifstream::in);
    if (!fileStream.is_open())
    {
        std::cout << "file could not be opened" << std::endl;
        return tiles;
    }
    
    std::string line;
    std::getline(fileStream, line);

    if (line != "START")
    {
        std::cout << "START not found" << std::endl;
        return tiles;
    }
    
    std::getline(fileStream, line);
    while (line != "END")
    {
        std::vector<int> tileRow;
        for (int i = 0; i < line.length(); ++i)
        {
            if (line[i] != '0' && line[i] != '1')
            {
                std::cout << "Invalid character in " << file << " : '" << line[i] << "'" << std::endl;
                return std::vector<std::vector<int>>();
            }
            tileRow.push_back(line[i] - '0');
        }
        tiles.push_back(tileRow);

        std::getline(fileStream, line);
        if (!fileStream.good())
        {
            std::cout << "Something went wrong while reading " << file << std::endl;
            return std::vector<std::vector<int>>();
        }
    }

    return tiles;
}