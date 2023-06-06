#ifndef DEV_DISPLAY_H
#define DEV_DISPLAY_H

#include <string>

#include <SFML/Graphics.hpp>

class DevDisplay
{
    public:
        DevDisplay();
        void frameLogic();
        void draw(sf::RenderWindow& window);
        void showMessage(const std::string& message);

    private:
        enum TextStates
        {
            HIDDEN,
            FULLY_VISIBLE,
            FADING
        };

        void initializeView();
        void loadFont();
        void initializeText();

        void changeState(const TextStates& state);
        void tickPersistClock();
        void tickFadeClock();
        void setTextOpacity(const int& opacity);

        TextStates _activeState;
        sf::View _view;
        sf::Font _font;
        int _fontSize;
        sf::Text _text;
        sf::Clock _persistClock;
        sf::Clock _fadeClock;
        int _persistRemainder;
        sf::Color _textColor;
};

#endif // DEV_DISPLAY_H