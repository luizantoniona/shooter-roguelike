#include "Projectile.h"

BEGIN_ENTITY_NAMESPACE

Projectile::Projectile() :
    _damage( 0.0 ),
    _speed( 0.0 ),
    _direction() {
}

void Projectile::setDamage( float damage ) {
    _damage = damage;
}

float Projectile::getDamage() const {
    return _damage;
}

void Projectile::setSpeed( float speed ) {
    _speed = speed;
}

float Projectile::getSpeed() const {
    return _speed;
}

void Projectile::setDirection( sf::Vector2f direction ) {
    _direction = direction;
}

sf::Vector2f Projectile::getDirection() const {
    return _direction;
}

void Projectile::update( const sf::RenderWindow& window, const sf::Time& deltaTime ) {
    sf::Vector2f movement = _direction * _speed * deltaTime.asSeconds();
    _shape.move( movement );
}

sf::FloatRect Projectile::getGlobalBounds() const {
    return _shape.getGlobalBounds();
}

bool Projectile::isOutOfBounds( int width, int height ) const {
    sf::Vector2f position = _shape.getPosition();
    return position.x < 0 || position.x > width || position.y < 0 || position.y > height;
}

END_ENTITY_NAMESPACE