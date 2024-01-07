#pragma once

#include <vector>
#include <memory>
#include "../MapGenerator.hpp"
#include "../enemies/Enemy.hpp"
#include "../Protagonist.hpp"

void convert_sketch(const unsigned char i_current_level, unsigned short &i_level_finish,
                    std::vector<std::shared_ptr<Enemy>> &i_enemies, sf::Color &i_background_color,
                    MapGenerator &mapGenerator, Protagonist &catchy);