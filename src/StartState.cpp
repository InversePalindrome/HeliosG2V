/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - StartState.cpp
InversePalindrome.com
*/


#include "StartState.hpp"
#include "StateMachine.hpp"


StartState::StartState(StateMachine* stateMachine, StateData* stateData) :
    State(stateMachine, stateData),
    background(stateData->video->getTexture("Resources/Images/StartBackground.jpg"))
{
}

void StartState::handleEvent()
{
    if (this->stateData->inputHandler->isKeyDown())
    {
        this->stateMachine->popState();
        this->stateMachine->pushState(StateID::Simulation);
    }
}

void StartState::update(irr::f32 deltaTime)
{

}

void StartState::draw()
{
    this->stateData->video->draw2DImage(this->background, irr::core::recti(0u, 0u, this->stateData->video->getScreenSize().Width, this->stateData->video->getScreenSize().Height),
        irr::core::recti(0u, 0u, 1920u, 1080u));
}
