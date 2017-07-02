/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - Application.cpp
InversePalindrome.com
*/


#include "Application.hpp"


Application::Application() :
	device(irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1152u, 648u), 16u, false, false, true)),
	video(device->getVideoDriver()),
	sceneManager(device->getSceneManager()),
	stateMachine(device)
{
	device->setWindowCaption(L"HeliosG2V");
	
	stateMachine.pushState(StateID::Intro);
}

void Application::run()
{
	while (device->run())
	{
		this->video->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));

		this->stateMachine.update();

		this->sceneManager->drawAll();

		this->video->endScene();
	}
}


