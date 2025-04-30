#include "EnemyController.h"

#include <cmath>

BEGIN_CONTROLLER_NAMESPACE

void EnemyController::updateEnemies( sf::RenderWindow& window, const sf::Time& deltaTime, Entities::Character& player, std::vector<std::unique_ptr<Entities::Character>>& enemies ) {

    for ( auto& enemy : enemies ) {
        sf::Vector2f direction = player.getShape()->getPosition() - enemy->getShape()->getPosition();
        float length = std::hypot( direction.x, direction.y );

        if ( length > 0.0f ) {
            direction /= length;
            enemy->getShape()->move( direction * enemy->getStatus().getSpeed() * deltaTime.asSeconds() );
        }
    }
}

END_CONTROLLER_NAMESPACE
