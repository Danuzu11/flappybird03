/*
    ISPPV1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class LogPair.
*/

#include <Settings.hpp>
#include <src/LogPair.hpp>

LogPair::LogPair(float _x, float _y, bool _moving) noexcept
    : x{_x}, y{_y},
      top{x, y + Settings::LOG_HEIGHT,_moving, true},
      bottom{x, y + Settings::LOGS_GAP + Settings::LOG_HEIGHT,_moving, false}
{

}

bool LogPair::collides(const sf::FloatRect& rect) const noexcept
{
    return top.get_collision_rect().intersects(rect) || bottom.get_collision_rect().intersects(rect);
}


void LogPair::update(float dt) noexcept
{
    x += -Settings::MAIN_SCROLL_SPEED * dt;

    top.update(x,dt);
    bottom.update(x,dt);

    if(top.get_collision_rect().intersects(bottom.get_collision_rect()))
    {
        if(!top.get_collide_log())
        {
            Settings::sounds["woodcollide"].play();
            top.set_collide_log(true);
        }
    }else{
        top.set_collide_log(false);
    }
}

void LogPair::render(sf::RenderTarget& target) const noexcept
{
    top.render(target);
    bottom.render(target);
}

bool LogPair::is_out_of_game() const noexcept
{
    return x < -Settings::LOG_WIDTH;
}

bool LogPair::update_scored(const sf::FloatRect& rect) noexcept
{
    if (scored)
    {
        return false;
    }

    if (rect.left > x + Settings::LOG_WIDTH)
    {
        scored = true;
        return true;
    }

    return false;
}

void LogPair::reset(float _x, float _y) noexcept
{
    x = _x;
    y = _y;
    scored = false;
}