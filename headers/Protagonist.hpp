//#pragma once
//
//#include <vector>
//#include "SFML/Graphics/Sprite.hpp"
//#include "SFML/Graphics/Texture.hpp"
//#include "SFML/Graphics/RenderWindow.hpp"
//#include "MapGenerator.hpp"
//
//class Protagonist {
//    bool crouching;
//    bool dead;
//    bool flipped;
//    bool on_ground;
//
//    //Oh, this is a funny story!
//    //So I was working on level 1-2 when I discovered a simple bug.
//    //The bug was that when 2 Goombas stand SUPER close to each other and Mario jumps on them, one goomba dies and the other kills Mario.
//    //This was happening because the first Goomba was setting Mario's vertical speed below 0 after dying.
//    //Then the second Goomba checked the collision with Mario and saw that Mario wasn't squishing anymore and instead was going upwards.
//    //So he was killing Mario.
//    //And by adding this variable, I fixed the bug.
//    //Hehe.
//    float enemy_bounce_speed;
//    float horizontal_speed;
//    float vertical_speed;
//    float x;
//    float y;
//
//    //The longer we press the jump button, the higher Mario jumps. And we use this variable for that.
//    unsigned char jump_timer;
//    //I was thinking about adding Fire Mario.
//    //But I figured that it's gonna be too much work and I'm too lazy for that.
//    //Maybe in the next part?
//    unsigned char powerup_state;
//
//    unsigned short death_timer;
//    unsigned short growth_timer;
//    unsigned short invincible_timer;
//
//    std::vector<Mushroom> mushrooms;
//
//    sf::Sprite sprite;
//
//    sf::Texture texture;
//
//public:
//    Mario();
//
//    bool get_dead() const;
//
//    float get_vertical_speed() const;
//
//    float get_x() const;
//
//    void die(const bool i_instant_death);
//
//    void draw(sf::RenderWindow &i_window);
//
//    void draw_mushrooms(const unsigned i_view_x, sf::RenderWindow &i_window);
//
//    void reset();
//
//    void changeAvatar();
//
//    void set_position(const float i_x, const float i_y);
//
//    void set_vertical_speed(const float i_value);
//
//    void update(const unsigned i_view_x, MapGenerator &i_map_generator);
//
//    sf::FloatRect get_hit_box() const;
//};
//

#pragma once

#include <SFML/Graphics.hpp>

class Protagonist {
public:
    Protagonist();

    void update();

    void draw(sf::RenderWindow &i_window);

    void changeAvatar();

private:
    float x, y;
    float horizontal_speed, vertical_speed;
    bool on_ground;

    void handleMovement();

    void handleJump();

    sf::FloatRect getHitBox() const;

    sf::Texture texture;
    sf::Sprite sprite;
};

