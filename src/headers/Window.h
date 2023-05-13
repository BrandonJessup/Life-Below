#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>

class Window : public sf::RenderWindow
{
    public:
        Window();
        void create();
        bool mouseInEdgePanArea(sf::Event::MouseMoveEvent& mousePosition);
        void setMouseCursorGrabbed(const bool& grab);
        bool cursorGrabbed();
        bool isWithinBounds(const sf::Vector2i& position);

    private:
        bool _cursorIsGrabbed;
};

#endif // WINDOW_H