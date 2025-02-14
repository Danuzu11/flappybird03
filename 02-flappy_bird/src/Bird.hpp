/*
    ISPPV1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class Bird.
*/

#pragma once

#include <SFML/Graphics.hpp>

class Bird
{
public:
    Bird(float _x, float _y, float w, float h) noexcept;

    Bird(const Bird&) = delete;

    Bird& operator = (Bird) = delete;

    sf::FloatRect get_collision_rect() const noexcept;

    void jump() noexcept;
    
    void moveL() noexcept;

    void moveR() noexcept;

    void update(float dt) noexcept;

    void render(sf::RenderTarget& target) const noexcept;

    //Nuevo
    void stop() noexcept;

    void start() noexcept;

    void transform() noexcept;

    bool is_transform() noexcept;

private:
    float x;
    float y;
    float width;
    float height;
    float vy;
    float vx;
    sf::Sprite sprite;
    bool jumping{false};
    bool move_l{false};

    bool move_r{false};

    //Nuevo
    bool stopped{false};
    bool supersayayin{false};
    float supersaiyan_timer{0.f};
    float transformation_duration{5.0f};
    bool visible = false;
    float blink_timer{0.f};
    float blink_duration{0.1f};
};
