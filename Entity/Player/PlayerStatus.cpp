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

void PlayerStatus::setGold( int gold ) {
    _gold = gold;
}

int PlayerStatus::getGold() const {
    return _gold;
}

END_ENTITY_NAMESPACE