/*
    ISPPV1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class Log.
*/

#pragma once

#include <SFML/Graphics.hpp>

class Power
{
public:
    Power(float _x, float _y, bool _movement) noexcept;

    sf::FloatRect get_collision_rect() const noexcept;

    void update(float dt) noexcept;

    void render(sf::RenderTarget& target) const noexcept;

    bool is_out_of_game() const noexcept;

    void reset(float _x, float _y) noexcept;

    bool collides(const sf::FloatRect& rect) const noexcept;

private:
    float x;
    float y;
    float width;
    float height;
    sf::Sprite sprite;


    float oscilation_dt{0.f};
    float oscilation_speed{2.f};
    float oscilation_amplitude{40.f};
    float initial_position{0.f};
    bool movement{false};
};