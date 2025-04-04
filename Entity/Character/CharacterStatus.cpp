#include "CharacterStatus.h"

BEGIN_ENTITY_NAMESPACE

CharacterStatus::CharacterStatus() :
    _speed( 0.0 ),
    _health( 0 ),
    _gold( 0 ),
    _attack( 0 ) {
}

void CharacterStatus::setSpeed( const float speed ) {
    _speed = speed;
}

float CharacterStatus::getSpeed() const {
    return _speed;
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

void CharacterStatus::setAttack( const int attack ) {
    _attack = attack;
}

int CharacterStatus::getAttack() const {
    return _attack;
}

END_ENTITY_NAMESPACE