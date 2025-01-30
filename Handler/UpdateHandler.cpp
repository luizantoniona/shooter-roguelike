#include "UpdateHandler.h"

BEGIN_HANDLER_NAMESPACE

void UpdateHandler::update( sf::Time& deltaTime, Entity::Player& player, std::vector<Entity::Enemy>& enemies,
                            Entity::Map& map ) {
    player.update( deltaTime );

    for ( auto& enemy : enemies ) {
        enemy.update( deltaTime );
    }

    map.update( deltaTime );

    checkCollisions( player, enemies );
}

void UpdateHandler::checkCollisions( Entity::Player& player, std::vector<Entity::Enemy>& enemies ) {
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

END_HANDLER_NAMESPACE