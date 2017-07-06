/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - Application.hpp
InversePalindrome.com
*/


#pragma once

#include "StateData.hpp"
#include "StateMachine.hpp"

#include <irrlicht.h>


class Application
{
public:
	Application();

	void run();

private:
	InputHandler inputHandler;

	irr::IrrlichtDevice* device;
	irr::video::IVideoDriver* video;
	irr::scene::ISceneManager* sceneManager;
	irr::gui::IGUIEnvironment* gui;

	StateData stateData;
	StateMachine stateMachine;

	irr::u32 elapsedTime;
	
	void handleEvent();
	void update();
	void render();
};