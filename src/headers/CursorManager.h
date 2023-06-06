#ifndef CURSOR_MANAGER_H
#define CURSOR_MANAGER_H

#include <SFML/Graphics.hpp>

#include "Direction.h"

class CursorManager
{
    public:
        static void initialize(sf::RenderWindow& window);

        static void setCursorToDefault();
        static void setCursorToMatchPanDirection(const Direction& direction);

    private:
        // Prevent instantiation.
        CursorManager();

        static void initializeCursors();

        static sf::RenderWindow* _window;
        static sf::Cursor _panCursors[9];
};

#endif // CURSOR_MANAGER_H