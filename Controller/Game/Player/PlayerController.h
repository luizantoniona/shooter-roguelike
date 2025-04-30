#pragma once

#include <Controller/ControllerGlobals.h>

#include <Entities/Character/Character.h>
#include <Entities/Map/Map.h>

BEGIN_CONTROLLER_NAMESPACE

class PlayerController {
public:
    static void updatePlayer( sf::RenderWindow& window, const sf::Time& deltaTime, Entities::Character& player, Entities::Map& map );

private:
    static void updatePlayerPosition( const sf::RenderWindow& window, const sf::Time& deltaTime, Entities::Character& player, Entities::Map& map );
};

END_CONTROLLER_NAMESPACE
