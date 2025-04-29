#pragma once

#include <SFML/Graphics.hpp>

#include <Controller/ControllerGlobals.h>

#include <Renderables/Entities/Character/Character.h>
#include <Renderables/Entities/Map/Map.h>

BEGIN_CONTROLLER_NAMESPACE

class SpawnController {
public:
    static void spawn( Entities::Map& map, std::vector<std::unique_ptr<Entities::Character>>& enemies, Entities::Character& player );
};

END_CONTROLLER_NAMESPACE
