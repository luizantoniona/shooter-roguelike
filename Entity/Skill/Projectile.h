#pragma once

#include <SFML/Graphics.hpp>

#include <Entity/EntityGlobals.h>
#include <SFML/System/Vector2.hpp>

BEGIN_ENTITY_NAMESPACE

class Projectile {
public:
    Projectile();

    void setDamage( float damage );
    float getDamage() const;

    void setSpeed( float speed );
    float getSpeed() const;

    void setSize( float size );
    float getSize() const;

    void setDirection( sf::Vector2f direction );
    sf::Vector2f getDirection() const;

    void setPosition( sf::Vector2f position );
    sf::Vector2f getPosition() const;

    void build();

    void update( const sf::Time& deltaTime );
    void render( sf::RenderWindow& window );

    sf::FloatRect getGlobalBounds() const;

    bool isOutOfBounds( int width, int height ) const;

private:
    float _damage;
    float _speed;
    float _size;
    sf::Vector2f _direction;
    sf::CircleShape _shape;
};

END_ENTITY_NAMESPACE