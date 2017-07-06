/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - SolarSystem.hpp
InversePalindrome.com
*/


#pragma once

#include "AstroObject.hpp"

#include <ISceneManager.h>

#include <unordered_map>


class SolarSystem
{
	enum class AstroObjectID { Sun, Merury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, Neptune };

public:
	SolarSystem(irr::scene::ISceneManager* sceneManager);

	void update(irr::f32 deltaTime);

private:
	irr::scene::ISceneManager* sceneManager;
	std::unordered_map<AstroObjectID, AstroObject> astroObjects;
};