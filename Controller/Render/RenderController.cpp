#include "RenderController.h"

BEGIN_CONTROLLER_NAMESPACE

void RenderController::render( sf::RenderWindow& window, Entities::Character& player, std::vector<std::unique_ptr<Entities::Character>>& enemies, Entities::Map& map ) {

    window.draw( map.getShape() );

    player.getShape().render( window );

    for ( auto& playerProjectile : player.getProjectiles() ) {
        playerProjectile.getShape().render( window );
    }

    for ( auto& enemy : enemies ) {
        enemy->getShape().render( window );
    }
}

END_CONTROLLER_NAMESPACE