/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - SimulationState.hpp
InversePalindrome.com
*/


#pragma once

#include "State.hpp"


class SimulationState : public State
{
public:
	SimulationState(StateMachine* stateMachine, StateData* stateData);

	virtual void handleEvent() override;
	virtual void update() override;
	virtual void draw() override;
};