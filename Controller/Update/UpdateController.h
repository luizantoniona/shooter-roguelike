#pragma once

#include <SFML/Graphics.hpp>

#include <Controller/ControllerGlobals.h>

#include <Entity/Enemy/Enemy.h>
#include <Entity/Map/Map.h>
#include <Entity/Player/Player.h>

using Entity::Enemy;
using Entity::Map;
using Entity::Player;

BEGIN_CONTROLLER_NAMESPACE

class UpdateController {
public:
    void update( sf::RenderWindow& window, sf::Time& deltaTime, Player& player, std::vector<Enemy>& enemies, Map& map );
    void checkCollisions( Player& player, std::vector<Enemy>& enemies );
};

END_CONTROLLER_NAMESPACE