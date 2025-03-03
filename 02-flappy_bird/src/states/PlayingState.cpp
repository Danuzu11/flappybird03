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
#include <src/states/PlayingState.hpp>

PlayingState::PlayingState(StateMachine* sm,std::shared_ptr<GameModeBase> mode) noexcept
    : BaseState{sm},Gmode{mode}
{

}

void PlayingState::enter(std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird) noexcept
{
    world = _world;
    world->start();
    world->reset(true,Gmode);
    
    if (_bird == nullptr)
    {
        bird = std::make_shared<Bird>(
            Settings::VIRTUAL_WIDTH / 2 - Settings::BIRD_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 2 - Settings::BIRD_HEIGHT / 2,
            Settings::BIRD_WIDTH, Settings::BIRD_HEIGHT
        );
    }
    else
    {
        bird = _bird;
  
        bird->start();
    }

    score = world->get_global_score();

}

void PlayingState::handle_inputs(const sf::Event& event) noexcept
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        bird->jump();
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
    {
        world->set_global_score(score);
        afterpause = true;
        state_machine->change_state("pause",world,bird,Gmode);
    }

    if(dynamic_cast<HardMode*>(Gmode.get())){

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
        {
        bird->moveR();
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
        {
        bird->moveL();
        }

    }





}

void PlayingState::update(float dt) noexcept
{
    bird->update(dt);
    world->update(dt);

    

    //si no esta transformado funionan las colisiones
    if(!bird->is_transform())
    {
        if (world->collides(bird->get_collision_rect()))
        {
            Settings::sounds["explosion"].play();
            Settings::sounds["hurt"].play();
            state_machine->change_state("count_down",nullptr,nullptr,Gmode);
        }
    
    }

    if (world->update_scored(bird->get_collision_rect()))
    {
        ++score;
        Settings::sounds["score"].play();
    }


    //Colision estrellas
    if (world->collides_stars(bird->get_collision_rect()))
    {
        Settings::sounds["explosion"].play();
        bird->transform();
    }
}

void PlayingState::render(sf::RenderTarget& target) const noexcept
{
    world->render(target);
    bird->render(target);
    render_text(target, 20, 10, "Score: " + std::to_string(score), Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White);
}