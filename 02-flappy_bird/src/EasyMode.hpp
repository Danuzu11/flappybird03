// ClassicMode.hpp

#pragma once

#include <src/GameModeBase.hpp>

class EasyMode : public GameModeBase {
public:
    EasyMode();
    virtual bool MoveLogs() override ;
    virtual bool Stars() override;

};
