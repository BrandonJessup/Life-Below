#include "headers/Window.h"

#include <SFML/Graphics.hpp>

#include "headers/Global.h"

Window::Window()
{
}

void Window::create(const int& scale)
{
    sf::RenderWindow::create(sf::VideoMode(global::WINDOW_NATIVE_RESOLUTION_X * scale, global::WINDOW_NATIVE_RESOLUTION_Y * scale), "Life Below", sf::Style::Close);
    setFramerateLimit(120);

    setMouseCursorGrabbed(true);
}

void Window::updateWindowSize(const int& scale)
{
    setSize(sf::Vector2u(global::WINDOW_NATIVE_RESOLUTION_X * scale, global::WINDOW_NATIVE_RESOLUTION_Y * scale));
}

bool Window::mouseInEdgePanArea(sf::Event::MouseMoveEvent& mousePosition)
{
    sf::Vector2u windowSize = getSize();
    if (
        mousePosition.x < global::EDGE_PAN_REGION_THICKNESS
        || mousePosition.x > windowSize.x - global::EDGE_PAN_REGION_THICKNESS - 1
        || mousePosition.y < global::EDGE_PAN_REGION_THICKNESS
        || mousePosition.y > windowSize.y - global::EDGE_PAN_REGION_THICKNESS - 1
    )
    {
        return true;
    }
    
    return false;
}

void Window::setMouseCursorGrabbed(const bool& grab)
{
    sf::RenderWindow::setMouseCursorGrabbed(grab);
    _cursorIsGrabbed = grab;
}

bool Window::cursorGrabbed()
{
    return _cursorIsGrabbed;
}

bool Window::isWithinBounds(const sf::Vector2i& position)
{
    if (position.x < 0 || position.x >= getSize().x || position.y < 0 || position.y >= getSize().y)
    {
        return false;
    }

    return true;
}