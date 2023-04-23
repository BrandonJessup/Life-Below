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
    sprite.setPosition((400 - texture.getSize().x) / 2, (400 - texture.getSize().y) / 2);

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