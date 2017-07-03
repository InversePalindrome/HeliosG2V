/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - StateData.cpp
InversePalindrome.com
*/


#include "StateData.hpp"


StateData::StateData(irr::IrrlichtDevice* device, InputHandler* inputHandler) :
	device(device),
	video(device->getVideoDriver()),
	sceneManager(device->getSceneManager()),
	gui(device->getGUIEnvironment()),
	inputHandler(inputHandler)
{
}
