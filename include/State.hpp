/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - State.hpp
InversePalindrome.com
*/


#pragma once

#include "StateData.hpp"

#include <IrrlichtDevice.h>


class StateMachine;

class State
{
public:
	State(StateMachine* stateMachine, StateData* stateData);

	virtual void handleEvent() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

protected:
	StateMachine* stateMachine;
	StateData* stateData;
};