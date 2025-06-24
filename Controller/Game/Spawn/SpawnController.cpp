#include "SpawnController.h"

#include <Entities/Map/Wave/Wave.h>
#include <Entities/Map/Wave/WaveEnemyInfo.h>
#include <Factory/Character/CharacterFactory.h>

BEGIN_CONTROLLER_NAMESPACE

void SpawnController::spawn( Entities::Map& map, std::vector<std::unique_ptr<Entities::Character> >& enemies, Entities::Character& player ) {

    if ( enemies.size() > 0 ) {
        return;
    }

    if ( map.getWaves().empty() ) {
        return;
    }

    Entities::Wave currrentWave = map.getWaves().front();

    for ( Entities::WaveEnemyInfo& enemyInfo : currrentWave.getEnemies() ) {

        std::unique_ptr<Entities::Character> enemyOriginal = Factories::CharacterFactory::createCharacter( false, enemyInfo.getEnemyType() );

        for ( int i = 0; i < enemyInfo.getAmount(); ++i ) {

            sf::Vector2f position( std::rand() % map.getWidth(), std::rand() % map.getHeight() );
            if ( map.isInsideBounds( position ) ) {
                std::unique_ptr<Entities::Character> enemy = enemyOriginal->clone();
                enemy->getShape().setPosition( position );
                enemies.emplace_back( std::move( enemy ) );
            }
        }
    }

    map.popWave();
}

END_CONTROLLER_NAMESPACE
