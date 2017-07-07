/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - PauseState.cpp
InversePalindrome.com
*/


#include "PauseState.hpp"
#include "StateMachine.hpp"


PauseState::PauseState(StateMachine* stateMachine, StateData* stateData) :
	State(stateMachine, stateData)
{
}

void PauseState::handleEvent()
{
	if (this->stateData->inputHandler->isKeyDown(irr::EKEY_CODE::KEY_ESCAPE))
	{
		this->stateMachine->popState();
	}
}

void PauseState::update(irr::f32 deltaTime)
{
	
}

void PauseState::draw()
{
	
}

bool PauseState::isTransparent()
{
	return true;
}