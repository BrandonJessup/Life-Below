#include "headers/Game.h"

#include "headers/Global.h"
#include "headers/CursorManager.h"
#include "headers/Window.h"
#include "headers/World.h"
#include "headers/DevDisplay.h"

Game::Game()
{
    _window.create();

    CursorManager::initialize(_window);
}

void Game::run()
{
    while (_window.isOpen())
    {
        sf::Event event;
        while (_window.pollEvent(event))
        {
            processEvent(event);
        }

        frameLogic();

        _window.clear();

        _world.draw(_window);
        _devDisplay.draw(_window);
        
        _window.display();
    }
}

void Game::processEvent(sf::Event& event)
{
    if (event.type == sf::Event::Closed)
    {
        _window.close();
    }
    else if (event.type == sf::Event::LostFocus)
    {
        _window.setMouseCursorGrabbed(false);
    }
    else if (event.type == sf::Event::MouseButtonPressed)
    {
        if (_window.isWithinBounds(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))
        {
            _window.setMouseCursorGrabbed(true);
        }
    }
    else if (event.type == sf::Event::MouseMoved)
    {
        if (_window.cursorGrabbed() && _window.mouseInEdgePanArea(event.mouseMove))
        {
            _world.updatePanDirection(_window.getSize(), event.mouseMove);
        }
        else if (!_window.mouseInEdgePanArea(event.mouseMove))
        {
            if (_world.isPanning())
            {
                _world.stopPanning();
                CursorManager::setCursorToDefault();
            }
        }
    }
    // TEMP: Development hotkeys.
    else if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Escape)
        {
            _window.close();
        }
        else if (event.key.code == sf::Keyboard::Enter)
        {
            _world.resetView();
            _devDisplay.showMessage("Re-centering");
        }
    }
}

void Game::frameLogic()
{
    _world.frameLogic();
    _devDisplay.frameLogic();
}