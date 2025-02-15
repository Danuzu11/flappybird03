/*
    ISPPV1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class Log.
*/

#pragma once

#include <SFML/Graphics.hpp>

class Log
{
public:
    Log(float _x, float _y,bool movement, bool inverted) noexcept;

    sf::FloatRect get_collision_rect() const noexcept;

    void update(float _x,float dt) noexcept;

    void render(sf::RenderTarget& target) const noexcept;

    bool check_log_collides(const Log& otherLog) const noexcept;

    bool get_collide_log() const noexcept;

    void set_collide_log(bool _collide) noexcept;

private:
    float x;
    float y;
    bool inverted;
    sf::Sprite sprite;
    float oscilation_dt{0.f};
    float oscilation_speed{2.f};
    float oscilation_amplitude{48.f};
    float initial_position{0.f};
    bool movement{false};
    bool was_collide{true};
};