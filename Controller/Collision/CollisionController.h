#pragma once

#include <SFML/Graphics.hpp>

#include <Controller/ControllerGlobals.h>

#include <Entity/Enemy/Enemy.h>
#include <Entity/Player/Player.h>

using Entities::Enemy;
using Entities::Player;

BEGIN_CONTROLLER_NAMESPACE

class CollisionController {
public:
    void checkCollisions( Player& player, std::vector<std::unique_ptr<Enemy>>& enemies );

private:
    void handleProjectileCollisions( Player& player, std::vector<std::unique_ptr<Enemy>>& enemies );
    void handlePlayerCollisions( Player& player, std::vector<std::unique_ptr<Enemy>>& enemies );
};

END_CONTROLLER_NAMESPACE