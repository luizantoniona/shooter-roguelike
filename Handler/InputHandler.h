#pragma once

#include <SFML/Graphics.hpp>

#include <Entity/Player/Player.h>
#include <Handler/HandlerGlobals.h>

using Entity::Player;

BEGIN_HANDLER_NAMESPACE

class InputHandler {
public:
    void handleInput( const sf::Event& event, Player& player );
};

END_HANDLER_NAMESPACE