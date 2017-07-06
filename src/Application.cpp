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
	elapsedTime(0u),
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
	auto deltaTime = static_cast<irr::f32>(this->device->getTimer()->getTime() - elapsedTime) / 1000.f;

	elapsedTime = this->device->getTimer()->getTime();

	this->stateMachine.update(deltaTime);
}

void Application::render()
{
	this->video->beginScene(true, true, irr::video::SColor(255u, 0u, 0u, 0u));

	this->stateMachine.draw();

	this->sceneManager->drawAll();

	this->gui->drawAll();

	this->video->endScene();
}

