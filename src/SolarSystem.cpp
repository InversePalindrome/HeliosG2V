/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - SolarSystem.cpp
InversePalindrome.com
*/


#include "SolarSystem.hpp"


SolarSystem::SolarSystem(irr::scene::ISceneManager* sceneManager) :
	sceneManager(sceneManager),
	astroObjects()
{
	sceneManager->addCameraSceneNodeMaya(0u, 100.f, 100.f, 100.f, 1u, 3000.f);
	
	astroObjects.emplace(AstroObjectID::Sun, AstroObject("Sun", 5.f, 0.f, irr::core::vector2df(0.f, 0.f), 
		sceneManager->addMeshSceneNode(sceneManager->getMesh("Resources/Meshes/football-soccer-ball.obj"))));

	astroObjects.emplace(AstroObjectID::Merury, AstroObject("Mercury", 0.4f, 2.f, irr::core::vector2df(620.f, 400.f),
		sceneManager->addMeshSceneNode(sceneManager->getMesh("Resources/Meshes/football-soccer-ball.obj"))));

	astroObjects.emplace(AstroObjectID::Venus, AstroObject("Venus", 0.9f, 1.5f, irr::core::vector2df(840.f, 620.f),
		sceneManager->addMeshSceneNode(sceneManager->getMesh("Resources/Meshes/football-soccer-ball.obj"))));

	astroObjects.emplace(AstroObjectID::Earth, AstroObject("Earth", 1.f, 1.f, irr::core::vector2df(1100.f, 820.f),
		sceneManager->addMeshSceneNode(sceneManager->getMesh("Resources/Meshes/football-soccer-ball.obj"))));
	
	astroObjects.emplace(AstroObjectID::Mars, AstroObject("Mars", 0.5f, 0.5f, irr::core::vector2df(1500.f, 1180.f), 
		sceneManager->addMeshSceneNode(sceneManager->getMesh("Resources/Meshes/football-soccer-ball.obj"))));
	
	astroObjects.emplace(AstroObjectID::Jupiter, AstroObject("Jupiter", 2.2f, 0.25f, irr::core::vector2df(2200.f, 1300.f),
		sceneManager->addMeshSceneNode(sceneManager->getMesh("Resources/Meshes/football-soccer-ball.obj"))));
	
	astroObjects.emplace(AstroObjectID::Saturn, AstroObject("Saturn", 1.8f, 0.2f, irr::core::vector2df(2600.f, 1500.f),
		sceneManager->addMeshSceneNode(sceneManager->getMesh("Resources/Meshes/football-soccer-ball.obj"))));

	astroObjects.emplace(AstroObjectID::Uranus, AstroObject("Uranus", 1.5f, 0.1f, irr::core::vector2df(3100.f, 1700.f),
		sceneManager->addMeshSceneNode(sceneManager->getMesh("Resources/Meshes/football-soccer-ball.obj"))));

	astroObjects.emplace(AstroObjectID::Neptune, AstroObject("Neptune", 1.4f, 0.05f, irr::core::vector2df(3600.f, 1900.f),
		sceneManager->addMeshSceneNode(sceneManager->getMesh("Resources/Meshes/football-soccer-ball.obj"))));
}

void SolarSystem::update(irr::f32 deltaTime)
{
	for (auto& astroObject : this->astroObjects)
	{
		astroObject.second.setPosition(irr::core::vector3df(std::cos(astroObject.second.getOrbitalAngle()) * astroObject.second.getOrbitRadius().X,
			 0.f, std::sin(astroObject.second.getOrbitalAngle()) * astroObject.second.getOrbitRadius().Y));

		astroObject.second.setOrbitalAngle(astroObject.second.getOrbitalAngle() + astroObject.second.getOrbitalDisplacement() * deltaTime);

		astroObject.second.setRotation(astroObject.second.getRotation() + irr::core::vector3df(astroObject.second.getOrbitalDisplacement(),
			0.f, astroObject.second.getOrbitalDisplacement()));
	}
}