/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - PauseState.hpp
InversePalindrome.com
*/


#pragma once

#include "State.hpp"


class PauseState : public State
{
public:
    PauseState(StateMachine* stateMachine, StateData* stateData);

    virtual void handleEvent() override;
    virtual void update(irr::f32 deltaTime) override;
    virtual void draw() override;

    virtual bool isTransparent() override;
};