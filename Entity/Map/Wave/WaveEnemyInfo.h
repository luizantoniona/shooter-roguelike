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

    std::string getEnemyType() const;
    void setEnemyType( const std::string& enemyType );

private:
    int _amount;
    std::string _enemyType;
};

END_ENTITY_NAMESPACE