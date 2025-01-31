#include "UpdateController.h"

BEGIN_CONTROLLER_NAMESPACE

void UpdateController::update( sf::RenderWindow& window, sf::Time& deltaTime, Entity::Player& player, std::vector<Entity::Enemy>& enemies, Entity::Map& map ) {
    player.update( window, deltaTime );

    for ( auto& enemy : enemies ) {
        enemy.update( deltaTime );
    }

    map.update( deltaTime );
}

END_CONTROLLER_NAMESPACE