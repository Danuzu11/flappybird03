#pragma once

#include <memory>

#include <SFML/Graphics.hpp>
#include <src/states/StateMachine.hpp>


class GameModeBase
{
public:
    
    virtual ~GameModeBase() = default;
    virtual bool MoveLogs() = 0;
    virtual bool Stars() = 0;

protected:
    
};