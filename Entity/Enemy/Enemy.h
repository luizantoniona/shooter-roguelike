#pragma once

#include <SFML/Graphics.hpp>

#include <Entity/EntityGlobals.h>

#include <Entity/Shape.h>

BEGIN_ENTITY_NAMESPACE

class Enemy : public Shape {
public:
    Enemy();
    ~Enemy();

    void setHealth( int health );
    int getHealth() const;

    void setSpeed( float speed );
    float getSpeed() const;

    void update( sf::Time& deltaTime );
    void render( sf::RenderWindow& window );

private:
    int _health;
    float _speed;
};

END_ENTITY_NAMESPACE