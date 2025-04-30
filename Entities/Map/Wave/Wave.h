#pragma once

#include <vector>

#include <Renderables/Entities/EntitiesGlobals.h>

#include <Renderables/Entities/Map/Wave/WaveEnemyInfo.h>

BEGIN_ENTITIES_NAMESPACE

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

END_ENTITIES_NAMESPACE
