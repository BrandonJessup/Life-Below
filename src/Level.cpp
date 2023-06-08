#include "headers/Level.h"

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_cave);
}