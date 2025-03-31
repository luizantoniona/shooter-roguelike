#include "CollisionController.h"

BEGIN_CONTROLLER_NAMESPACE

void CollisionController::checkCollisions( Player& player, std::vector<std::unique_ptr<Enemy>>& enemies ) {
    handleProjectileCollisions( player, enemies );
    handlePlayerCollisions( player, enemies );
}

void CollisionController::handleProjectileCollisions( Player& player, std::vector<std::unique_ptr<Enemy>>& enemies ) {
    auto& projectiles = player.getProjectiles();

    for ( auto projectileIt = projectiles.begin(); projectileIt != projectiles.end(); ) {
        bool hit = false;

        for ( auto enemyIt = enemies.begin(); enemyIt != enemies.end(); ) {
            if ( enemyIt->get()->getShape().getGlobalBounds().intersects( projectileIt->getGlobalBounds() ) ) {

                enemyIt = enemies.erase( enemyIt );

                hit = true;
                break;

            } else {
                ++enemyIt;
            }
        }

        if ( hit ) {
            projectileIt = projectiles.erase( projectileIt );

        } else {
            ++projectileIt;
        }
    }
}

void CollisionController::handlePlayerCollisions( Player& player, std::vector<std::unique_ptr<Enemy>>& enemies ) {
    for ( auto enemyIt = enemies.begin(); enemyIt != enemies.end(); ) {
        if ( enemyIt->get()->getShape().getGlobalBounds().intersects( player.getShape().getGlobalBounds() ) ) {

            auto& playerStatus = player.getPlayerStatus();
            int currentHealth = playerStatus.getHealth();

            playerStatus.setHealth( currentHealth - enemyIt->get()->getAttack() );

            enemyIt = enemies.erase( enemyIt );

        } else {
            ++enemyIt;
        }
    }
}

END_CONTROLLER_NAMESPACE