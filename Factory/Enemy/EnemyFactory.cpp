#include "EnemyFactory.h"

namespace {
constexpr const float DEFAULT_SPAWN_SIZE = 20.0f;
}

BEGIN_FACTORY_NAMESPACE

Enemy* EnemyFactory::createEnemy( int health, int speed, int sides, float radius, const sf::Color& color, const sf::Vector2f& position ) {
    Enemy* enemy = new Enemy();
    enemy->setHealth( health );
    enemy->setSpeed( speed );
    enemy->setSides( sides );
    enemy->setRadius( radius * DEFAULT_SPAWN_SIZE );
    enemy->setColor( color );
    enemy->setPosition( position );
    enemy->build();
    return enemy;
}

END_FACTORY_NAMESPACE