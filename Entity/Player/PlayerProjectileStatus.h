#pragma once

#include <Entity/EntityGlobals.h>

BEGIN_ENTITY_NAMESPACE

class PlayerProjectileStatus {
public:
    PlayerProjectileStatus();

    void setProjectileFireRate( float projectileFireRate );
    float getProjectileFireRate() const;

    void setProjectileSpeed( float projectileSpeed );
    float getProjectileSpeed() const;

    void setProjectileSize( float projectileSize );
    float getProjectileSize() const;

    void setProjectileDamage( float projectileDamage );
    float getProjectileDamage() const;

private:
    float _projectileFireRate;
    float _projectileSpeed;
    float _projectileSize;
    float _projectileDamage;
};

END_ENTITY_NAMESPACE
