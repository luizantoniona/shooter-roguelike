#include "WaveFactory.h"

#include <Entity/Map/Wave/WaveEnemyInfo.h>

using Entity::WaveEnemyInfo;

namespace {
constexpr const char* ENEMIES_KEY = "enemies";
constexpr const char* AMOUNT_KEY = "amount";
constexpr const char* HEALTH_KEY = "health";
constexpr const char* SPEED_KEY = "speed";
constexpr const char* SIDES_KEY = "sides";
constexpr const char* SIZE_KEY = "size";
constexpr const char* COLOR_KEY = "color";
} // namespace

BEGIN_FACTORY_NAMESPACE

std::queue<Wave> WaveFactory::generateWaves( Json::Value& wavesJson ) {
    std::queue<Wave> waves;

    for ( auto& waveJson : wavesJson ) {
        Wave wave;

        for ( auto& enemyJson : waveJson[ ENEMIES_KEY ] ) {
            WaveEnemyInfo enemyInfo;
            enemyInfo.setAmount( enemyJson[ AMOUNT_KEY ].asInt() );
            enemyInfo.setHealth( enemyJson[ HEALTH_KEY ].asInt() );
            enemyInfo.setSpeed( enemyJson[ SPEED_KEY ].asInt() );
            enemyInfo.setSides( enemyJson[ SIDES_KEY ].asInt() );
            enemyInfo.setSize( enemyJson[ SIZE_KEY ].asInt() );
            enemyInfo.setColor( enemyJson[ COLOR_KEY ].asString() );

            wave.addEnemy( enemyInfo );
        }

        waves.push( wave );
    }

    return waves;
}

END_FACTORY_NAMESPACE