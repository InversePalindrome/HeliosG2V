/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - StartState.hpp
InversePalindrome.com
*/


#pragma once

#include "State.hpp"


class StartState : public State
{
public:
	StartState(StateMachine* stateMachine, StateData* stateData);

	virtual void handleEvent() override;
	virtual void update() override;
	virtual void draw() override;

private:
	irr::video::ITexture* background;
};