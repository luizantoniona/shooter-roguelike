#pragma once

#include <SFML/Graphics.hpp>

#include <Controller/ControllerGlobals.h>

#include <Entity/Character/Character.h>
#include <Entity/Map/Map.h>

BEGIN_CONTROLLER_NAMESPACE

class Spawner {
public:
    static void spawn( Entities::Map& map, std::vector<std::unique_ptr<Entities::Character>>& enemies, Entities::Character& player );
};

END_CONTROLLER_NAMESPACE