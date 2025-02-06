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

    int getSides() const;
    void setSides( const int sides );

    float getSpeed() const;
    void setSpeed( const float speed );

    float getSize() const;
    void setSize( const float size );

    std::string getColor() const;
    void setColor( const std::string& color );

private:
    int _amount;
    int _health;
    int _sides;
    float _speed;
    float _size;
    std::string _color;
};

END_ENTITY_NAMESPACE