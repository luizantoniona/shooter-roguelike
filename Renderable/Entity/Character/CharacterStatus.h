#pragma once

#include <Entity/EntityGlobals.h>

BEGIN_ENTITY_NAMESPACE

class CharacterStatus {
public:
    CharacterStatus();

    void setHealth( const int health );
    int getHealth() const;

    void setGold( const int gold );
    int getGold() const;

    void setSpeed( const float speed );
    float getSpeed() const;

    void setAttack( const int attack );
    int getAttack() const;

private:
    float _speed;
    int _health;
    int _gold;
    int _attack;
};

END_ENTITY_NAMESPACE