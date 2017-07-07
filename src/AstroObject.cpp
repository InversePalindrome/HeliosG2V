/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - AstroObject.cpp
InversePalindrome.com
*/


#include "AstroObject.hpp"


AstroObject::AstroObject(const std::string& name, float scale, float orbitalDisplacement, const irr::core::vector2df& orbitRadius, irr::scene::IMeshSceneNode* node) :
	MeshEntity(node),
	name(name),
	orbitalAngle(90.f),
	orbitalDisplacement(orbitalDisplacement),
	orbitRadius(orbitRadius)
{
	node->setScale(irr::core::vector3df(scale, scale, scale));
}

std::string AstroObject::getName() const
{
	return this->name;
}

float AstroObject::getOrbitalAngle() const
{
	return this->orbitalAngle;
}

float AstroObject::getOrbitalDisplacement() const
{
	return this->orbitalDisplacement;
}

irr::core::vector2df AstroObject::getOrbitRadius() const
{
	return this->orbitRadius;
}

void AstroObject::setOrbitalAngle(float orbitalAngle)
{
	this->orbitalAngle = orbitalAngle;
}

void AstroObject::setOrbitalDisplacement(float orbitalDisplacement)
{
	this->orbitalDisplacement = orbitalDisplacement;
}

void AstroObject::setOrbitRadius(const irr::core::vector2df& orbitRadius)
{
	this->orbitRadius = orbitRadius;
}