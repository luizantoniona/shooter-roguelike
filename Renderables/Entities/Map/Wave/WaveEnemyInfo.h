#pragma once

#include <string>

#include <Renderables/Entities/EntitiesGlobals.h>

BEGIN_ENTITIES_NAMESPACE

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

END_ENTITIES_NAMESPACE