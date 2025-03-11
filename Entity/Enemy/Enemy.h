#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include <Entity/EntityGlobals.h>

#include <Entity/BaseEntity.h>
#include <Entity/Player/Player.h>

BEGIN_ENTITY_NAMESPACE

class Enemy : public BaseEntity {
public:
    Enemy( Player& player );
    ~Enemy();

    std::unique_ptr<Enemy> clone() const;

    void setSpeed( float speed );
    float getSpeed() const;

    void setHealth( int health );
    int getHealth() const;

    void update( const sf::RenderWindow& window, const sf::Time& deltaTime ) override;

private:
    Player& _player;
    float _speed;
    int _health;
};

END_ENTITY_NAMESPACE