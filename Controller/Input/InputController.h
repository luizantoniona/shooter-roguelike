#pragma once

#include <SFML/Graphics.hpp>

#include <Controller/ControllerGlobals.h>

#include <Entities/Character/Character.h>

BEGIN_CONTROLLER_NAMESPACE

class InputController {
public:
    static void handleInput( const sf::Event& event, Entities::Character& player );
};

END_CONTROLLER_NAMESPACE
