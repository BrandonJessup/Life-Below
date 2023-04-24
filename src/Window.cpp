#include "Window.h"

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Globals.h"

Window::Window()
{
    initializeCursors();

    // // Fullscreen
    // sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    // create(sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel), "Life Below", sf::Style::Fullscreen);
    
    // Windowed
    create(sf::VideoMode(globals::WINDOW_NATIVE_RESOLUTION_X * globals::scale, globals::WINDOW_NATIVE_RESOLUTION_Y * globals::scale), "Life Below", sf::Style::Close);

    setMouseCursorGrabbed(true);

    setFramerateLimit(120);

    _panDirection = NONE;
}

void Window::onResize()
{
    sf::View view = getView();
    sf::Vector2u newSize = getSize();
    view.setSize(newSize.x, newSize.y);
    setView(view);
}

void Window::handleEvent(sf::Event& event)
{
    if (event.type == sf::Event::Closed)
    {
        close();
    }
    else if (event.type == sf::Event::LostFocus)
    {
        setMouseCursorGrabbed(false);
    }
    else if (event.type == sf::Event::MouseButtonPressed)
    {
        if (isWithinWindowBounds(event.mouseButton.x, event.mouseButton.y))
        {
            setMouseCursorGrabbed(true);
        }
    }
    else if (event.type == sf::Event::MouseMoved)
    {
        if (hasFocus() && _cursorIsGrabbed && mouseInEdgePanArea(event.mouseMove))
        {
            EdgePanDirection oldPanDirection = _panDirection;
            _panDirection = determineEdgePanDirection(event.mouseMove);
            if (_panDirection != oldPanDirection)
            {
                _panClock.restart();
                setCursorToMatchPanDirection(_panDirection);
            }
        }
        else if (!mouseInEdgePanArea(event.mouseMove))
        {
            _panDirection = NONE;
            setCursorToDefault();
        }
    }
    // TEMP: Development hotkeys.
    else if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Escape)
        {
            close();
        }
        // Move view back to starting position.
        else if (event.key.code == sf::Keyboard::Enter)
        {
            sf::View view = getView();
            view.setCenter(400 / 2, 400 / 2);
            setView(view);
        }
        else if (event.key.code == sf::Keyboard::Up)
        {
            ++globals::scale;
            if (globals::scale > globals::WINDOW_SCALING_MAX)
            {
                globals::scale = globals::WINDOW_SCALING_MAX;
            }
            updateWindowSize(globals::scale);
            std::cout << "Scale: " << globals::scale << std::endl;
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
            --globals::scale;
            if (globals::scale < globals::WINDOW_SCALING_MIN)
            {
                globals::scale = globals::WINDOW_SCALING_MIN;
            }
            updateWindowSize(globals::scale);
            std::cout << "Scale: " << globals::scale << std::endl;
        }
    }
}

void Window::frameLogic()
{
    if (_panDirection != NONE)
    {
        panView(_panDirection);
    }
}

void Window::initializeCursors()
{
    _panCursors[NONE].loadFromSystem(sf::Cursor::Arrow);
    _panCursors[NORTH].loadFromSystem(sf::Cursor::SizeVertical);
    _panCursors[NORTH_EAST].loadFromSystem(sf::Cursor::SizeBottomLeftTopRight);
    _panCursors[EAST].loadFromSystem(sf::Cursor::SizeHorizontal);
    _panCursors[SOUTH_EAST].loadFromSystem(sf::Cursor::SizeTopLeftBottomRight);
    _panCursors[SOUTH].loadFromSystem(sf::Cursor::SizeVertical);
    _panCursors[SOUTH_WEST].loadFromSystem(sf::Cursor::SizeBottomLeftTopRight);
    _panCursors[WEST].loadFromSystem(sf::Cursor::SizeHorizontal);
    _panCursors[NORTH_WEST].loadFromSystem(sf::Cursor::SizeTopLeftBottomRight);
}

