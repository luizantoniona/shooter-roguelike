#include "CharacterProjectileStatus.h"

BEGIN_ENTITY_NAMESPACE

CharacterProjectileStatus::CharacterProjectileStatus() :
    _projectileFireRate( 0.0f ),
    _projectileSpeed( 0.0f ),
    _projectileSize( 0.0f ),
    _projectileDamage( 0.0f ) {
}

void CharacterProjectileStatus::setProjectileDamage( const int projectileDamage ) {
    _projectileDamage = projectileDamage;
}

int CharacterProjectileStatus::getProjectileDamage() const {
    return _projectileDamage;
}

void CharacterProjectileStatus::setProjectileFireRate( const float projectileFireRate ) {
    _projectileFireRate = projectileFireRate;
}

float CharacterProjectileStatus::getProjectileFireRate() const {
    return _projectileFireRate;
}

void CharacterProjectileStatus::setProjectileSpeed( const float projectileSpeed ) {
    _projectileSpeed = projectileSpeed;
}

float CharacterProjectileStatus::getProjectileSpeed() const {
    return _projectileSpeed;
}

void CharacterProjectileStatus::setProjectileSize( const float projectileSize ) {
    _projectileSize = projectileSize;
}

float CharacterProjectileStatus::getProjectileSize() const {
    return _projectileSize;
}

END_ENTITY_NAMESPACE