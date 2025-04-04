#pragma once

#include <Controller/ControllerGlobals.h>

#include <Entity/Character/Character.h>
#include <Entity/Map/Map.h>

BEGIN_CONTROLLER_NAMESPACE

class EnemyController {
public:
    static void updateEnemies( sf::RenderWindow& window, const sf::Time& deltaTime, Entities::Character& player, std::vector<std::unique_ptr<Entities::Character>>& enemies );
};

END_CONTROLLER_NAMESPACE