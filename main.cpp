#include <fmt/core.h>
#include <chrono>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "headers/helpers/config.hpp"
#include "headers/MapGenerator.hpp"
#include "headers/helpers/Button.hpp"
#include "headers/Protagonist.hpp"


struct GameData {
    int level;
    std::vector<std::string> levelConfig;
};

// Function to display the welcome page with buttons
void displayWelcomePage(sf::RenderWindow &window) {
    Button start_button(50.f, 375.f, 200.f, 50.f, "Start Game");
    Button change_avatar_button(280.f, 375.f, 200.f, 50.f, "Change Avatar");


    start_button.draw(window);
    change_avatar_button.draw(window);

    if (start_button.isClicked(window)) {
//        MapGenerator mapGenerator(gameData.levelConfig, gameData.level);
//        mapGenerator.generateMap();
        std::cout << "Starting Game with Level " << 2 << "...\n";
    }

    if (change_avatar_button.isClicked(window)) {
//        catchy.changeAvatar();
        std::cout << "Avatar changed!\n";
    }
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

    Protagonist catchy;


    char current_level = 0;
    short level_finish = 0;
    std::chrono::microseconds lag(0);
    std::chrono::steady_clock::time_point previous_time;


    //SFML window menu configuration
    sf::Color background_color = sf::Color(225, 112, 85);
    sf::Event event;
    sf::RenderWindow window(sf::VideoMode(SCREEN_RESIZE * SCREEN_WIDTH, SCREEN_RESIZE * SCREEN_HEIGHT),
                            "Catch Catchy", sf::Style::Close);
    sf::Texture background;
    if (!background.loadFromFile(
            "C:\\Users\\damia\\Desktop\\MAIN\\PJATK\\thirdSemester\\PJC\\platformGame\\assets\\welcome_short.jpg")) {
        fmt::print("Cannot load background");
    }
    sf::Sprite backgroundImage(background);
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
                }
            }

            if (FRAME_DURATION > lag) {
                view.reset(sf::FloatRect(view_x, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
                window.setView(view);
                window.clear(background_color);
                window.draw(backgroundImage);
                displayWelcomePage(window);
                window.display();
            }
        }
    }

    return EXIT_SUCCESS;
}