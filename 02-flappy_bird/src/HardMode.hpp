#pragma once

#include <src/GameModeBase.hpp>

class HardMode: public GameModeBase 
{
public:
    HardMode();
    virtual bool MoveLogs() override;
    virtual bool Stars() override;

};
