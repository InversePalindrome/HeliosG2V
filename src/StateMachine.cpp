/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - StateMachine.cpp
InversePalindrome.com
*/


#include "StateMachine.hpp"
#include "IntroState.hpp"


StateMachine::StateMachine(irr::IrrlichtDevice* device) :
	states(),
	stateActions(),
	stateFactory()
{
	registerState<IntroState>(StateID::Intro, device);
}

void StateMachine::update()
{
	if (!this->states.empty())
	{
		this->states.back()->update();
	}

	this->processStateActions();
}

void StateMachine::pushState(StateID stateID)
{
	this->stateActions.push_back([this, stateID] { this->states.push_back(this->getState(stateID)); });
}

void StateMachine::popState()
{
	this->stateActions.push_back([this] { this->states.pop_back(); });
}

void StateMachine::clearStates()
{
	this->stateActions.push_back([this] { this->states.clear(); });
}

StateMachine::StatePtr StateMachine::getState(StateID stateID)
{
	return this->stateFactory.find(stateID)->second();
}

void StateMachine::processStateActions()
{
	for (const auto& action : this->stateActions)
	{
		action();
	}

	this->stateActions.clear();
}