#pragma once

#include <SFML/Graphics.hpp>

#include <Controller/ControllerGlobals.h>

#include <Entity/Player/Player.h>

using Entities::Player;

BEGIN_CONTROLLER_NAMESPACE

class InputController {
public:
    void handleInput( const sf::Event& event, Player& player );
};

END_CONTROLLER_NAMESPACE