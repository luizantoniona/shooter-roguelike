#include "Projectile.h"

BEGIN_ENTITIES_NAMESPACE

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

bool Projectile::isOutOfBounds( int width, int height ) const {
    sf::Vector2f position = _shape->getPosition();
    return position.x < 0 || position.x > width || position.y < 0 || position.y > height;
}

END_ENTITIES_NAMESPACE
