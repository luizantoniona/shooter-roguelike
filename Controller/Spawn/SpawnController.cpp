#include "SpawnController.h"

#include <Map/Wave/Wave.h>
#include <Map/Wave/WaveEnemyInfo.h>

using Entity::Wave;
using Entity::WaveEnemyInfo;

namespace {
constexpr double SPAWN_RADIUS = 20.0;
}

BEGIN_CONTROLLER_NAMESPACE

void SpawnController::checkSpawn( Map& map, std::vector<Enemy>& enemies ) {

    if ( enemies.size() > 0 ) {
        return;
    }

    Wave currrentWave = map.getWaves().front();

    for ( WaveEnemyInfo& enemyInfo : currrentWave.getEnemies() ) {

        for ( int i = 0; i < enemyInfo.getAmount(); ++i ) {

            sf::Vector2f position( std::rand() % map.getWidth(), std::rand() % map.getHeight() );
            if ( map.isInsideBounds( position ) ) {

                // TODO: USE EnemyFactory to generate enemies
                enemies.emplace_back( enemyInfo.getSides(), enemyInfo.getSize(), position, sf::Color::Red );
            }
        }
    }

    map.popWave();
}

END_CONTROLLER_NAMESPACE