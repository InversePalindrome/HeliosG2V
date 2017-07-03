/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - IntroState.hpp
InversePalindrome.com
*/


#pragma once

#include "State.hpp"

#include <ITimer.h>


class IntroState : public State
{
public:
	IntroState(StateMachine* stateMachine, StateData* stateData);

	virtual void handleEvent() override;
	virtual void update() override;
	virtual void draw() override;

private:
	irr::video::ITexture* logo;
	irr::ITimer* timer;
};

