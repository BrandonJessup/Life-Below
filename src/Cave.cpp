#include "headers/Cave.h"

Cave::Cave()
{
    // TODO
}

void Cave::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_tileMap);
}