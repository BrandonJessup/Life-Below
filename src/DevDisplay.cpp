#include "headers/DevDisplay.h"

#include <string>

#include "headers/Global.h"

DevDisplay::DevDisplay()
{
    initializeView();
    loadFont();
    initializeText();
}

void DevDisplay::frameLogic()
{
    // TODO: fade out text
}

void DevDisplay::draw(sf::RenderWindow& window)
{
    window.setView(_view);

    if (_text.getString() != "")
    {
        window.draw(_text);
    }
}

void DevDisplay::scaleChanged(const int& scale)
{
    _text.setString("x" + std::to_string(scale));
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
    _text.setString(_message); // TEMP
    _text.setFillColor(sf::Color(32, 194, 14));
    _text.setCharacterSize(_fontSize);
    _text.setPosition(4, global::WINDOW_NATIVE_RESOLUTION_Y - _fontSize * 1.2);
}