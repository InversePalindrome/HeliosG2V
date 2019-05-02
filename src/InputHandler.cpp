/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - InputHandler.cpp
InversePalindrome.com
*/


#include "InputHandler.hpp"


InputHandler::InputHandler() :
    keys()
{
    std::fill(std::begin(keys), std::end(keys), false);
}

bool InputHandler::OnEvent(const irr::SEvent& event)
{
    switch (event.EventType)
    {
    case irr::EET_KEY_INPUT_EVENT:
        this->keys.at(event.KeyInput.Key) = event.KeyInput.PressedDown;
        break;
    }

    return false;
}

bool InputHandler::isKeyDown() const
{
    for (const auto& key : this->keys)
    {
        if (key)
        {
            return true;
        }
    }

    return false;
}

bool InputHandler::isKeyDown(irr::EKEY_CODE key) const
{
    return this->keys.at(key);
}