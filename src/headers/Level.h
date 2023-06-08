#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>

#include "Cave.h"

/*
    Generates layout of cave.
*/
class Level : public sf::Drawable, public sf::Transformable
{
    public:
        // TODO

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        
    private:
        Cave _cave;
};

#endif // LEVEL_H