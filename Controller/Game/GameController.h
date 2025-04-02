#pragma once

#include <SFML/Graphics.hpp>

#include <Controller/ControllerGlobals.h>

#include <Entity/Character/Character.h>
#include <Entity/Map/Map.h>

BEGIN_CONTROLLER_NAMESPACE

class GameController {
public:
    static void update( sf::RenderWindow& window, const sf::Time& deltaTime, Entities::Character& player, std::vector<std::unique_ptr<Entities::Character>>& enemies, Entities::Map& map );

private:
    static void updatePlayer( sf::RenderWindow& window, const sf::Time& deltaTime, Entities::Character& player );
    static void updateMap();
};

END_CONTROLLER_NAMESPACE