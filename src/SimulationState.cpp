/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - SimulationState.cpp
InversePalindrome.com
*/


#include "SimulationState.hpp"
#include "StateMachine.hpp"

#include <IGUIStaticText.h>
#include <IGUIEnvironment.h>


SimulationState::SimulationState(StateMachine* stateMachine, StateData* stateData) :
    State(stateMachine, stateData),
    solarSystem(stateData->sceneManager, stateData->inputHandler),
    tabControl(stateData->gui->addTabControl(irr::core::recti(0u, 0u, 200u, 180u), 0u, true, true))
{
    stateData->gui->getSkin()->setFont(stateData->sceneManager->getGUIEnvironment()->getFont("Resources/Fonts/governor.XML"));

    tabControl->addTab(L"Sun");
    tabControl->addTab(L"Mercury");
    tabControl->addTab(L"Venus");
    tabControl->addTab(L"Earth");
    tabControl->addTab(L"Mars");
    tabControl->addTab(L"Jupiter");
    tabControl->addTab(L"Saturn");
    tabControl->addTab(L"Uranus");
    tabControl->addTab(L"Neptune");


    auto* skin = stateData->gui->getSkin();
    skin->setFont(stateData->sceneManager->getGUIEnvironment()->getFont("Resources/Fonts/governor.XML"));
    skin->setColor(irr::gui::EGUI_DEFAULT_COLOR::EGDC_BUTTON_TEXT, irr::video::SColor(255u, 0u, 128u, 255u));

    tabControl->getTab(0u)->addChild(stateData->gui->addStaticText(L"Mass:\n1.989e30 kg\nSize Radius:\n695,700 km", irr::core::recti(0u, 0u, 200u, 200u)));
    tabControl->getTab(1u)->addChild(stateData->gui->addStaticText(L"Mass:\n3.285e23 kg\nSize Radius:\n2440km\nOrbital Period:\n88 days", irr::core::recti(0u, 0u, 200u, 200u)));
    tabControl->getTab(2u)->addChild(stateData->gui->addStaticText(L"Mass:\n4.8675e24 kg\nSize Radius:\n6052 km\nOrbital Period:\n224.7 days", irr::core::recti(0u, 0u, 200u, 200u)));
    tabControl->getTab(3u)->addChild(stateData->gui->addStaticText(L"Mass:\n5.972e24 kg\nSize Radius:\n6371 km\nOrbital Period:\n365.25 days", irr::core::recti(0u, 0u, 200u, 200u)));
    tabControl->getTab(4u)->addChild(stateData->gui->addStaticText(L"Mass:\n6.4171e23 kg\nSize Radius:\n3389.5 km\nOrbital Period:\n686.96 days", irr::core::recti(0u, 0u, 200u, 200u)));
    tabControl->getTab(5u)->addChild(stateData->gui->addStaticText(L"Mass:\n1.898e27 kg\nSize Radius:\n69911 km\nOrbital Period:\n4332.59 days", irr::core::recti(0u, 0u, 200u, 200u)));
    tabControl->getTab(6u)->addChild(stateData->gui->addStaticText(L"Mass:\n5.683e26 kg\nSize Radius:\n58232 km\nOrbital Period:\n10759.22 days", irr::core::recti(0u, 0u, 200u, 200u)));
    tabControl->getTab(7u)->addChild(stateData->gui->addStaticText(L"Mass:\n8.681e25 kg\nSize Radius:\n25559 km\nOrbital Period:\n30688.5 days", irr::core::recti(0u, 0u, 200u, 200u)));
    tabControl->getTab(8u)->addChild(stateData->gui->addStaticText(L"Mass:\n1.024e26 kg\nSize Radius:\n24622 km\nOrbital Period:\n60182 days", irr::core::recti(0u, 0u, 200u, 200u)));

    tabControl->setVisible(false);
}

void SimulationState::handleEvent()
{
    if (this->stateData->inputHandler->isKeyDown(irr::EKEY_CODE::KEY_ESCAPE))
    {
        this->stateMachine->pushState(StateID::Pause);
    }
    else if (this->stateData->inputHandler->isKeyDown(irr::EKEY_CODE::KEY_TAB))
    {
        if (this->tabControl->isVisible())
        {
            this->tabControl->setVisible(false);
        }
        else
        {
            this->tabControl->setVisible(true);
        }
    }

    this->solarSystem.handleEvent();
}

void SimulationState::update(irr::f32 deltaTime)
{
    this->solarSystem.update(deltaTime);
}

void SimulationState::draw()
{

}