#include "Enemy.h"

BEGIN_ENTITY_NAMESPACE

Enemy::Enemy( int sides, float radius, const sf::Vector2f& position, const sf::Color& color )
    : Shape( sides, radius, position, color ) {
}

Enemy::~Enemy() {
}

void Enemy::update( sf::Time& deltaTime ) {
    sf::Vector2f offset( ( std::rand() % 3 - 1 ) * 10 * deltaTime.asSeconds(),
                         ( std::rand() % 3 - 1 ) * 10 * deltaTime.asSeconds() );
    move( offset );
}

void Enemy::render( sf::RenderWindow& window ) {
    Shape::render( window );
}

END_ENTITY_NAMESPACE