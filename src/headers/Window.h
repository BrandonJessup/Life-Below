#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>

class Window : public sf::RenderWindow
{
    public:
        Window();
        void create(const int& scale);
        void updateWindowSize(const int& scale); // TEMP: Delete and change everything to use global::WINDOW_SCALE after we settle on which scale to use
        bool mouseInEdgePanArea(sf::Event::MouseMoveEvent& mousePosition);
        void setMouseCursorGrabbed(const bool& grab);
        bool cursorGrabbed();
        bool isWithinBounds(const sf::Vector2i& position);

    private:
        bool _cursorIsGrabbed;
};

#endif // WINDOW_H