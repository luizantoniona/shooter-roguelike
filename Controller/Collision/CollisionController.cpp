#include "CollisionController.h"

BEGIN_CONTROLLER_NAMESPACE

void CollisionController::checkCollisions( Entity::Player& player, std::vector<std::unique_ptr<Enemy>>& enemies ) {
    auto& projectiles = player.getProjectiles();
    for ( auto it = projectiles.begin(); it != projectiles.end(); ) {
        bool hit = false;
        for ( auto enemyIt = enemies.begin(); enemyIt != enemies.end(); ) {
            if ( enemyIt->get()->getShape().getGlobalBounds().intersects( it->getGlobalBounds() ) ) {
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