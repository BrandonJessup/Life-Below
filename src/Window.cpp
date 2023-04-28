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
}

void Window::updateWindowSize(const int& scale)
{
    setSize(sf::Vector2u(global::WINDOW_NATIVE_RESOLUTION_X * scale, global::WINDOW_NATIVE_RESOLUTION_Y * scale));
}