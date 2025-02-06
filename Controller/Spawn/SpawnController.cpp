#include "SpawnController.h"

#include <Factory/Enemy/EnemyFactory.h>
#include <Map/Wave/Wave.h>
#include <Map/Wave/WaveEnemyInfo.h>

using Entity::Wave;
using Entity::WaveEnemyInfo;
using Factory::EnemyFactory;

BEGIN_CONTROLLER_NAMESPACE

void SpawnController::checkSpawn( Map& map, std::vector<std::unique_ptr<Enemy>>& enemies, Player* player ) {

    if ( enemies.size() > 0 ) {
        return;
    }

    Wave currrentWave = map.getWaves().front();

    for ( WaveEnemyInfo& enemyInfo : currrentWave.getEnemies() ) {

        std::unique_ptr<Enemy> enemyOriginal = EnemyFactory::createEnemy( player, enemyInfo.getEnemyType() );

        for ( int i = 0; i < enemyInfo.getAmount(); ++i ) {

            sf::Vector2f position( std::rand() % map.getWidth(), std::rand() % map.getHeight() );
            if ( map.isInsideBounds( position ) ) {
                std::unique_ptr<Enemy> enemy = enemyOriginal->clone();
                enemy->setPosition( position );
                enemies.emplace_back( std::move( enemy ) );
            }
        }
    }

    map.popWave();
}

END_CONTROLLER_NAMESPACE