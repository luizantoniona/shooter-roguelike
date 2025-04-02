#include "GameController.h"

#include <cmath>

#include <Controller/Game/Collision/CollisionController.h>
#include <Controller/Game/Enemy/EnemyController.h>
#include <Controller/Game/Player/PlayerController.h>
#include <Controller/Game/Spawn/SpawnController.h>

BEGIN_CONTROLLER_NAMESPACE

void GameController::update( sf::RenderWindow& window, const sf::Time& deltaTime, Entities::Character& player, std::vector<std::unique_ptr<Entities::Character>>& enemies, Entities::Map& map ) {

    PlayerController::updatePlayer( window, deltaTime, player, map );
    EnemyController::updateEnemies( window, deltaTime, player, enemies );

    // map.update( deltaTime );

    CollisionController::checkCollisions( player, enemies );
    SpawnController::spawn( map, enemies, player );
}

END_CONTROLLER_NAMESPACE