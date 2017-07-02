/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - State.cpp
InversePalindrome.com
*/


#include "State.hpp"
#include "StateMachine.hpp"


State::State(StateMachine* stateMachine, irr::IrrlichtDevice* device) :
	device(device),
	video(device->getVideoDriver()),
	sceneManager(device->getSceneManager())
{
}