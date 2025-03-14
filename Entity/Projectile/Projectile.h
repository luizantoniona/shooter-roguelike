#pragma once

#include <SFML/Graphics.hpp>

#include <Entity/EntityGlobals.h>

#include <Entity/BaseEntity.h>

BEGIN_ENTITY_NAMESPACE

class Projectile : public BaseEntity {
public:
    Projectile();

    void setDamage( float damage );
    float getDamage() const;

    void setSpeed( float speed );
    float getSpeed() const;

    void setDirection( sf::Vector2f direction );
    sf::Vector2f getDirection() const;

    void update( const sf::RenderWindow& window, const sf::Time& deltaTime ) override;

    sf::FloatRect getGlobalBounds() const;

    bool isOutOfBounds( int width, int height ) const;

private:
    float _damage;
    float _speed;
    sf::Vector2f _direction;
};

END_ENTITY_NAMESPACE