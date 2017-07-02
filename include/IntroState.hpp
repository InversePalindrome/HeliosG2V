/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - IntroState.hpp
InversePalindrome.com
*/


#pragma once

#include "State.hpp"


class IntroState : public State
{
public:
	IntroState(StateMachine* stateMachine, irr::IrrlichtDevice* device);

	virtual void update() override;
};

