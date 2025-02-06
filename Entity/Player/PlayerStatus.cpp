#include "PlayerStatus.h"

BEGIN_ENTITY_NAMESPACE

PlayerStatus::PlayerStatus() :
    _health( 0 ),
    _gold( 0 ),
    _speed( 0.0 ) {
}

void PlayerStatus::setHealth( const int health ) {
    _health = health;
}

int PlayerStatus::getHealth() const {
    return _health;
}

void PlayerStatus::setGold( const int gold ) {
    _gold = gold;
}

int PlayerStatus::getGold() const {
    return _gold;
}

void PlayerStatus::setSpeed( const float speed ) {
    _speed = speed;
}

float PlayerStatus::getSpeed() const {
    return _speed;
}

END_ENTITY_NAMESPACE