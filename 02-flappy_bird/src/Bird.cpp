/*
    ISPPV1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class Bird.
*/

#include <Settings.hpp>
#include <src/Bird.hpp>
#include <cmath>

sf::Clock clock_visible;

Bird::Bird(float _x, float _y, float w, float h) noexcept
    : x{_x}, y{_y}, width{w}, height{h}, vy{0.f}, sprite{Settings::textures["bird"]}
{
    sprite.setPosition(x, y);
}

sf::FloatRect Bird::get_collision_rect() const noexcept
{
    return sf::FloatRect{x, y, width, height};
}

void Bird::jump() noexcept
{
    if (!jumping)
    {
        jumping = true;
    }
}

void Bird::moveL() noexcept
{
    if (!move_l)
    {
        move_l= true;
    }
}

void Bird::moveR() noexcept
{
    if (!move_r)
    {
        move_r= true;
    }
}


void Bird::update(float dt) noexcept
{
    if(stopped)
    {
        return;
    }

    vy += Settings::GRAVITY * dt;

    if (move_r)
    {
        vx += acceleration* dt;
        if(vx > max_speed)
        {
            vx = max_speed;
        }
        move_r = false;
    }
    else if(move_l)
    {
        vx -= acceleration * dt;
        if(vx < -max_speed)
        {
            vx = -max_speed;
        }
        move_l = false;

    }
    else
    {
        if(vx > 0){
            vx -= deceleration * dt;
            if(vx < 0)
            {
                vx = 0;
            }
        }else if (vx < 0)
        {
            vx += deceleration * dt;
            if(vx > 0)
            {
                vx = 0;
            }
        }
        
    }

    if(is_transform()){

        supersaiyan_timer += dt;
        blink_timer += dt;

        if (blink_timer >= blink_duration)
        {
            visible = !visible;
            blink_timer = 0.f;
        }

        if(supersaiyan_timer >= transformation_duration){
            supersayayin = false;
            visible = true;
            Settings::music.setPitch(1.0f);
        }
    }

    if (jumping)
    {
        Settings::sounds["jump"].play();
        vy = -Settings::JUMP_TAKEOFF_SPEED;
        jumping = false;
    }




    y += vy * dt;
    x += vx * dt;
    sprite.setPosition(x, y);
}

void Bird::render(sf::RenderTarget& target) const noexcept
{

    if(!supersayayin || visible){
        target.draw(sprite);
    }

}

//nuevo

void Bird::stop() noexcept
{
    if(stopped)
    {
        stopped = false;
    }else{
        stopped = true;
        vy = 0;
    }
}

void Bird::start() noexcept
{
    stopped = false;
}

void Bird::transform() noexcept
{
    supersayayin = true;
    supersaiyan_timer = 0.f;
    Settings::music.setPitch(1.5f);
}

bool Bird::is_transform() noexcept
{
    return supersayayin;
}