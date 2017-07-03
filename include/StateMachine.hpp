/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - StateMachine.hpp
InversePalindrome.com
*/


#pragma once

#include "State.hpp"

#include <memory>
#include <vector>
#include <functional>
#include <unordered_map>

#include <IrrlichtDevice.h>


enum class StateID { Intro, Start, Simulation };

class StateMachine
{
	using StatePtr = std::unique_ptr<State>;

public:
	StateMachine(StateData* stateData);

	void handleEvent();
	void update();
	void draw();

	void pushState(StateID stateID);
	void popState();
	void clearStates();

private:
	std::vector<StatePtr> states;
	std::vector<std::function<void()>> stateActions;
	std::unordered_map<StateID, std::function<StatePtr()>> stateFactory;

	StatePtr getState(StateID stateID);

	void processStateActions();

	template<typename T>
	void registerState(StateID stateID, StateData* stateData);
};


template<typename T>
void StateMachine::registerState(StateID stateID, StateData* stateData)
{
	this->stateFactory[stateID] = [this, stateData]()
	{
		return std::make_unique<T>(this, stateData);
	};
}