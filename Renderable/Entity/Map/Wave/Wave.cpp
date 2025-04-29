#include "Wave.h"

BEGIN_ENTITY_NAMESPACE

Wave::Wave() {
}

Wave::~Wave() {
}

std::vector<WaveEnemyInfo> Wave::getEnemies() const {
    return _enemies;
}

void Wave::setEnemies( const std::vector<WaveEnemyInfo>& enemies ) {
    _enemies = enemies;
}

void Wave::addEnemy( const WaveEnemyInfo& enemy ) {
    _enemies.push_back( enemy );
}

END_ENTITY_NAMESPACE