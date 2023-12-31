#include <fmt/core.h>
#include <chrono>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "headers/config.hpp"
#include "headers/MapGenerator.h"


int main() {
    //starting configuration
    std::vector<std::string> levelConfig = {
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

    int level = 2;

    MapGenerator mapGenerator(levelConfig, level);
    mapGenerator.generateMap();

    char current_level = 0;
    short level_finish = 0;
    std::chrono::microseconds lag(0);
    std::chrono::steady_clock::time_point previous_time;
    //SFML window configuration
    sf::Color background_color = sf::Color(225, 112, 85);
    sf::Event event;
    sf::RenderWindow window(sf::VideoMode(SCREEN_RESIZE * SCREEN_WIDTH, SCREEN_RESIZE * SCREEN_HEIGHT),
                            "Catch Catchy", sf::Style::Close);
    window.setPosition({static_cast<int>(window.getPosition().x), static_cast<int>(window.getPosition().y - 90)});

    sf::View view(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
    previous_time = std::chrono::steady_clock::now();

    //icon load
    auto image = sf::Image{};
    if (!image.loadFromFile(iconRef)) {
        fmt::println("Cannot load icon");
    } else {
        window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
    }

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
                window.display();
            }
        }
    }
    return EXIT_SUCCESS;
}
