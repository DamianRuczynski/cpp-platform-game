#include "../../headers/helpers/Button.hpp"
#include <iostream>

Button::Button(float x, float y, float width, float height, const std::string &text) {
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(width, height));
    sf::Color button_color = sf::Color(225, 112, 85);
    shape.setFillColor(button_color);

    if (!font.loadFromFile(
            "C:\\Users\\damia\\Desktop\\MAIN\\PJATK\\thirdSemester\\PJC\\platformGame\\assets\\fonts\\font.ttf")) {
        std::cerr << "Cannot load font\n";
    }

    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(22);
    buttonText.setFillColor(sf::Color::Black);
    buttonText.setPosition(x + (width - buttonText.getLocalBounds().width) / 2,
                           y + (height - buttonText.getLocalBounds().height) / 2);
}

void Button::draw(sf::RenderWindow &window) {
    window.draw(shape);
    window.draw(buttonText);
}

bool Button::isMouseOver(sf::RenderWindow &window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::FloatRect buttonBounds = shape.getGlobalBounds();
    return buttonBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
}

bool Button::isClicked(sf::RenderWindow &window) {
    return isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}
