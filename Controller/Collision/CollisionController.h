#pragma once

#include <SFML/Graphics.hpp>

#include <Controller/ControllerGlobals.h>

#include <Entity/Enemy/Enemy.h>
#include <Entity/Player/Player.h>

using Entity::Enemy;
using Entity::Player;

BEGIN_CONTROLLER_NAMESPACE

class CollisionController {
public:
    void checkCollisions( Player& player, std::vector<std::unique_ptr<Enemy>>& enemies );
};

END_CONTROLLER_NAMESPACE