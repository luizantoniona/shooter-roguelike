#pragma once

#include <Entity/EntityGlobals.h>

BEGIN_ENTITY_NAMESPACE

class PlayerStatus {
public:
    PlayerStatus();

    void setHealth( int health );
    int getHealth() const;

    void setSpeed( int speed );
    int getSpeed() const;

    void setGold( int gold );
    int getGold() const;

private:
    int _health;
    int _speed;
    int _gold;
};

END_ENTITY_NAMESPACE
