#ifndef CURSORMANAGER_H
#define CURSORMANAGER_H

#include <SFML/Graphics.hpp>

#include "EdgePanDirection.h"

class CursorManager
{
    public:
        static void initialize(sf::RenderWindow& window);

        static void setCursorToDefault();
        static void setCursorToMatchPanDirection(const EdgePanDirection& direction);

    private:
        // Prevent instantiation.
        CursorManager();

        static void initializeCursors();

        static sf::RenderWindow* _window;
        static sf::Cursor _panCursors[9];
};

#endif // CURSORMANAGER_H