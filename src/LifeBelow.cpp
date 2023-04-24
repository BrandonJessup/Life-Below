#include <SFML/Graphics.hpp>

#include <iostream>

#include "Window.h"
#include "Global.h"

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
    sprite.setPosition((global::WINDOW_NATIVE_RESOLUTION_X - texture.getSize().x) / 2, (global::WINDOW_NATIVE_RESOLUTION_Y - texture.getSize().y) / 2);

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