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
    void update( sf::RenderWindow& window, const sf::Time& deltaTime, Player& player, std::vector<std::unique_ptr<Enemy>>& enemies, Map& map );
};

END_CONTROLLER_NAMESPACE