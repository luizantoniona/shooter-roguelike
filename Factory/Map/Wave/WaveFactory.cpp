#include "WaveFactory.h"

#include <Entity/Map/Wave/WaveEnemyInfo.h>

using Entities::WaveEnemyInfo;

namespace {
constexpr const char* ENEMIES_KEY = "enemies";
constexpr const char* AMOUNT_KEY = "amount";
constexpr const char* TYPE_KEY = "type";
} // namespace

BEGIN_FACTORY_NAMESPACE

std::queue<Wave> WaveFactory::generateWaves( Json::Value& wavesJson ) {
    std::queue<Wave> waves;

    for ( auto& waveJson : wavesJson ) {
        Wave wave;

        for ( auto& enemyJson : waveJson[ ENEMIES_KEY ] ) {
            WaveEnemyInfo enemyInfo;
            enemyInfo.setAmount( enemyJson[ AMOUNT_KEY ].asInt() );
            enemyInfo.setEnemyType( enemyJson[ TYPE_KEY ].asString() );

            wave.addEnemy( enemyInfo );
        }

        waves.push( wave );
    }

    return waves;
}

END_FACTORY_NAMESPACE