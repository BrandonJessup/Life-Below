#include "headers/Game.h"

#include "headers/Global.h"
#include "headers/CursorManager.h"
#include "headers/Window.h"
#include "headers/World.h"
#include "headers/DevDisplay.h"

Game::Game()
{
    _scale = 1; // TEMP: Delete and change everything to use global::WINDOW_SCALE after we settle on which scale to use

    _window.create(_scale);

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

        // TEMP: Draw sprite to screen so we have some kind of temporary visual while I get the core functionality set up.
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
            _world.setPanDirection(EdgePanDirection::NONE);
            CursorManager::setCursorToDefault();
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
        }
        else if (event.key.code == sf::Keyboard::Up)
        {
            ++_scale;
            if (_scale > global::WINDOW_SCALING_MAX)
            {
                _scale = global::WINDOW_SCALING_MAX;
            }
            _window.updateWindowSize(_scale);
            _devDisplay.scaleChanged(_scale);
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
            --_scale;
            if (_scale < global::WINDOW_SCALING_MIN)
            {
                _scale = global::WINDOW_SCALING_MIN;
            }
            _window.updateWindowSize(_scale);
            _devDisplay.scaleChanged(_scale);
        }
    }
}

void Game::frameLogic()
{
    _world.frameLogic();
}