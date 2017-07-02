/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - State.hpp
InversePalindrome.com
*/


#pragma once

#include <IrrlichtDevice.h>


class StateMachine;

class State
{
public:
	State(StateMachine* stateMachine, irr::IrrlichtDevice* device);

	virtual void update() = 0;

private:
	irr::IrrlichtDevice* device;
	irr::video::IVideoDriver* video;
	irr::scene::ISceneManager* sceneManager;
};