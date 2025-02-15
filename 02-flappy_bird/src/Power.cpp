/*
    ISPPV1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class Log.
*/

#include <Settings.hpp>
#include <src/Power.hpp>
#include <cmath>

Power::Power(float _x, float _y, bool _movement ) noexcept
    : x{_x}, y{_y}, sprite{Settings::textures["star"]},
    initial_position{_y},
    movement{_movement}
{
    sprite.setScale(1, 1);
    sprite.setPosition(x, y);
}

sf::FloatRect Power::get_collision_rect() const noexcept
{
    return sf::FloatRect{x, y, 10, 20};
}

bool Power::collides(const sf::FloatRect& rect) const noexcept
{
    return get_collision_rect().intersects(rect);
}

void Power::update(float dt) noexcept
{
    x += -Settings::MAIN_SCROLL_SPEED * dt;

    if(movement)
    {
        oscilation_dt += dt;
        float range_oscilation = std::sin(oscilation_dt * oscilation_speed) * oscilation_amplitude;
     
        y = initial_position + range_oscilation;

    }

    sprite.setPosition(x, y);
}

void Power::render(sf::RenderTarget& target) const noexcept
{
    target.draw(sprite);
}

bool Power::is_out_of_game() const noexcept
{
    return x < -Settings::LOG_WIDTH;
}

void Power::reset(float _x, float _y) noexcept
{
    x = _x;
    y = _y;
    initial_position = _y;
}