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

private:
    float _speed;
    int _health;
    int _gold;
};

END_ENTITY_NAMESPACE