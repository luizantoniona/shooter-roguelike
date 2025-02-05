#pragma once

#include <Entity/EntityGlobals.h>

BEGIN_ENTITY_NAMESPACE

class PlayerStatus {
public:
    PlayerStatus();

    void setHealth( int health );
    int getHealth() const;

    void setSpeed( int speed );
    int getSpeed() const;

    void setFireRate( float fireRate );
    float getFireRate() const;

    void setProjectileSpeed( float projectileSpeed );
    float getProjectileSpeed() const;

    void setProjectileSize( float projectileSize );
    float getProjectileSize() const;

    void setProjectileDamage( float projectileDamage );
    float getProjectileDamage() const;

private:
    int _health;
    int _speed;
    float _fireRate;
    float _projectileSpeed;
    float _projectileSize;
    float _projectileDamage;
};

END_ENTITY_NAMESPACE
