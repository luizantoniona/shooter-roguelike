#include "SpawnController.h"

#include <Factory/Enemy/EnemyFactory.h>
#include <Helper/Color/ColorHelper.h>
#include <Map/Wave/Wave.h>
#include <Map/Wave/WaveEnemyInfo.h>

using Entity::Wave;
using Entity::WaveEnemyInfo;
using Factory::EnemyFactory;
using Helper::ColorHelper;

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
                enemies.emplace_back(
                    *EnemyFactory::createEnemy(
                        enemyInfo.getHealth(),
                        enemyInfo.getSpeed(),
                        enemyInfo.getSides(),
                        enemyInfo.getSize(),
                        ColorHelper::colorFromString( enemyInfo.getColor() ),
                        position ) );
            }
        }
    }

    map.popWave();
}

END_CONTROLLER_NAMESPACE