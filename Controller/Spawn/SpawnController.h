#pragma once

#include <SFML/Graphics.hpp>

#include <Controller/ControllerGlobals.h>

#include <Entity/Enemy/Enemy.h>
#include <Entity/Map/Map.h>

using Entity::Enemy;
using Entity::Map;

BEGIN_CONTROLLER_NAMESPACE

class SpawnController {
public:
    void checkSpawn( Map& map, std::vector<Enemy>& enemies );
};

END_CONTROLLER_NAMESPACE