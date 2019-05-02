/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - SolarSystem.hpp
InversePalindrome.com
*/


#pragma once

#include "AstroObject.hpp"
#include "InputHandler.hpp"

#include <ISceneManager.h>
#include <ITextSceneNode.h>

#include <vector>
#include <unordered_map>


class SolarSystem
{
    enum class AstroObjectID { Sun, Merury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, Neptune };

public:
    SolarSystem(irr::scene::ISceneManager* sceneManager, InputHandler* inputHandler);

    void update(irr::f32 deltaTime);
    void handleEvent();

private:
    irr::scene::ISceneManager* sceneManager;
    InputHandler* inputHandler;

    std::unordered_map<AstroObjectID, AstroObject> astroObjects;
    std::vector<irr::scene::ITextSceneNode*> astroNames;
};