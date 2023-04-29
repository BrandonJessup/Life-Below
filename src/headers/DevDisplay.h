#ifndef DEVDISPLAY_H
#define DEVDISPLAY_H

#include <string>

#include <SFML/Graphics.hpp>

class DevDisplay
{
    public:
        DevDisplay();
        void frameLogic();
        void draw(sf::RenderWindow& window);
        void scaleChanged(const int& scale);

    private:
        void initializeView();
        void loadFont();
        void initializeText();

        sf::View _view;
        sf::Font _font;
        int _fontSize;
        sf::Text _text;
        std::string _message;
};

#endif // DEVDISPLAY_H