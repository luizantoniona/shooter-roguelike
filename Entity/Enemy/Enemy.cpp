#include "Enemy.h"

BEGIN_ENTITY_NAMESPACE

Enemy::Enemy() :
    Shape() {
}

Enemy::~Enemy() {
}

void Enemy::setHealth( int health ) {
    _health = health;
}

int Enemy::getHealth() const {
    return _health;
}

void Enemy::setSpeed( int speed ) {
    _speed = speed;
}

int Enemy::getSpeed() const {
    return _speed;
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