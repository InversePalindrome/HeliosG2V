/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - Application.cpp
InversePalindrome.com
*/


#include "Application.hpp"


Application::Application() :
	inputHandler(),
	device(irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1152u, 648u), 16u, false, false, true, &inputHandler)),
	video(device->getVideoDriver()),
	sceneManager(device->getSceneManager()),
	gui(device->getGUIEnvironment()),
	stateData(device, &inputHandler),
	stateMachine(&stateData)
{
	device->setWindowCaption(L"HeliosG2V");
	
	stateMachine.pushState(StateID::Intro);
}

void Application::run()
{
	while (device->run())
	{
		this->handleEvent();

		this->update();

		this->render();
	}
}

void Application::handleEvent()
{
	this->stateMachine.handleEvent();
}

void Application::update()
{
	this->stateMachine.update();
}

void Application::render()
{
	this->video->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));

	this->stateMachine.draw();

	this->sceneManager->drawAll();

	this->gui->drawAll();

	this->video->endScene();
}

