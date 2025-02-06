#pragma once

#include <Entity/EntityGlobals.h>

BEGIN_ENTITY_NAMESPACE

class PlayerProjectileStatus {
public:
    PlayerProjectileStatus();

    void setProjectileDamage( const int projectileDamage );
    int getProjectileDamage() const;

    void setProjectileFireRate( const float projectileFireRate );
    float getProjectileFireRate() const;

    void setProjectileSpeed( const float projectileSpeed );
    float getProjectileSpeed() const;

    void setProjectileSize( const float projectileSize );
    float getProjectileSize() const;

private:
    int _projectileDamage;
    float _projectileFireRate;
    float _projectileSpeed;
    float _projectileSize;
};

END_ENTITY_NAMESPACE
