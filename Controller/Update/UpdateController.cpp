#include "UpdateController.h"

BEGIN_CONTROLLER_NAMESPACE

void UpdateController::update( sf::RenderWindow& window, sf::Time& deltaTime, Entity::Player& player,
                               std::vector<Entity::Enemy>& enemies, Entity::Map& map ) {
    player.update( window, deltaTime );

    for ( auto& enemy : enemies ) {
        enemy.update( deltaTime );
    }

    map.update( deltaTime );

    checkCollisions( player, enemies );
}

void UpdateController::checkCollisions( Entity::Player& player, std::vector<Entity::Enemy>& enemies ) {
    auto& projectiles = player.getProjectiles();
    for ( auto it = projectiles.begin(); it != projectiles.end(); ) {
        bool hit = false;
        for ( auto enemyIt = enemies.begin(); enemyIt != enemies.end(); ) {
            if ( enemyIt->getGlobalBounds().intersects( it->getGlobalBounds() ) ) {
                enemyIt = enemies.erase( enemyIt );
                hit = true;
                break;
            } else {
                ++enemyIt;
            }
        }
        if ( hit ) {
            it = projectiles.erase( it );
        } else {
            ++it;
        }
    }
}

END_CONTROLLER_NAMESPACE