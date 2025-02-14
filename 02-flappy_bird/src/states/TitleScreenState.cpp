/*
    ISPPV1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class TitleScreenState.
*/

#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/TitleScreenState.hpp>

TitleScreenState::TitleScreenState(StateMachine* sm) noexcept
    : BaseState{sm}, world{}
{

}

// void TitleScreenState::handle_inputs(const sf::Event& event) noexcept
// {
//     if (event.key.code == sf::Keyboard::Return)
//     {
//         state_machine->change_state("count_down");
//     }
// }

void TitleScreenState::handle_inputs(const sf::Event& event) noexcept
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down)
        {
            selected_mode = (selected_mode == 0) ? 1 : 0; // Alterna entre opciones
            is_hard_mode = !is_hard_mode; // Alterna entre Normal y Hard Mode

        }
        else if (event.key.code == sf::Keyboard::Return)
        {
            
                state_machine->change_state("count_down",nullptr,nullptr,getSelectMode());
            
        }
    }
}

void TitleScreenState::update(float dt) noexcept
{
    world.update(dt);
}

// void TitleScreenState::render(sf::RenderTarget& target) const noexcept 
// {
//     world.render(target);
//     render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 3, "Flappy Bird", Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White, true);
//     render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 3, "Press Enter to start", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);
// }

void TitleScreenState::render(sf::RenderTarget& target) const noexcept 
{
    world.render(target);

    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 3, 
                "Flappy Bird", Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White, true);

    sf::Color start_color = (selected_mode == 0) ? sf::Color::Yellow : sf::Color::White;
    sf::Color mode_color = (selected_mode == 1) ? sf::Color::Yellow : sf::Color::White;
    
    std::string mode_text = is_hard_mode ? "Mode: HARD" : "Mode: NORMAL";

    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 3, 
                "Start Game", Settings::MEDIUM_TEXT_SIZE, "font", start_color, true);

    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 3 + 40, 
                mode_text, Settings::MEDIUM_TEXT_SIZE, "font", mode_color, true);
    // render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 3 + 40, 
    //             std::to_string(selected_mode), Settings::MEDIUM_TEXT_SIZE, "font", mode_color, true);
}

std::shared_ptr<GameModeBase> TitleScreenState::getSelectMode() noexcept
{

    if (is_hard_mode)
        return std::make_unique<HardMode>();
    else
        return std::make_unique<EasyMode>();

   



} 