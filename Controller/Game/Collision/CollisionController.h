#pragma once

#include <SFML/Graphics.hpp>

#include <Controller/ControllerGlobals.h>

#include <Entity/Character/Character.h>

BEGIN_CONTROLLER_NAMESPACE

class CollisionController {
public:
    static void checkCollisions( Entities::Character& player, std::vector<std::unique_ptr<Entities::Character>>& enemies );

private:
    static void handleProjectileCollisions( Entities::Character& player, std::vector<std::unique_ptr<Entities::Character>>& enemies );
    static void handlePlayerCollisions( Entities::Character& player, std::vector<std::unique_ptr<Entities::Character>>& enemies );
};

END_CONTROLLER_NAMESPACE