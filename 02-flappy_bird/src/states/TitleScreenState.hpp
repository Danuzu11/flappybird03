/*
    ISPPV1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class TitleScreenState.
*/

#pragma once

#include <src/World.hpp>
#include <src/states/BaseState.hpp>
#include <src/GameModeBase.hpp>
#include <src/EasyMode.hpp>
#include <src/HardMode.hpp>

class TitleScreenState: public BaseState
{
public:
    TitleScreenState(StateMachine* sm) noexcept;

    void handle_inputs(const sf::Event& event) noexcept override;

    void update(float dt) noexcept override;

    void render(sf::RenderTarget& target) const noexcept override;

    std::shared_ptr<GameModeBase> getSelectMode() noexcept;

private:
    World world;
    int selected_mode = 0;
    bool is_hard_mode = false;
};
