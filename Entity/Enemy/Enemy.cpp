#include "Enemy.h"

#include <cmath>

BEGIN_ENTITY_NAMESPACE

Enemy::Enemy( Player& player ) :
    BaseEntity(),
    _player( player ) {
}

Enemy::~Enemy() {
}

std::unique_ptr<Enemy> Enemy::clone() const {
    return std::make_unique<Enemy>( *this );
}

void Enemy::setHealth( const int health ) {
    _health = health;
}

int Enemy::getHealth() const {
    return _health;
}

void Enemy::setAttack( const int attack ) {
    _attack = attack;
}

int Enemy::getAttack() const {
    return _attack;
}

void Enemy::setSpeed( const float speed ) {
    _speed = speed;
}

float Enemy::getSpeed() const {
    return _speed;
}

void Enemy::update( const sf::RenderWindow& window, const sf::Time& deltaTime ) {

    sf::Vector2f direction = _player.getShape().getPosition() - _shape.getPosition();
    float length = std::hypot( direction.x, direction.y );

    if ( length > 0.0f ) {
        direction /= length;
        _shape.move( direction * _speed * deltaTime.asSeconds() );
    }
}

END_ENTITY_NAMESPACE