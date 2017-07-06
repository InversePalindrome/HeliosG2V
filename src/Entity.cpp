/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - Entity.cpp
InversePalindrome.com
*/


#include "Entity.hpp"


Entity::Entity(irr::scene::ISceneNode* node) : 
	node(node)
{
}

irr::scene::ISceneNode* Entity::getNode()
{
	return this->node;
}

void Entity::addChild(irr::scene::ISceneNode* childNode)
{
	this->node->addChild(childNode);
}

void Entity::setParent(irr::scene::ISceneNode* parentNode)
{
	this->node->setParent(parentNode);
}

irr::core::vector3df Entity::getPosition() const
{
	return this->node->getPosition();
}

irr::core::vector3df Entity::getScale() const
{
	return this->node->getScale();
}

irr::core::vector3df Entity::getRotation() const
{
	return this->node->getRotation();
}

void Entity::setPosition(const irr::core::vector3df& position)
{
	this->node->setPosition(position);
}

void Entity::setScale(const irr::core::vector3df& scale)
{
	this->node->setScale(scale);
}

void Entity::setRotation(const irr::core::vector3df& rotation)
{
	this->node->setRotation(rotation);
}