#include "SpawnController.h"

BEGIN_CONTROLLER_NAMESPACE

void SpawnController::checkSpawn( Map& map, std::vector<Enemy>& enemies ) {

    if ( enemies.size() > 0 ) {
        return;
    }

    // TODO READ FROM map.WAVES
    // 1. Read from map.WAVES
    // 2. Generate enemies based on the wave information
    // 3. Add enemies to the enemies vector

    for ( int i = 0; i < 5; ++i ) {
        sf::Vector2f position( std::rand() % map.getWidth(), std::rand() % map.getHeight() );
        if ( map.isInsideBounds( position ) ) {
            enemies.emplace_back( 6, 20.0f, position, sf::Color::Red );
        }
    }
}

END_CONTROLLER_NAMESPACE