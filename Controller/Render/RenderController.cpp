#include "RenderController.h"

BEGIN_CONTROLLER_NAMESPACE

void RenderController::render( sf::RenderWindow& window, Entities::Character& player, std::vector<std::unique_ptr<Entities::Character>>& enemies, Entities::Map& map ) {

    window.draw( map.getShape() );

    player.render( window );

    for ( auto& playerProjectile : player.getProjectiles() ) {
        playerProjectile.render( window );
    }

    for ( auto& enemy : enemies ) {
        enemy->render( window );

        // TODO: Uncomment when projectiles are implemented

        // for ( auto& enemyProjectile : enemy->getProjectiles() ) {
        //     enemyProjectile.render( window );
        // }
    }
}

END_CONTROLLER_NAMESPACE
