/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - StateData.hpp
InversePalindrome.com
*/


#pragma once

#include <IrrlichtDevice.h>

#include "InputHandler.hpp"


struct StateData
{
    StateData(irr::IrrlichtDevice* device, InputHandler* inputHandler);

    irr::IrrlichtDevice* device;
    irr::video::IVideoDriver* video;
    irr::scene::ISceneManager* sceneManager;
    irr::gui::IGUIEnvironment* gui;

    InputHandler* inputHandler;
};