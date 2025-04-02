#pragma once

#include <Controller/ControllerGlobals.h>

#include <Entity/Character/Character.h>
#include <Entity/Map/Map.h>

BEGIN_CONTROLLER_NAMESPACE

class PlayerController {
public:
    static void updatePlayer( sf::RenderWindow& window, const sf::Time& deltaTime, Entities::Character& player, Entities::Map& map );

private:
    static void updatePlayerPosition( const sf::RenderWindow& window, const sf::Time& deltaTime, Entities::Character& player, Entities::Map& map );
};

END_CONTROLLER_NAMESPACE