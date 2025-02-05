#include "Projectile.h"

BEGIN_ENTITY_NAMESPACE

Projectile::Projectile( const sf::Vector2f& position, const sf::Vector2f& direction, float speed ) :
    _direction( direction ), _speed( speed ) {
    _shape.setRadius( 5.0f );
    _shape.setFillColor( sf::Color::Yellow );
    _shape.setPosition( position );
}

Projectile::~Projectile() {
}

void Projectile::update( const sf::Time& deltaTime ) {
    sf::Vector2f movement = _direction * _speed * deltaTime.asSeconds();
    _shape.move( movement );
}

void Projectile::render( sf::RenderWindow& window ) {
    window.draw( _shape );
}

sf::Vector2f Projectile::getPosition() const {
    return _shape.getPosition();
}

sf::FloatRect Projectile::getGlobalBounds() const {
    return _shape.getGlobalBounds();
}

bool Projectile::isOutOfBounds( int width, int height ) const {
    sf::Vector2f position = _shape.getPosition();
    return position.x < 0 || position.x > width || position.y < 0 || position.y > height;
}

END_ENTITY_NAMESPACE