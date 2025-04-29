#pragma once

#include <Controller/ControllerGlobals.h>

#include <Renderables/Entities/Character/Character.h>
#include <Renderables/Entities/Map/Map.h>

BEGIN_CONTROLLER_NAMESPACE

class EnemyController {
public:
    static void updateEnemies( sf::RenderWindow& window, const sf::Time& deltaTime, Entities::Character& player, std::vector<std::unique_ptr<Entities::Character>>& enemies );
};

END_CONTROLLER_NAMESPACE
