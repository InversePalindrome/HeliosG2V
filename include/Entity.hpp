/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - Entity.hpp
InversePalindrome.com
*/


#pragma once

#include <ISceneNode.h>

#include <string>


class Entity
{
public:
	Entity(irr::scene::ISceneNode* node);

	irr::scene::ISceneNode* getNode();

	void addChild(irr::scene::ISceneNode* childNode);
	void setParent(irr::scene::ISceneNode* parentNode);

	irr::core::vector3df getPosition() const;
	irr::core::vector3df getScale() const;
	irr::core::vector3df getRotation() const;

	void setPosition(const irr::core::vector3df& position);
	void setScale(const irr::core::vector3df& scale);
	void setRotation(const irr::core::vector3df& rotation);

protected:
	irr::scene::ISceneNode* node;
};