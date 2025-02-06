#include "UpdateController.h"

BEGIN_CONTROLLER_NAMESPACE

void UpdateController::update( sf::RenderWindow& window, sf::Time& deltaTime, Player& player, std::vector<std::unique_ptr<Enemy>>& enemies, Map& map ) {
    player.update( window, deltaTime );

    for ( auto& enemy : enemies ) {
        enemy->update( deltaTime );
    }

    map.update( deltaTime );
}

END_CONTROLLER_NAMESPACE