#include "headers/Tiles.h"

Tiles::Tiles()
{
    const int level[] =
    {
        0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 0,
        0, 2, 1, 1, 1, 0,
        0, 1, 1, 1, 2, 0,
        0, 0, 0, 0, 0, 0
    };

    load("assets/tile sheet.png", sf::Vector2u(48, 48), level, 6, 6);
}