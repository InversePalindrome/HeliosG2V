/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - SolarSystem.cpp
InversePalindrome.com
*/


#include "SolarSystem.hpp"

#include <IGUIFont.h>
#include <IVideoDriver.h>
#include <IGUIEnvironment.h>


SolarSystem::SolarSystem(irr::scene::ISceneManager* sceneManager, InputHandler* inputHandler) :
    sceneManager(sceneManager),
    inputHandler(inputHandler),
    astroObjects(),
    astroNames()
{
    sceneManager->addCameraSceneNodeMaya(0u, 100.f, 100.f, 100.f, 1u, 3100.f);
    sceneManager->addSkyDomeSceneNode(sceneManager->getVideoDriver()->getTexture("Resources/Images/SpaceBackground.jpg"));

    astroObjects.emplace(AstroObjectID::Sun, AstroObject("Sun", 22.f, 0.f, irr::core::vector2df(0.f, 0.f),
        sceneManager->addMeshSceneNode(sceneManager->getMesh("Resources/Meshes/Sun.obj"))));

    astroObjects.emplace(AstroObjectID::Merury, AstroObject("Mercury", 1.8f, 2.f, irr::core::vector2df(620.f, 400.f),
        sceneManager->addMeshSceneNode(sceneManager->getMesh("Resources/Meshes/Mercury.obj"))));

    astroObjects.emplace(AstroObjectID::Venus, AstroObject("Venus", 4.2f, 1.5f, irr::core::vector2df(840.f, 620.f),
        sceneManager->addMeshSceneNode(sceneManager->getMesh("Resources/Meshes/Venus.obj"))));

    astroObjects.emplace(AstroObjectID::Earth, AstroObject("Earth", 4.6f, 1.f, irr::core::vector2df(1100.f, 820.f),
        sceneManager->addMeshSceneNode(sceneManager->getMesh("Resources/Meshes/Earth.obj"))));

    astroObjects.emplace(AstroObjectID::Mars, AstroObject("Mars", 2.4f, 0.5f, irr::core::vector2df(1500.f, 1180.f),
        sceneManager->addMeshSceneNode(sceneManager->getMesh("Resources/Meshes/Mars.obj"))));

    astroObjects.emplace(AstroObjectID::Jupiter, AstroObject("Jupiter", 10.f, 0.25f, irr::core::vector2df(1800.f, 1300.f),
        sceneManager->addMeshSceneNode(sceneManager->getMesh("Resources/Meshes/Jupiter.obj"))));

    astroObjects.emplace(AstroObjectID::Saturn, AstroObject("Saturn", 8.2f, 0.2f, irr::core::vector2df(2200.f, 1500.f),
        sceneManager->addMeshSceneNode(sceneManager->getMesh("Resources/Meshes/Saturn.obj"))));

    astroObjects.emplace(AstroObjectID::Uranus, AstroObject("Uranus", 6.f, 0.1f, irr::core::vector2df(3000.f, 1700.f),
        sceneManager->addMeshSceneNode(sceneManager->getMesh("Resources/Meshes/Uranus.obj"))));

    astroObjects.emplace(AstroObjectID::Neptune, AstroObject("Neptune", 5.9f, 0.05f, irr::core::vector2df(3400.f, 1900.f),
        sceneManager->addMeshSceneNode(sceneManager->getMesh("Resources/Meshes/Neptune.obj"))));

    auto* font = sceneManager->getGUIEnvironment()->getFont("Resources/Fonts/governor.XML");

    astroNames.push_back(sceneManager->addTextSceneNode(font, L"Sun", irr::video::SColor(255u, 0u, 128u, 255u), astroObjects.at(AstroObjectID::Sun).getNode(), irr::core::vector3df(0.f, 0.f, 0.f)));
    astroNames.push_back(sceneManager->addTextSceneNode(font, L"Mercury", irr::video::SColor(255u, 0u, 128u, 255u), astroObjects.at(AstroObjectID::Merury).getNode(), irr::core::vector3df(0.f, 0.f, 0.f)));
    astroNames.push_back(sceneManager->addTextSceneNode(font, L"Venus", irr::video::SColor(255u, 0u, 128u, 255u), astroObjects.at(AstroObjectID::Venus).getNode(), irr::core::vector3df(0.f, 0.f, 0.f)));
    astroNames.push_back(sceneManager->addTextSceneNode(font, L"Earth", irr::video::SColor(255u, 0u, 128u, 255u), astroObjects.at(AstroObjectID::Earth).getNode(), irr::core::vector3df(0.f, 0.f, 0.f)));
    astroNames.push_back(sceneManager->addTextSceneNode(font, L"Mars", irr::video::SColor(255u, 0u, 128u, 255u), astroObjects.at(AstroObjectID::Mars).getNode(), irr::core::vector3df(0.f, 0.f, 0.f)));
    astroNames.push_back(sceneManager->addTextSceneNode(font, L"Jupiter", irr::video::SColor(255u, 0u, 128u, 255u), astroObjects.at(AstroObjectID::Jupiter).getNode(), irr::core::vector3df(0.f, 0.f, 0.f)));
    astroNames.push_back(sceneManager->addTextSceneNode(font, L"Saturn", irr::video::SColor(255u, 0u, 128u, 255u), astroObjects.at(AstroObjectID::Saturn).getNode(), irr::core::vector3df(0.f, 0.f, 0.f)));
    astroNames.push_back(sceneManager->addTextSceneNode(font, L"Uranus", irr::video::SColor(255u, 0u, 128u, 255u), astroObjects.at(AstroObjectID::Uranus).getNode(), irr::core::vector3df(0.f, 0.f, 0.f)));
    astroNames.push_back(sceneManager->addTextSceneNode(font, L"Neptune", irr::video::SColor(255u, 0u, 128u, 255u), astroObjects.at(AstroObjectID::Neptune).getNode(), irr::core::vector3df(0.f, 0.f, 0.f)));

    for (auto& astroName : astroNames)
    {
        astroName->setVisible(false);
    }
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

void SolarSystem::handleEvent()
{
    if (inputHandler->isKeyDown(irr::EKEY_CODE::KEY_TAB))
    {
        for (auto& astroName : this->astroNames)
        {
            if (astroName->isVisible())
            {
                astroName->setVisible(false);
            }
            else
            {
                astroName->setVisible(true);
            }
        }
    }
}