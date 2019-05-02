/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - StateMachine.cpp
InversePalindrome.com
*/


#include "StateMachine.hpp"
#include "SimulationState.hpp"
#include "IntroState.hpp"
#include "StartState.hpp"
#include "PauseState.hpp"


StateMachine::StateMachine(StateData* stateData) :
    states(),
    stateActions(),
    stateFactory()
{
    registerState<IntroState>(StateID::Intro, stateData);
    registerState<StartState>(StateID::Start, stateData);
    registerState<SimulationState>(StateID::Simulation, stateData);
    registerState<PauseState>(StateID::Pause, stateData);
}

void StateMachine::handleEvent()
{
    if (!this->states.empty())
    {
        this->states.back()->handleEvent();
    }

    this->processStateActions();
}

void StateMachine::update(irr::f32 deltaTime)
{
    if (!this->states.empty())
    {
        this->states.back()->update(deltaTime);
    }

    this->processStateActions();
}

void StateMachine::draw()
{
    if (!this->states.empty())
    {
        if (this->states.back()->isTransparent() && this->states.size() > 1)
        {
            auto itr = std::end(this->states);

            for (; itr != std::begin(this->states); --itr)
            {
                if (itr != std::end(this->states) && !(*itr)->isTransparent())
                {
                    break;
                }
            }

            for (; itr != std::end(this->states); ++itr)
            {
                (*itr)->draw();
            }
        }
        else
        {
            this->states.back()->draw();
        }
    }
}

void StateMachine::pushState(StateID stateID)
{
    this->stateActions.push_back([this, stateID] { this->states.push_back(this->getState(stateID)); });
}

void StateMachine::popState()
{
    this->stateActions.push_back([this] { this->states.pop_back(); });
}

void StateMachine::clearStates()
{
    this->stateActions.push_back([this] { this->states.clear(); });
}

StateMachine::StatePtr StateMachine::getState(StateID stateID)
{
    return this->stateFactory.find(stateID)->second();
}

void StateMachine::processStateActions()
{
    for (const auto& action : this->stateActions)
    {
        action();
    }

    this->stateActions.clear();
}