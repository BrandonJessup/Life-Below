#include "headers/Game.h"

#include "headers/Global.h"
#include "headers/Window.h"

Game::Game()
{
    _scale = 1; // TEMP: Delete and change everything to use global::WINDOW_SCALE after we settle on which scale to use

    _window.create(_scale);
}

void Game::run()
{
    // TEMP: Draw sprite to screen so we have some kind of temporary visual while I get the core functionality set up.
    sf::Texture texture;
    texture.loadFromFile("assets/enemy weak.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition((global::WINDOW_NATIVE_RESOLUTION_X - texture.getSize().x) / 2, (global::WINDOW_NATIVE_RESOLUTION_Y - texture.getSize().y) / 2);

    while (_window.isOpen())
    {
        sf::Event event;
        while (_window.pollEvent(event))
        {
            processEvent(event);
        }

        frameLogic();

        // TEMP: Draw sprite to screen so we have some kind of temporary visual while I get the core functionality set up.
        _window.clear();
        _window.draw(sprite);
        _window.display();
    }
}

void Game::processEvent(sf::Event& event)
{
    if (event.type == sf::Event::Closed)
    {
        _window.close();
    }
    // TODO
}

void Game::frameLogic()
{
    // TODO
}