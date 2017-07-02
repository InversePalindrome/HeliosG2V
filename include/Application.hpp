/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - Application.hpp
InversePalindrome.com
*/


#pragma once

#include "StateMachine.hpp"

#include <irrlicht.h>


class Application
{
public:
	Application();

	void run();

private:
	irr::IrrlichtDevice* device;
	irr::video::IVideoDriver* video;
	irr::scene::ISceneManager* sceneManager;

	StateMachine stateMachine;
};