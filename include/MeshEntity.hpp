/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - MessEntity.hpp
InversePalindrome.com
*/


#pragma once

#include "Entity.hpp"

#include <IMeshSceneNode.h>


class MeshEntity : public Entity
{
public:
    MeshEntity(irr::scene::IMeshSceneNode* node);

    void setMesh(irr::scene::IMesh* mesh);
};