/*
    ISPPV1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class Log.
*/

#include <Settings.hpp>
#include <src/Log.hpp>
#include <cmath>

Log::Log(float _x, float _y, bool _movement , bool _inverted) noexcept
    : x{_x}, y{_y},inverted{_inverted}, sprite{Settings::textures["Log"]},
    initial_position{_y},
    movement{_movement}
{
    if (inverted)
    {
        sprite.rotate(180.f);
    }
}

sf::FloatRect Log::get_collision_rect() const noexcept
{
    if (!inverted)
    {
        return sf::FloatRect{x, y, Settings::LOG_WIDTH, Settings::LOG_HEIGHT};
    }

    return sf::FloatRect{x - Settings::LOG_WIDTH, y - Settings::LOG_HEIGHT, Settings::LOG_WIDTH, Settings::LOG_HEIGHT};
}

void Log::update(float _x,float dt) noexcept
{
    x = _x;

    // nuevo
    if(movement)
    {
        oscilation_dt += dt;
        float range_oscilation = std::sin(oscilation_dt * oscilation_speed) * oscilation_amplitude;
     
        if (inverted)
        {
            y = initial_position + range_oscilation;
        }else{
            y = initial_position - range_oscilation;
        }
    }

    if (inverted)
    {
        x += Settings::LOG_WIDTH;
    }

    sprite.setPosition(x, y);
}

void Log::render(sf::RenderTarget& target) const noexcept
{
    target.draw(sprite);
}
