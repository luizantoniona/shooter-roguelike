#pragma once

#include <SFML/Graphics.hpp>

#include <Controller/ControllerGlobals.h>

#include <Entity/Character/Character.h>
#include <Entity/Map/Map.h>

BEGIN_CONTROLLER_NAMESPACE

class RenderController {
public:
    static void render( sf::RenderWindow& window, Entities::Character& player, std::vector<std::unique_ptr<Entities::Character>>& enemies, Entities::Map& map );
};

END_CONTROLLER_NAMESPACE