#include "Collisioner.h"

BEGIN_CONTROLLER_NAMESPACE

void Collisioner::checkCollisions( Entities::Character& player, std::vector<std::unique_ptr<Entities::Character>>& enemies ) {
    handleProjectileCollisions( player, enemies );
    handlePlayerCollisions( player, enemies );
}

void Collisioner::handleProjectileCollisions( Entities::Character& player, std::vector<std::unique_ptr<Entities::Character>>& enemies ) {
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

void Collisioner::handlePlayerCollisions( Entities::Character& player, std::vector<std::unique_ptr<Entities::Character>>& enemies ) {
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