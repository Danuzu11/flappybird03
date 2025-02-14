/*
    ISPPV1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class World.
*/

#include <Settings.hpp>
#include <src/World.hpp>

World::World(bool _generate_logs,std::shared_ptr<GameModeBase> _game_mode) noexcept
    : generate_logs{_generate_logs}, background{Settings::textures["background"]}, ground{Settings::textures["ground"]},
    power{},logs{}, rng{std::default_random_engine{}()}, game_mode{_game_mode}
{
    ground.setPosition(0, Settings::VIRTUAL_HEIGHT - Settings::GROUND_HEIGHT);
    std::uniform_int_distribution<int> dist(0, 80);
    last_log_y = -Settings::LOG_HEIGHT + dist(rng) + 20;
}

void World::reset(bool _generate_logs,std::shared_ptr<GameModeBase> _game_mode) noexcept
{
    generate_logs = _generate_logs;
    game_mode = _game_mode;
}

bool World::collides(const sf::FloatRect& rect) const noexcept
{
    if (rect.top + rect.height >= Settings::VIRTUAL_HEIGHT)
    {
        return true;
    }
    
    for (auto log_pair: logs)
    {
        if (log_pair->collides(rect))
        {
            return true;
        }
    }

    return false;
}

bool World::update_scored(const sf::FloatRect& rect) noexcept
{
    for (auto log_pair: logs)
    {
        if (log_pair->update_scored(rect))
        {
            return true;
        }
    }

    return false;
}

void World::update(float dt) noexcept
{
    if(stopped)
    {
        return;
    }

    if (generate_logs)
    {
        logs_spawn_timer += dt;

        if (logs_spawn_timer >= Settings::TIME_TO_SPAWN_LOGS)
        {
            logs_spawn_timer = 0.f;

            std::uniform_int_distribution<int> dist{-20, 20};
            float y = std::max(-Settings::LOG_HEIGHT + 10, std::min(last_log_y + dist(rng), Settings::VIRTUAL_HEIGHT + 90 - Settings::LOG_HEIGHT));

            last_log_y = y;

            //nuevo
            if(game_mode->MoveLogs()){
                float random_log_movement = std::rand() % 2;

                if(random_log_movement == 1){
                    logs.push_back(log_factory.create(Settings::VIRTUAL_WIDTH, y));
                }else{
                    logs.push_back(log_factory.create(Settings::VIRTUAL_WIDTH, y, false));
                }
            }else{
                logs.push_back(log_factory.create(Settings::VIRTUAL_WIDTH, y, false));
            }

            if(game_mode->Stars())
            {

                 std::bernoulli_distribution star_prop{0.4};

                 if(star_prop(rng))
                 {
                    power.push_back(powers_factory.create(Settings::VIRTUAL_WIDTH + 100, Settings::VIRTUAL_HEIGHT/2.5, true));
                 } 
                 

            }

           
            
            
        }
    }

    background_x += -Settings::BACK_SCROLL_SPEED * dt;

    if (background_x <= -Settings::BACKGROUND_LOOPING_POINT)
    {
        background_x = 0;
    }

    background.setPosition(background_x, 0);

    ground_x += -Settings::MAIN_SCROLL_SPEED * dt;

    if (ground_x <= -Settings::VIRTUAL_WIDTH)
    {
        ground_x = 0;
    }

    ground.setPosition(ground_x, Settings::VIRTUAL_HEIGHT - Settings::GROUND_HEIGHT);

    for (auto it = logs.begin(); it != logs.end(); )
    {
        if ((*it)->is_out_of_game())
        {
            auto log_pair = *it;
            log_factory.remove(log_pair);
            it = logs.erase(it);
            
        }
        else
        {
            (*it)->update(dt);
            ++it;
        }
    }

    for (auto it = power.begin(); it != power.end(); )
    {
        if ((*it)->is_out_of_game())
        {
            auto power_pair = *it;
            powers_factory.remove(power_pair);
            it = power.erase(it);
            
        }
        else
        {
            (*it)->update(dt);
            ++it;
        }
    }
}

void World::render(sf::RenderTarget& target) const noexcept
{
    target.draw(background);

    for (const auto& log_pair: logs)
    {
        log_pair->render(target);

    }

    for (const auto& power_pair: power)
    {
        power_pair->render(target);

    }

    target.draw(ground);
}

//nuevo

void World::stop() noexcept
{
    if(stopped)
    {
        stopped = false;
        float background_x = 0.f;
        float ground_x = 0.f;
    }else
    {
        stopped = true;
    }
}

void World::start() noexcept
{
    stopped = false;
}

void World::set_global_score(int local_score) 
{
    global_score = local_score;
}

int World::get_global_score() 
{
    return global_score;
}

//nuevo
void World::change_mode() 
{
    if(hard_mode){
        hard_mode = false;
    }else{
        hard_mode = true;
    }
}

bool World::collides_stars(const sf::FloatRect& rect) noexcept
{
 
    for (auto it = power.begin(); it != power.end(); )
    {
        if ((*it)->collides(rect))
        {
            auto power_pair = *it;
            powers_factory.remove(power_pair); 
            it = power.erase(it);  
            return true;
        }
        else
        {
            ++it;
        }
    }

    return false;
}