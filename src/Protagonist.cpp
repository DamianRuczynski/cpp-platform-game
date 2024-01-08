

#include <iostream>
#include "../headers/Protagonist.hpp"

Protagonist::Protagonist() : x(0), y(0), horizontal_speed(0), vertical_speed(0), on_ground(false) {
    // Load texture and set it to the sprite
    texture.loadFromFile("path/to/your/image.png");
    sprite.setTexture(texture);
}

void Protagonist::update() {
    handleMovement();
    handleJump();
}

void Protagonist::draw(sf::RenderWindow &i_window) {
    sprite.setPosition(x, y);
    i_window.draw(sprite);
}

void Protagonist::handleMovement() {
    // Basic left and right movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        horizontal_speed = 5.0f; // Adjust speed as needed
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        horizontal_speed = -5.0f; // Adjust speed as needed
    } else {
        horizontal_speed = 0.0f;
    }

    // Update the position based on horizontal speed
    x += horizontal_speed;
}

void Protagonist::handleJump() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && on_ground) {
        // Apply an upward force when the jump key is pressed and the character is on the ground
        vertical_speed = -10.0f; // Adjust jump height as needed
        on_ground = false; // Assuming the character is in the air after jumping
    }

    // Apply gravity to bring the character back down
    vertical_speed += 0.5f; // Adjust gravity as needed

    // Update the position based on vertical speed
    y += vertical_speed;
}

sf::FloatRect Protagonist::getHitBox() const {
    return sf::FloatRect(x, y, sprite.getLocalBounds().width, sprite.getLocalBounds().height);
}

void Protagonist::changeAvatar() {

    std::cout << "Avatar changed" << std::endl;

}
