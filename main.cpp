#include <fmt/core.h>
#include <chrono>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "headers/config.hpp"
#include "headers/MapGenerator.hpp"


struct GameData {
    int level;
    std::vector<std::string> levelConfig;
};

// Function to display the welcome page with buttons
void displayWelcomePage(sf::RenderWindow &window) {
    sf::Font font;

    sf::Text welcomeText("Welcome to the Game!", font, 30);
    welcomeText.setPosition(50.f, 50.f);
    welcomeText.setFillColor(sf::Color::Black);

    sf::Text startText("1. Start Game", font, 2000);
    startText.setPosition(50.f, 150.f);
    startText.setFillColor(sf::Color::Black);

    sf::Text avatarText("2. Change Avatar", font, 20);
    avatarText.setPosition(50.f, 200.f);
    avatarText.setFillColor(sf::Color::Black);

    window.draw(welcomeText);
    window.draw(startText);
    window.draw(avatarText);
}

// Function to start the game with given level and level config
void startGame(sf::RenderWindow &window, const GameData &gameData) {
    std::cout << "Starting Game with Level " << gameData.level << "...\n";
}

// Function to change the avatar
void changeAvatar() {
    std::cout << "Avatar changed!\n";
}


int main() {
    //starting configuration
    GameData gameData;
    gameData.level = 2;
    gameData.levelConfig = {
            "                                                                   ",
            "                                                                   ",
            "                                                                   ",
            "                                                                   ",
            "                                                                   ",
            "            %  =*=     %                                           ",
            "                                                                   ",
            "                                           -+                      ",
            "                              ^     ^      ()                      ",
            "=============================================   ===================",
    };

    MapGenerator mapGenerator(gameData.levelConfig, gameData.level);
    mapGenerator.generateMap();

    char current_level = 0;
    short level_finish = 0;
    std::chrono::microseconds lag(0);
    std::chrono::steady_clock::time_point previous_time;
    //SFML window menu configuration
    sf::Color background_color = sf::Color(225, 112, 85);
    sf::Event event;
    sf::RenderWindow window(sf::VideoMode(SCREEN_RESIZE * SCREEN_WIDTH, SCREEN_RESIZE * SCREEN_HEIGHT),
                            "Catch Catchy", sf::Style::Close);
    window.setPosition({static_cast<int>(window.getPosition().x), static_cast<int>(window.getPosition().y - 90)});

    sf::View view(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
    previous_time = std::chrono::steady_clock::now();

    //icon load
    auto image = sf::Image{};
    if (!image.loadFromFile(locationRef + "icon.jpg")) {
        fmt::println("Cannot load icon");
    } else {
        window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
    }
    constexpr std::chrono::microseconds FRAME_DURATION(16667);
    // open window
    while (window.isOpen()) {


        auto delta_time = std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::steady_clock::now() - previous_time);
        lag += delta_time;
        previous_time += delta_time;
        while (FRAME_DURATION <= lag) {
            int view_x;
            lag -= FRAME_DURATION;
            while (window.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::KeyPressed:
                        switch (event.key.code) {
                            case sf::Keyboard::Enter:
                                fmt::println("Enter pressed");
                                break;
                        }
                        break;
                    case sf::Event::MouseButtonPressed:
                        switch (event.mouseButton.button) {
                            case sf::Mouse::Left:
                                fmt::println("Left mouse button pressed");
                                // Check if the mouse click is within the area of the buttons
                                if (sf::Mouse::getPosition(window).x >= 50.f &&
                                    sf::Mouse::getPosition(window).x <= 200.f &&
                                    sf::Mouse::getPosition(window).y >= 150.f &&
                                    sf::Mouse::getPosition(window).y <= 180.f) {
                                    startGame(window, gameData);
                                } else if (sf::Mouse::getPosition(window).x >= 50.f &&
                                           sf::Mouse::getPosition(window).x <= 200.f &&
                                           sf::Mouse::getPosition(window).y >= 200.f &&
                                           sf::Mouse::getPosition(window).y <= 230.f) {
                                    changeAvatar();
                                }
                                break;
                            case sf::Mouse::Right:
                                fmt::println("Right mouse button pressed");
                                break;
                        }
                        break;
                }
            }

            if (FRAME_DURATION > lag) {
                view.reset(sf::FloatRect(view_x, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
                window.setView(view);
                window.clear(background_color);
                displayWelcomePage(window);
                window.display();
            }
        }
    }

    return EXIT_SUCCESS;
}