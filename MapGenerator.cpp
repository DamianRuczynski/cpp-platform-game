#include "SFML/Graphics.hpp"
#include <vector>
#include <string>
#include <iostream>


#include "headers/MapGenerator.h"


MapGenerator::MapGenerator(const std::vector<std::string> &levelConfig, int level)
        : levelConfig(levelConfig), level(level) {}

void MapGenerator::generateMap() {

    std::cout << "MapGenerator::generateMap() called" << std::endl;
//        // Load background based on the level
//        std::string backgroundFileName = "background_level_" + std::to_string(level) + ".jpg";
//        // Load background image here using SFML
//
//        // Generate map elements based on configuration
//        for (size_t row = 0; row < levelConfig.size(); ++row) {
//            for (size_t col = 0; col < levelConfig[row].length(); ++col) {
//                char symbol = levelConfig[row][col];
//                sf::Vector2f position(col * blockSize, row * blockSize); // Adjust blockSize as needed
//
//                // Generate map elements based on symbols
//                if (symbol == '%') {
//                    generateBlock(position, "brick_texture.jpg"); // Replace with actual brick texture
//                } else if (symbol == '=') {
//                    generateEnemy(position, "enemy_texture.jpg"); // Replace with actual enemy texture
//                } else if (symbol == '^') {
//                    generateBlock(position, "brick_texture.jpg"); // Replace with actual brick texture for floor
//                } else if (symbol == '-') {
//                    generateBlock(position, "block_texture.jpg"); // Replace with actual block texture
//                }
//                // Add more conditions for other symbols as needed
//            }
//        }
}

void MapGenerator::generateBlock(const sf::Vector2f &position, const std::string &textureFile) {
    // Code to generate a block at the specified position with the given texture
    // Use SFML to create and draw a block sprite
}

void MapGenerator::generateEnemy(const sf::Vector2f &position, const std::string &textureFile) {
    // Code to generate an enemy at the specified position with the given texture
    // Use SFML to create and draw an enemy sprite
}

