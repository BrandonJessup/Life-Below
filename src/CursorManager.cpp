#include "headers/CursorManager.h"

#include <SFML/Graphics.hpp>

#include "headers/Direction.h"

sf::RenderWindow* CursorManager::_window;
sf::Cursor CursorManager::_panCursors[9];

void CursorManager::initialize(sf::RenderWindow& window)
{
    _window = &window;

    initializeCursors();
}

void CursorManager::initializeCursors()
{
    _panCursors[NO_DIRECTION].loadFromSystem(sf::Cursor::Arrow);
    _panCursors[NORTH].loadFromSystem(sf::Cursor::SizeVertical);
    _panCursors[NORTH_EAST].loadFromSystem(sf::Cursor::SizeBottomLeftTopRight);
    _panCursors[EAST].loadFromSystem(sf::Cursor::SizeHorizontal);
    _panCursors[SOUTH_EAST].loadFromSystem(sf::Cursor::SizeTopLeftBottomRight);
    _panCursors[SOUTH].loadFromSystem(sf::Cursor::SizeVertical);
    _panCursors[SOUTH_WEST].loadFromSystem(sf::Cursor::SizeBottomLeftTopRight);
    _panCursors[WEST].loadFromSystem(sf::Cursor::SizeHorizontal);
    _panCursors[NORTH_WEST].loadFromSystem(sf::Cursor::SizeTopLeftBottomRight);
}

void CursorManager::setCursorToDefault()
{
    _window->setMouseCursor(_panCursors[NO_DIRECTION]);
}

void CursorManager::setCursorToMatchPanDirection(const Direction& direction)
{
    _window->setMouseCursor(_panCursors[direction]);
}