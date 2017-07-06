/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - SimulationState.cpp
InversePalindrome.com
*/


#include "SimulationState.hpp"
#include "StateMachine.hpp"


SimulationState::SimulationState(StateMachine* stateMachine, StateData* stateData) :
	State(stateMachine, stateData),
	solarSystem(stateData->sceneManager)
{
}

void SimulationState::handleEvent()
{

}

void SimulationState::update(irr::f32 deltaTime)
{
	this->solarSystem.update(deltaTime);
}

void SimulationState::draw()
{

}