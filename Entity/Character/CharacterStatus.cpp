#include "CharacterStatus.h"

BEGIN_ENTITY_NAMESPACE

CharacterStatus::CharacterStatus() :
    _health( 0 ),
    _gold( 0 ),
    _speed( 0.0 ) {
}

void CharacterStatus::setHealth( const int health ) {
    _health = health;
}

int CharacterStatus::getHealth() const {
    return _health;
}

void CharacterStatus::setGold( const int gold ) {
    _gold = gold;
}

int CharacterStatus::getGold() const {
    return _gold;
}

void CharacterStatus::setSpeed( const float speed ) {
    _speed = speed;
}

float CharacterStatus::getSpeed() const {
    return _speed;
}

END_ENTITY_NAMESPACE