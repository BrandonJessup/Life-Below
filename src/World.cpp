#include "headers/World.h"

#include <iostream>

#include <SFML/Graphics.hpp>

#include "headers/Global.h"
#include "headers/Direction.h"
#include "headers/CursorManager.h"

World::World()
{
    initializeView();

    // TEMP
    loadTempSprite();

    _panDirectionHorizontal = NO_DIRECTION;
    _panDirectionVertical = NO_DIRECTION;
    _keyPanning = false;
}

void World::frameLogic()
{
    panView();
}

void World::draw(sf::RenderWindow& window)
{
    window.setView(_view);

    drawMap(window);
    drawEntities(window);
}

void World::stopPanning()
{
    _panDirectionHorizontal = NO_DIRECTION;
    _panDirectionVertical = NO_DIRECTION;
}

bool World::isPanning()
{
    return _panDirectionHorizontal != NO_DIRECTION || _panDirectionVertical != NO_DIRECTION;
}

void World::updatePanDirection(const sf::Vector2u& windowSize, const sf::Event::MouseMoveEvent& mousePosition)
{
    updatePanDirection(windowSize, sf::Vector2i(mousePosition.x, mousePosition.y));
}

void World::updatePanDirection(const sf::Vector2u& windowSize, const sf::Vector2i& mousePosition)
{
    Direction oldHorizontal = _panDirectionHorizontal;
    Direction oldVertical = _panDirectionVertical;
    determineEdgePanDirection(windowSize, mousePosition);
    if (oldHorizontal != _panDirectionHorizontal || oldVertical != _panDirectionVertical)
    {
        CursorManager::setCursorToMatchPanDirection(cardinalToOrdinal(_panDirectionHorizontal, _panDirectionVertical));
    }

    if (oldHorizontal != _panDirectionHorizontal)
    {
        _panClockHorizontal.restart();
    }
    if (oldVertical != _panDirectionVertical)
    {
        _panClockVertical.restart();
    }
}

void World::resetView()
{
    _view.setCenter(global::WINDOW_NATIVE_RESOLUTION_X / 2, global::WINDOW_NATIVE_RESOLUTION_Y / 2);
}

void World::updateKeyPan()
{
    bool up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    bool down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

    Direction oldHorizontal = _panDirectionHorizontal;
    Direction oldVertical = _panDirectionVertical;

    if (up && down)
    {
        _panDirectionVertical = NO_DIRECTION;
    }
    else if (up)
    {
        _panDirectionVertical = NORTH;
    }
    else if (down)
    {
        _panDirectionVertical = SOUTH;
    }
    else 
    {
        _panDirectionVertical = NO_DIRECTION;
    }

    if (left && right)
    {
        _panDirectionHorizontal = NO_DIRECTION;
    }
    else if (left)
    {
        _panDirectionHorizontal = WEST;
    }
    else if (right)
    {
        _panDirectionHorizontal = EAST;
    }
    else 
    {
        _panDirectionHorizontal = NO_DIRECTION;
    }

    if (oldHorizontal != _panDirectionHorizontal)
    {
        _panClockHorizontal.restart();
    }
    if (oldVertical != _panDirectionVertical)
    {
        _panClockVertical.restart();
    }

    if (_panDirectionHorizontal == NO_DIRECTION && _panDirectionVertical == NO_DIRECTION)
    {
        _keyPanning = false;
    }
    else
    {
        _keyPanning = true;
    }
}

bool World::isKeyPanning()
{
    return _keyPanning;
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

void World::determineEdgePanDirection(const sf::Vector2u& windowSize, const sf::Vector2i& mousePosition)
{   
    if (mousePosition.y < global::EDGE_PAN_REGION_THICKNESS)
    {
        _panDirectionVertical = NORTH;
    }
    else if (mousePosition.y > windowSize.y - global::EDGE_PAN_REGION_THICKNESS - 1)
    {
        _panDirectionVertical = SOUTH;
    }
    else 
    {
        _panDirectionVertical = NO_DIRECTION;
    }

    if (mousePosition.x < global::EDGE_PAN_REGION_THICKNESS)
    {
        _panDirectionHorizontal = WEST;
    }
    else if (mousePosition.x > windowSize.x - global::EDGE_PAN_REGION_THICKNESS - 1)
    {
        _panDirectionHorizontal = EAST;
    }
    else
    {
        _panDirectionHorizontal = NO_DIRECTION;
    }
}

void World::panView()
{
    if (_panDirectionHorizontal != NO_DIRECTION)
    {
        sf::Time sinceLastPan = _panClockHorizontal.getElapsedTime();

        // When this type is 'float' the movement will appear smoother, but blurrier,
        // when type is 'int' movement will appear more jagged.
        float panBy = sinceLastPan.asMilliseconds() * (global::EDGE_PAN_SPEED / 1000.0f);

        // If elapsed time since last pan isn't long enough to amount to a measurable 
        // amount of movement, don't restart the clock.
        if (panBy == 0)
        {
            return;
        }

        _panClockHorizontal.restart();

        if (_panDirectionHorizontal == EAST)
        {
            _view.move(panBy, 0);
        }
        else if (_panDirectionHorizontal == WEST)
        {
            _view.move(-panBy, 0);
        }
    }

    if (_panDirectionVertical != NO_DIRECTION)
    {
        sf::Time sinceLastPan = _panClockVertical.getElapsedTime();

        // When this type is 'float' the movement will appear smoother, but blurrier,
        // when type is 'int' movement will appear more jagged.
        float panBy = sinceLastPan.asMilliseconds() * (global::EDGE_PAN_SPEED / 1000.0f);

        // If elapsed time since last pan isn't long enough to amount to a measurable 
        // amount of movement, don't restart the clock.
        if (panBy == 0)
        {
            return;
        }

        _panClockVertical.restart();

        if (_panDirectionVertical == NORTH)
        {
            _view.move(0, -panBy);
        }
        else if (_panDirectionVertical == SOUTH)
        {
            _view.move(0, panBy);
        }
    }
}

void World::drawMap(sf::RenderWindow& window)
{
    window.draw(_level);
}

void World::drawEntities(sf::RenderWindow& window)
{
    // TEMP
    window.draw(_tempSprite);
}

Direction World::cardinalToOrdinal(const Direction& horizontal, const Direction& vertical)
{
    if (horizontal == NO_DIRECTION && vertical == NORTH)
    {
        return NORTH;
    }
    else if (horizontal == EAST && vertical == NORTH)
    {
        return NORTH_EAST;
    }
    else if (horizontal == EAST && vertical == NO_DIRECTION)
    {
        return EAST;
    }
    else if (horizontal == EAST && vertical == SOUTH)
    {
        return SOUTH_EAST;
    }
    else if (horizontal == NO_DIRECTION && vertical == SOUTH)
    {
        return SOUTH;
    }
    else if (horizontal == WEST && vertical == SOUTH)
    {
        return SOUTH_WEST;
    }
    else if (horizontal == WEST && vertical == NO_DIRECTION)
    {
        return WEST;
    }
    else if (horizontal == WEST && vertical == NORTH)
    {
        return NORTH_WEST;
    }
    else if (horizontal == NO_DIRECTION && vertical == NO_DIRECTION)
    {
        return NO_DIRECTION;
    }
    // DEBUG
    else
    {
        std::cout << "Invalid direction: " << "horizontal: " << horizontal << " vertical: " << vertical << std::endl;
        return NO_DIRECTION;
    }
}