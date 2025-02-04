#pragma once

#include <vector>

#include <Entity/EntityGlobals.h>

#include <Entity/Map/Wave/WaveEnemyInfo.h>

BEGIN_ENTITY_NAMESPACE

class Wave {
public:
    Wave();
    ~Wave();

    std::vector<WaveEnemyInfo> getEnemies() const;
    void setEnemies( const std::vector<WaveEnemyInfo>& enemies );
    void addEnemy( const WaveEnemyInfo& enemy );

private:
    std::vector<WaveEnemyInfo> _enemies;
};

END_ENTITY_NAMESPACE