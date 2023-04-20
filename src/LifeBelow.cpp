#include <SFML/Graphics.hpp>

#include "window.h"

int main()
{
    Window window;
    
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            window.handleEvent(event);
        }

        window.frameLogic();

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}