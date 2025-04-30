#pragma once

#include <SFML/Graphics.hpp>

#include <Entities/EntitiesGlobals.h>

#include <Entities/Entity.h>

BEGIN_ENTITIES_NAMESPACE

class Projectile : public Entity {
public:
    Projectile();

    void setDamage( float damage );
    float getDamage() const;

    void setSpeed( float speed );
    float getSpeed() const;

    void setDirection( sf::Vector2f direction );
    sf::Vector2f getDirection() const;

    sf::FloatRect getGlobalBounds() const;

    bool isOutOfBounds( int width, int height ) const;

private:
    float _damage;
    float _speed;
    sf::Vector2f _direction;
};

END_ENTITIES_NAMESPACE
