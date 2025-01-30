#include "Enemy.h"

BEGIN_ENTITY_NAMESPACE

Enemy::Enemy( int sides, float radius, const sf::Vector2f& position, const sf::Color& color )
    : Shape( sides, radius, position, color ) {
}

Enemy::~Enemy() {
}

void Enemy::update() {
}

void Enemy::render( sf::RenderWindow& window ) {
    Shape::render( window );
}

END_ENTITY_NAMESPACE