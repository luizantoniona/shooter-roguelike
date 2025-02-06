#pragma once

#include <Entity/EntityGlobals.h>

BEGIN_ENTITY_NAMESPACE

class PlayerStatus {
public:
    PlayerStatus();

    void setHealth( const int health );
    int getHealth() const;

    void setGold( const int gold );
    int getGold() const;

    void setSpeed( const float speed );
    float getSpeed() const;

private:
    int _health;
    int _gold;
    float _speed;
};

END_ENTITY_NAMESPACE
