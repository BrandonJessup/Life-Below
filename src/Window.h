#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>

class Window : public sf::RenderWindow
{
    public:
        Window();
        void onResize();
        void handleEvent(sf::Event& event);
        void frameLogic();

    private:
        enum EdgePanDirection
        {
            NONE = 0,
            NORTH,
            NORTH_EAST,
            EAST,
            SOUTH_EAST,
            SOUTH,
            SOUTH_WEST,
            WEST,
            NORTH_WEST
        };

        void initializeCursors();
        bool mouseInEdgePanArea(sf::Event::MouseMoveEvent mousePosition);
        EdgePanDirection determineEdgePanDirection(sf::Event::MouseMoveEvent mousePosition); 
        void setCursorToDefault();
        void setCursorToMatchPanDirection(EdgePanDirection direction);
        void panView(EdgePanDirection direction);
        bool isWithinWindowBounds(int x, int y);
        void setMouseCursorGrabbed(bool grab);
        void updateWindowSize(const int& scale);

        EdgePanDirection _panDirection;
        sf::Clock _panClock;
        sf::Cursor _panCursors[9];
        bool _cursorIsGrabbed;
        int _scale; // TEMP: Delete and change everything to use global::WINDOW_SCALE after we settle on which scale to use
};

#endif // WINDOW_H