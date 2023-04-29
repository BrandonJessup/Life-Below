#include "headers/World.h"

#include <SFML/Graphics.hpp>

#include "headers/Global.h"
#include "headers/EdgePanDirection.h"
#include "headers/CursorManager.h"

World::World()
{
    initializeView();

    // TEMP
    loadTempSprite();

    _panDirection = NONE;
}

void World::frameLogic()
{
    panView(_panDirection);
}

void World::draw(sf::RenderWindow& window)
{
    window.setView(_view);

    // TEMP
    window.draw(_tempSprite);
}

void World::setPanDirection(const EdgePanDirection& direction)
{
    _panDirection = direction;
}

void World::updatePanDirection(const sf::Vector2u& windowSize, const sf::Event::MouseMoveEvent& mousePosition)
{
    EdgePanDirection oldPanDirection = _panDirection;
    _panDirection = determineEdgePanDirection(windowSize, mousePosition);
    if (_panDirection != oldPanDirection)
    {
        _panClock.restart();
        CursorManager::setCursorToMatchPanDirection(_panDirection);
    }
}

void World::resetView()
{
    _view.setCenter(global::WINDOW_NATIVE_RESOLUTION_X / 2, global::WINDOW_NATIVE_RESOLUTION_Y / 2);
}

void World::initializeView()
{
    _view.setSize(global::WINDOW_NATIVE_RESOLUTION_X, global::WINDOW_NATIVE_RESOLUTION_Y);
    _view.setCenter(global::WINDOW_NATIVE_RESOLUTION_X / 2, global::WINDOW_NATIVE_RESOLUTION_Y / 2);
}

// TEMP
void World::loadTempSprite()
{
    // TEMP: Draw sprite to screen so we have some kind of temporary visual while I get the core functionality set up.
    _tempTexture.loadFromFile("assets/enemy weak.png");
    _tempSprite.setTexture(_tempTexture);
    _tempSprite.setPosition((global::WINDOW_NATIVE_RESOLUTION_X - _tempTexture.getSize().x) / 2, (global::WINDOW_NATIVE_RESOLUTION_Y - _tempTexture.getSize().y) / 2);
}

EdgePanDirection World::determineEdgePanDirection(const sf::Vector2u& windowSize, const sf::Event::MouseMoveEvent& mousePosition)
{
    if (mousePosition.x < global::EDGE_PAN_REGION_THICKNESS && mousePosition.y < global::EDGE_PAN_REGION_THICKNESS)
    {
        return NORTH_WEST;
    }
    else if (mousePosition.x < global::EDGE_PAN_REGION_THICKNESS && mousePosition.y > windowSize.y - global::EDGE_PAN_REGION_THICKNESS - 1)
    {
        return SOUTH_WEST;
    }
    else if (mousePosition.x < global::EDGE_PAN_REGION_THICKNESS)
    {
        return WEST;
    }
    else if (mousePosition.x > windowSize.x - global::EDGE_PAN_REGION_THICKNESS - 1 && mousePosition.y < global::EDGE_PAN_REGION_THICKNESS)
    {
        return NORTH_EAST;
    }
    else if (mousePosition.x > windowSize.x - global::EDGE_PAN_REGION_THICKNESS - 1 && mousePosition.y > windowSize.y - global::EDGE_PAN_REGION_THICKNESS - 1)
    {
        return SOUTH_EAST;
    }
    else if (mousePosition.x > windowSize.x - global::EDGE_PAN_REGION_THICKNESS - 1)
    {
        return EAST;
    }
    else if (mousePosition.y < global::EDGE_PAN_REGION_THICKNESS)
    {
        return NORTH;
    }
    else if (mousePosition.y > windowSize.y - global::EDGE_PAN_REGION_THICKNESS - 1)
    {
        return SOUTH;
    }
    
    return NONE;
}

void World::panView(EdgePanDirection direction)
{
    if (_panDirection != NONE)
    {
        sf::Time sinceLastPan = _panClock.getElapsedTime();

        // When this type is 'float' the movement will appear smoother, but blurrier,
        // when type is 'int' movement will appear more jagged.
        float panBy = sinceLastPan.asMilliseconds() * (global::EDGE_PAN_SPEED / 1000.0f);

        // If elapsed time since last pan isn't long enough to amount to a measurable 
        // amount of movement, don't restart the clock.
        if (panBy == 0)
        {
            return;
        }

        _panClock.restart();

        if (direction == NORTH)
        {
            _view.move(0, -panBy);
        }
        else if (direction == NORTH_EAST)
        {
            _view.move(panBy, -panBy);
        }
        else if (direction == EAST)
        {
            _view.move(panBy, 0);
        }
        else if (direction == SOUTH_EAST)
        {
            _view.move(panBy, panBy);
        }
        else if (direction == SOUTH)
        {
            _view.move(0, panBy);
        }
        else if (direction == SOUTH_WEST)
        {
            _view.move(-panBy, panBy);
        }
        else if (direction == WEST)
        {
            _view.move(-panBy, 0);
        }
        else if (direction == NORTH_WEST)
        {
            _view.move(-panBy, -panBy);
        }
    }
}