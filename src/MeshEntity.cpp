/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - MeshEntity.cpp
InversePalindrome.com
*/


#include "MeshEntity.hpp"


MeshEntity::MeshEntity(irr::scene::IMeshSceneNode* node) :
	Entity(node)
{
	node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

void MeshEntity::setMesh(irr::scene::IMesh* mesh)
{
	static_cast<irr::scene::IMeshSceneNode*>(this->node)->setMesh(mesh);
}