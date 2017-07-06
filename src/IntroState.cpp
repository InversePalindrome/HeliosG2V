/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - IntroState.cpp
InversePalindrome.com
*/


#include "IntroState.hpp"
#include "StateMachine.hpp"


IntroState::IntroState(StateMachine* stateMachine, StateData* stateData) :
	State(stateMachine, stateData),
	logo(stateData->video->getTexture("Resources/Images/InversePalindromeLogo.png")),
	timer(stateData->device->getTimer())
{ 
}

void IntroState::handleEvent()
{
}

void IntroState::update(irr::f32 deltaTime)
{
	if(this->timer->getTime() >= 2500u)
	{
		this->stateMachine->popState();
		this->stateMachine->pushState(StateID::Start);
	}
}

void IntroState::draw()
{
	this->stateData->video->draw2DImage(this->logo, irr::core::recti(360u, 229u, 773u, 419u), irr::core::recti(0u, 0u, 919u, 411u));
}