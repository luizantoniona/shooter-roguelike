#include "PlayerStatus.h"

BEGIN_ENTITY_NAMESPACE

PlayerStatus::PlayerStatus() {
}

void PlayerStatus::setHealth( int health ) {
    _health = health;
}

int PlayerStatus::getHealth() const {
    return _health;
}

void PlayerStatus::setSpeed( int speed ) {
    _speed = speed;
}

int PlayerStatus::getSpeed() const {
    return _speed;
}

void PlayerStatus::setFireRate( float fireRate ) {
    _fireRate = fireRate;
}

float PlayerStatus::getFireRate() const {
    return _fireRate;
}

void PlayerStatus::setProjectileSpeed( float projectileSpeed ) {
    _projectileSpeed = projectileSpeed;
}

float PlayerStatus::getProjectileSpeed() const {
    return _projectileSpeed;
}

void PlayerStatus::setProjectileSize( float projectileSize ) {
    _projectileSize = projectileSize;
}

float PlayerStatus::getProjectileSize() const {
    return _projectileSize;
}

void PlayerStatus::setProjectileDamage( float projectileDamage ) {
    _projectileDamage = projectileDamage;
}

float PlayerStatus::getProjectileDamage() const {
    return _projectileDamage;
}

END_ENTITY_NAMESPACE