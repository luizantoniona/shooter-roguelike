#pragma once

#include <SFML/Graphics.hpp>

#include <Controller/ControllerGlobals.h>

#include <Entity/Enemy/Enemy.h>
#include <Entity/Map/Map.h>
#include <Entity/Player/Player.h>

using Entities::Enemy;
using Entities::Map;
using Entities::Player;

BEGIN_CONTROLLER_NAMESPACE

class SpawnController {
public:
    void checkSpawn( Map& map, std::vector<std::unique_ptr<Enemy>>& enemies, Player& player );
};

END_CONTROLLER_NAMESPACE