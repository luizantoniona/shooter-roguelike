#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include <Entity/EntityGlobals.h>

#include <Entity/Player/Player.h>
#include <Entity/Shape.h>

BEGIN_ENTITY_NAMESPACE

class Enemy : public Shape {
public:
    Enemy( Player* player );
    ~Enemy();

    std::unique_ptr<Enemy> clone() const;

    void setHealth( int health );
    int getHealth() const;

    void setSpeed( float speed );
    float getSpeed() const;

    void update( sf::Time& deltaTime );
    void render( sf::RenderWindow& window );

private:
    Player* _player;
    int _health;
    float _speed;
};

END_ENTITY_NAMESPACE