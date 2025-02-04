#pragma once

#include <string>

#include <Entity/EntityGlobals.h>

BEGIN_ENTITY_NAMESPACE

class WaveEnemyInfo {
public:
    WaveEnemyInfo();
    ~WaveEnemyInfo();

    int getAmount() const;
    void setAmount( const int amount );

    int getHealth() const;
    void setHealth( const int health );

    int getSpeed() const;
    void setSpeed( const int speed );

    int getSides() const;
    void setSides( const int sides );

    int getSize() const;
    void setSize( const int size );

    std::string getColor() const;
    void setColor( const std::string& color );

private:
    int _amount;
    int _health;
    int _speed;
    int _sides;
    int _size;
    std::string _color;
};

END_ENTITY_NAMESPACE