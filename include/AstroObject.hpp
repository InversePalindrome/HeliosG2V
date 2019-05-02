/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - AstroObject.hpp
InversePalindrome.com
*/


#pragma once

#include "MeshEntity.hpp"


class AstroObject : public MeshEntity
{
public:
    AstroObject(const std::string& name, float scale, float orbitalDisplacement, const irr::core::vector2df& orbitRadius, irr::scene::IMeshSceneNode* node);

    std::string getName() const;
    float getOrbitalAngle() const;
    float getOrbitalDisplacement() const;
    irr::core::vector2df getOrbitRadius() const;

    void setOrbitalAngle(float orbitalAngle);
    void setOrbitalDisplacement(float orbitalDisplacemnet);
    void setOrbitRadius(const irr::core::vector2df& orbitRadius);

private:
    const std::string name;

    float orbitalAngle;
    float orbitalDisplacement;
    irr::core::vector2df orbitRadius;
};