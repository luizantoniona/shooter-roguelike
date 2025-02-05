#pragma once

#include <SFML/Graphics.hpp>

#include <Entity/EntityGlobals.h>

BEGIN_ENTITY_NAMESPACE

class Projectile {
public:
    Projectile( const sf::Vector2f& position, const sf::Vector2f& direction, float speed );
    ~Projectile();

    void update( const sf::Time& deltaTime );
    void render( sf::RenderWindow& window );

    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBounds() const;

    bool isOutOfBounds( int width, int height ) const;

private:
    sf::CircleShape _shape;
    sf::Vector2f _direction;
    float _speed;
};

END_ENTITY_NAMESPACE