bool Window::mouseInEdgePanArea(sf::Event::MouseMoveEvent mousePosition)
{
    sf::Vector2u windowSize = getSize();
    if (
        mousePosition.x < globals::EDGE_PAN_REGION_THICKNESS
        || mousePosition.x > windowSize.x - globals::EDGE_PAN_REGION_THICKNESS - 1
        || mousePosition.y < globals::EDGE_PAN_REGION_THICKNESS
        || mousePosition.y > windowSize.y - globals::EDGE_PAN_REGION_THICKNESS - 1
    )
    {
        return true;
    }
    
    return false;
}

Window::EdgePanDirection Window::determineEdgePanDirection(sf::Event::MouseMoveEvent mousePosition)
{
    sf::Vector2u windowSize = getSize();
    if (mousePosition.x < globals::EDGE_PAN_REGION_THICKNESS && mousePosition.y < globals::EDGE_PAN_REGION_THICKNESS)
    {
        return NORTH_WEST;
    }
    else if (mousePosition.x < globals::EDGE_PAN_REGION_THICKNESS && mousePosition.y > windowSize.y - globals::EDGE_PAN_REGION_THICKNESS - 1)
    {
        return SOUTH_WEST;
    }
    else if (mousePosition.x < globals::EDGE_PAN_REGION_THICKNESS)
    {
        return WEST;
    }
    else if (mousePosition.x > windowSize.x - globals::EDGE_PAN_REGION_THICKNESS - 1 && mousePosition.y < globals::EDGE_PAN_REGION_THICKNESS)
    {
        return NORTH_EAST;
    }
    else if (mousePosition.x > windowSize.x - globals::EDGE_PAN_REGION_THICKNESS - 1 && mousePosition.y > windowSize.y - globals::EDGE_PAN_REGION_THICKNESS - 1)
    {
        return SOUTH_EAST;
    }
    else if (mousePosition.x > windowSize.x - globals::EDGE_PAN_REGION_THICKNESS - 1)
    {
        return EAST;
    }
    else if (mousePosition.y < globals::EDGE_PAN_REGION_THICKNESS)
    {
        return NORTH;
    }
    else if (mousePosition.y > windowSize.y - globals::EDGE_PAN_REGION_THICKNESS - 1)
    {
        return SOUTH;
    }
    
    return NONE;
}

void Window::setCursorToDefault()
{
    setMouseCursor(_panCursors[NONE]);
}

void Window::setCursorToMatchPanDirection(EdgePanDirection direction)
{
    setMouseCursor(_panCursors[direction]);
}

void Window::panView(EdgePanDirection direction)
{
    sf::View view = getView();

    sf::Time sinceLastPan = _panClock.getElapsedTime();

    // When this type is 'float' the movement will appear smoother, but blurrier,
    // when type is 'int' movement will appear more jagged.
    float panBy = sinceLastPan.asMilliseconds() * (globals::EDGE_PAN_SPEED / 1000.0f);

    // If elapsed time since last pan isn't long enough to amount to a measurable 
    // amount of movement, don't restart the clock.
    if (panBy == 0)
    {
        return;
    }

    _panClock.restart();

    if (direction == NORTH)
    {
        view.move(0, -panBy);
    }
    else if (direction == NORTH_EAST)
    {
        view.move(panBy, -panBy);
    }
    else if (direction == EAST)
    {
        view.move(panBy, 0);
    }
    else if (direction == SOUTH_EAST)
    {
        view.move(panBy, panBy);
    }
    else if (direction == SOUTH)
    {
        view.move(0, panBy);
    }
    else if (direction == SOUTH_WEST)
    {
        view.move(-panBy, panBy);
    }
    else if (direction == WEST)
    {
        view.move(-panBy, 0);
    }
    else if (direction == NORTH_WEST)
    {
        view.move(-panBy, -panBy);
    }

    setView(view);
}

bool Window::isWithinWindowBounds(int x, int y)
{
    if (x < 0 || x >= getSize().x || y < 0 || y >= getSize().y)
    {
        return false;
    }

    return true;
}

void Window::setMouseCursorGrabbed(bool grab)
{
    sf::RenderWindow::setMouseCursorGrabbed(grab);
    _cursorIsGrabbed = grab;
}

void Window::updateWindowSize(const int& scale)
{
    setSize(sf::Vector2u(globals::WINDOW_NATIVE_RESOLUTION_X * globals::scale, globals::WINDOW_NATIVE_RESOLUTION_Y * globals::scale));
}