#include <SFML/Graphics.hpp>

#include <iostream>

#include "window.h"

int main()
{
    Window window;

    sf::Texture texture;
    if (!texture.loadFromFile("assets/enemy weak.png"))
    {
        return 0;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            window.handleEvent(event);
        }

        window.frameLogic();

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}