#include "WaveEnemyInfo.h"

BEGIN_ENTITY_NAMESPACE

WaveEnemyInfo::WaveEnemyInfo() :
    _amount( 0 ),
    _enemyType( "" ) {
}

WaveEnemyInfo::~WaveEnemyInfo() {
}

int WaveEnemyInfo::getAmount() const {
    return _amount;
}

void WaveEnemyInfo::setAmount( const int amount ) {
    _amount = amount;
}

std::string WaveEnemyInfo::getEnemyType() const {
    return _enemyType;
}

void WaveEnemyInfo::setEnemyType( const std::string& enemyType ) {
    _enemyType = enemyType;
}

END_ENTITY_NAMESPACE