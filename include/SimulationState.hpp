/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - SimulationState.hpp
InversePalindrome.com
*/


#pragma once

#include "State.hpp"
#include "SolarSystem.hpp"

#include <IGUITabControl.h>


class SimulationState : public State
{
public:
	SimulationState(StateMachine* stateMachine, StateData* stateData);

	virtual void handleEvent() override;
	virtual void update(irr::f32 deltaTime) override;
	virtual void draw() override;

private:
	SolarSystem solarSystem;

	irr::gui::IGUITabControl* tabControl;
};