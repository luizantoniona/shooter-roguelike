#include "Enemy.h"

#include <cmath>

BEGIN_ENTITY_NAMESPACE

Enemy::Enemy( Player* player ) :
    Shape(),
    _player( player ) {
}

Enemy::~Enemy() {
}

std::unique_ptr<Enemy> Enemy::clone() const {
    return std::make_unique<Enemy>( *this );
}

void Enemy::setHealth( int health ) {
    _health = health;
}

int Enemy::getHealth() const {
    return _health;
}

void Enemy::setSpeed( float speed ) {
    _speed = speed;
}

float Enemy::getSpeed() const {
    return _speed;
}

void Enemy::update( sf::Time& deltaTime ) {

    sf::Vector2f direction = _player->getPosition() - getPosition();
    float length = std::hypot( direction.x, direction.y );

    if ( length > 0.0f ) {
        direction /= length;
        move( direction * _speed * deltaTime.asSeconds() );
    }
}

void Enemy::render( sf::RenderWindow& window ) {
    Shape::render( window );
}

END_ENTITY_NAMESPACE