#ifndef MAP_GENERATOR_H
#define MAP_GENERATOR_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class MapGenerator {
public:
    MapGenerator(const std::vector<std::string> &levelConfig, int level);

    void generateMap();

private:
    std::vector<std::string> levelConfig;
    int level;
    const int blockSize = 32; // Adjust the block size as needed

    void generateBlock(const sf::Vector2f &position, const std::string &textureFile);

    void generateEnemy(const sf::Vector2f &position, const std::string &textureFile);
};

#endif // MAP_GENERATOR_H
