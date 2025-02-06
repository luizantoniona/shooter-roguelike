#include "PlayerProjectileStatus.h"

BEGIN_ENTITY_NAMESPACE

PlayerProjectileStatus::PlayerProjectileStatus() :
    _projectileFireRate( 0.0f ),
    _projectileSpeed( 0.0f ),
    _projectileSize( 0.0f ),
    _projectileDamage( 0.0f ) {
}

void PlayerProjectileStatus::setProjectileDamage( const int projectileDamage ) {
    _projectileDamage = projectileDamage;
}

int PlayerProjectileStatus::getProjectileDamage() const {
    return _projectileDamage;
}

void PlayerProjectileStatus::setProjectileFireRate( const float projectileFireRate ) {
    _projectileFireRate = projectileFireRate;
}

float PlayerProjectileStatus::getProjectileFireRate() const {
    return _projectileFireRate;
}

void PlayerProjectileStatus::setProjectileSpeed( const float projectileSpeed ) {
    _projectileSpeed = projectileSpeed;
}

float PlayerProjectileStatus::getProjectileSpeed() const {
    return _projectileSpeed;
}

void PlayerProjectileStatus::setProjectileSize( const float projectileSize ) {
    _projectileSize = projectileSize;
}

float PlayerProjectileStatus::getProjectileSize() const {
    return _projectileSize;
}

END_ENTITY_NAMESPACE