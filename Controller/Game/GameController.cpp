#include "GameController.h"

#include <cmath>

#include <Controller/Game/Collision/CollisionController.h>
#include <Controller/Game/Enemy/EnemyController.h>
#include <Controller/Game/Player/PlayerController.h>
#include <Controller/Game/Spawn/SpawnController.h>

BEGIN_CONTROLLER_NAMESPACE

void GameController::update( sf::RenderWindow& window, const sf::Time& deltaTime, Entities::Character& player, std::vector<std::unique_ptr<Entities::Character> >& enemies, Entities::Map& map, GameState& gameState ) {

    if ( gameState != GameState::PLAYING ) {
        return;
    }

    PlayerController::updatePlayer( window, deltaTime, player, map );
    EnemyController::updateEnemies( window, deltaTime, player, enemies );

    // map.update( deltaTime );

    CollisionController::checkCollisions( player, enemies );
    SpawnController::spawn( map, enemies, player );

    updateGameState( player, enemies, map, gameState );
}

void GameController::updateGameState( Entities::Character& player, std::vector<std::unique_ptr<Entities::Character> >& enemies, Entities::Map& map, GameState& gameState ) {
    if ( player.getStatus().getHealth() <= 0 ) {
        gameState = GameState::GAME_OVER;
        return;
    }

    if ( map.getWaves().empty() ) {
        gameState = GameState::VICTORY;
        return;
    }
}

END_CONTROLLER_NAMESPACE
