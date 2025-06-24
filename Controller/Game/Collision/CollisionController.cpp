#include "CollisionController.h"

BEGIN_CONTROLLER_NAMESPACE

void CollisionController::checkCollisions( Entities::Character& player, std::vector<std::unique_ptr<Entities::Character> >& enemies ) {
    handleProjectileCollisions( player, enemies );
    handlePlayerCollisions( player, enemies );
}

void CollisionController::handleProjectileCollisions( Entities::Character& player, std::vector<std::unique_ptr<Entities::Character> >& enemies ) {
    auto& projectiles = player.getProjectiles();

    for ( auto projectileIt = projectiles.begin(); projectileIt != projectiles.end(); ) {
        bool hit = false;

        for ( auto enemyIt = enemies.begin(); enemyIt != enemies.end(); ) {

            if ( enemyIt->get()->getShape().getGlobalBounds().intersects( projectileIt->get()->getShape().getGlobalBounds() ) ) {

                auto& enemyStatus = enemyIt->get()->getStatus();
                enemyStatus.setHealth( enemyStatus.getHealth() - player.getProjectileStatus().getProjectileDamage() );

                if ( enemyStatus.getHealth() <= 0 ) {
                    enemyIt = enemies.erase( enemyIt );

                } else {
                    ++enemyIt;
                }

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

void CollisionController::handlePlayerCollisions( Entities::Character& player, std::vector<std::unique_ptr<Entities::Character> >& enemies ) {
    for ( auto enemyIt = enemies.begin(); enemyIt != enemies.end(); ) {
        if ( enemyIt->get()->getShape().getGlobalBounds().intersects( player.getShape().getGlobalBounds() ) ) {

            auto& playerStatus = player.getStatus();
            int currentHealth = playerStatus.getHealth();

            playerStatus.setHealth( currentHealth - enemyIt->get()->getStatus().getAttack() );

            enemyIt = enemies.erase( enemyIt );

        } else {
            ++enemyIt;
        }
    }
}

END_CONTROLLER_NAMESPACE
