/*
    ISPPV1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class World.
*/

#pragma once

#include <list>
#include <memory>
#include <random>

#include <SFML/Graphics.hpp>

#include <src/Factory.hpp>
#include <src/LogPair.hpp>
#include <src/Power.hpp>
#include <src/GameModeBase.hpp>
#include <src/HardMode.hpp>
#include <src/EasyMode.hpp>

class GameModeBase;
class HardMode;

class World
{
public:
    World(bool _generate_logs = false,std::shared_ptr<GameModeBase> game_mode = nullptr) noexcept;

    World(const World& world) = delete;

    World& operator = (World) = delete;

    void reset(bool _generate_logs,std::shared_ptr<GameModeBase> _game_mode) noexcept;

    bool collides(const sf::FloatRect& rect) const noexcept;

    bool update_scored(const sf::FloatRect& rect) noexcept;

    void update(float dt) noexcept;

    void render(sf::RenderTarget& target) const noexcept;

    
    void stop() noexcept;

    void start() noexcept;

    void set_global_score(int local_score);

    int get_global_score();

    void change_mode();

    bool collides_stars(const sf::FloatRect& rect) noexcept;


private:
    bool generate_logs;

    sf::Sprite background;
    sf::Sprite ground;

    float background_x{0.f};
    float ground_x{0.f};
    float time_spawn{0.f};

    Factory<LogPair> log_factory;

    std::list<std::shared_ptr<LogPair>> logs;

    std::mt19937 rng;

    float logs_spawn_timer{0.f};
    float last_log_y{0.f};
    float last_log_x{0.f};

    bool stopped{false};
    int global_score{0};
    bool hard_mode{false};

    Factory<Power> powers_factory;
    std::list<std::shared_ptr<Power>> power;
    std::shared_ptr<GameModeBase> game_mode;
};
