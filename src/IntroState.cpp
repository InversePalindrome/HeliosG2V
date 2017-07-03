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
	//timer->start();
}

void IntroState::handleEvent()
{

}

void IntroState::update()
{
	if(this->timer->getTime() >= 2500)
	{
		this->stateMachine->popState();
		this->stateMachine->pushState(StateID::Start);
	}
}

void IntroState::draw()
{
	this->stateData->video->draw2DImage(this->logo, irr::core::recti(379u, 229u, 773u, 419u), irr::core::recti(0u, 0u, 984u, 475u));
}