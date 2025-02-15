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

bool Log::check_log_collides(const Log& otherLog) const noexcept
{
    return get_collision_rect().intersects(otherLog.get_collision_rect());
}

void Log::update(float _x,float dt) noexcept
{
    x = _x;

    if(movement)
    {
        oscilation_dt += dt;
        float range_oscilation = std::sin(oscilation_dt * oscilation_speed) * oscilation_amplitude;
     
        if (inverted)
        {
            y = initial_position + range_oscilation;

            if(y > initial_position + Settings::LOGS_GAP)
            {
                y = initial_position + Settings::LOGS_GAP;
            }

        }else{
            y = initial_position - range_oscilation;

            if(y < initial_position - Settings::LOGS_GAP)
            {
                y = initial_position - Settings::LOGS_GAP;
            }
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

bool Log::get_collide_log() const noexcept
{
    return was_collide;
}

void Log::set_collide_log(bool _collide) noexcept
{
    was_collide = _collide;
}
