/*
    ISPPV1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class PlayingBaseState.
*/

#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/PauseState.hpp>

PauseState::PauseState(StateMachine* sm,std::shared_ptr<GameModeBase> mode) noexcept
    : BaseState{sm},mode{mode}
{

}

void PauseState::enter(std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird) noexcept
{
    world = _world;
    bird = _bird;
    world->stop();
    bird->stop();
}

void PauseState::handle_inputs(const sf::Event& event) noexcept
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
    {
        state_machine->change_state("playing",world,bird,mode);
    }
}

void PauseState::update(float dt) noexcept
{
    // There is no updates in pause state
}

void PauseState::render(sf::RenderTarget& target) const noexcept
{
    world->render(target);
    bird->render(target);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 3, "PAUSE ", Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White,true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 3, "Press 'P' to continue.... ", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White,true);
}