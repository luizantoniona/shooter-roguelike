#pragma once

#include <SFML/Graphics.hpp>

#include <Handler/HandlerGlobals.h>

#include <Entity/Enemy/Enemy.h>
#include <Entity/Map/Map.h>
#include <Entity/Player/Player.h>

using Entity::Enemy;
using Entity::Map;
using Entity::Player;

BEGIN_HANDLER_NAMESPACE

class UpdateHandler {
public:
    void update( sf::Time& deltaTime, Player& player, std::vector<Enemy>& enemies, Map& map );
    void checkCollisions( Player& player, std::vector<Enemy>& enemies );
};

END_HANDLER_NAMESPACE