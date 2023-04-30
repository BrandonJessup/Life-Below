#include "headers/DevDisplay.h"

#include <string>

#include "headers/Global.h"

DevDisplay::DevDisplay()
{
    initializeView();
    loadFont();
    _textColor = sf::Color(32, 194, 14, 255);
    initializeText();

    changeState(HIDDEN);
}

void DevDisplay::frameLogic()
{
    tickPersistClock();
    tickFadeClock();
}

void DevDisplay::draw(sf::RenderWindow& window)
{
    window.setView(_view);

    if (_activeState != HIDDEN)
    {
        window.draw(_text);
    }
}

void DevDisplay::scaleChanged(const int& scale)
{
    _text.setString("x" + std::to_string(scale));
    changeState(FULLY_VISIBLE);
}

void DevDisplay::initializeView()
{
    _view.setSize(global::WINDOW_NATIVE_RESOLUTION_X, global::WINDOW_NATIVE_RESOLUTION_Y);
    _view.setCenter(global::WINDOW_NATIVE_RESOLUTION_X / 2, global::WINDOW_NATIVE_RESOLUTION_Y / 2);
}

void DevDisplay::loadFont()
{
    _fontSize = 16;
    _font.loadFromFile("assets/runescape_uf(16px).ttf");
    sf::Texture& texture = const_cast<sf::Texture&>(_font.getTexture(_fontSize));
    texture.setSmooth(false);
}

void DevDisplay::initializeText()
{
    _text.setFont(_font);
    _text.setFillColor(_textColor);
    _text.setCharacterSize(_fontSize);
    _text.setPosition(4, global::WINDOW_NATIVE_RESOLUTION_Y - _fontSize * 1.2);
}

void DevDisplay::changeState(const TextStates& state)
{
    _activeState = state;

    if (state == HIDDEN)
    {
        setTextOpacity(0);
    }
    else if (state == FULLY_VISIBLE)
    {
        _persistClock.restart();
        setTextOpacity(255);
    }
    else if (state == FADING)
    {
        _fadeClock.restart();
    }
}

void DevDisplay::tickPersistClock()
{
    if (_activeState == FULLY_VISIBLE)
    {
        sf::Time elapsed = _persistClock.getElapsedTime();
        if (elapsed.asMilliseconds() > global::DEV_TEXT_PERSIST_DURATION)
        {
            _persistRemainder = elapsed.asMilliseconds() - global::DEV_TEXT_PERSIST_DURATION;

            changeState(FADING);
        }
    }
}

void DevDisplay::tickFadeClock()
{
    if (_activeState == FADING)
    {
        sf::Time elapsed = _fadeClock.getElapsedTime();
        if (elapsed.asMilliseconds() +  _persistRemainder < global::DEV_TEXT_FADE_DURATION)
        {
            float percentageTimePassed = (elapsed.asMilliseconds() +  _persistRemainder) / (float) global::DEV_TEXT_FADE_DURATION;
            int newOpacity = 255 - (255 * percentageTimePassed);
            setTextOpacity(newOpacity);
        }
        else
        {
            changeState(HIDDEN);
        }
    }
}

void DevDisplay::setTextOpacity(const int& opacity)
{
    _textColor.a = opacity;
    _text.setFillColor(_textColor);
}