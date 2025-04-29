#pragma once

#include <Controller/ControllerGlobals.h>

#include <Renderables/Entities/Character/Character.h>
#include <Renderables/Entities/Map/Map.h>

BEGIN_CONTROLLER_NAMESPACE

class PlayerProjectileController {
public:
    static void updatePlayerProjectile( const sf::Time& deltaTime, Entities::Character& player, Entities::Map& map );
    static void firePlayerProjectile( const sf::Vector2f& target, const sf::Time& deltaTime, Entities::Character& player );
};

END_CONTROLLER_NAMESPACE
