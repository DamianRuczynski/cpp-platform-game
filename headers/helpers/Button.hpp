#pragma once

#include <SFML/Graphics.hpp>

class Button {
public:
    Button(float x, float y, float width, float height, const std::string &text);

    void draw(sf::RenderWindow &window);

    bool isMouseOver(sf::RenderWindow &window);

    bool isClicked(sf::RenderWindow &window);

private:
    sf::RectangleShape shape;
    sf::Text buttonText;
    sf::Font font;
};
