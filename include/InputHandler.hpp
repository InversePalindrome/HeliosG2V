/*
Copyright (c) 2017 InversePalindrome
HeliosG2V - InputHandler.hpp
InversePalindrome.com
*/


#pragma once

#include <IEventReceiver.h>

#include <array>


class InputHandler : public irr::IEventReceiver
{
public:
    InputHandler();

    virtual bool OnEvent(const irr::SEvent& event) override;

    bool isKeyDown() const;
    bool isKeyDown(irr::EKEY_CODE key) const;

private:
    std::array<bool, irr::KEY_KEY_CODES_COUNT> keys;
};