#include "PlayerController.h"

#include <Controller/Game/Player/Projectile/PlayerProjectileController.h>

BEGIN_CONTROLLER_NAMESPACE

void PlayerController::updatePlayer( sf::RenderWindow& window, const sf::Time& deltaTime, Entities::Character& player, Entities::Map& map ) {

    updatePlayerPosition( window, deltaTime, player, map );

    PlayerProjectileController::updatePlayerProjectile( deltaTime, player, map );

    sf::View currentView = window.getView();
    sf::Vector2f mousePosition = window.mapPixelToCoords( sf::Mouse::getPosition( window ), currentView );

    PlayerProjectileController::firePlayerProjectile( mousePosition, deltaTime, player );
}

void PlayerController::updatePlayerPosition( const sf::RenderWindow& window, const sf::Time& deltaTime, Entities::Character& player, Entities::Map& map ) {

    auto playerShape = player.getShape();

    const float playerSpeed = player.getStatus().getSpeed();

    sf::Vector2f movement( 0, 0 );
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::W ) ) {
        movement.y -= playerSpeed * deltaTime.asSeconds();
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::S ) ) {
        movement.y += playerSpeed * deltaTime.asSeconds();
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A ) ) {
        movement.x -= playerSpeed * deltaTime.asSeconds();
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D ) ) {
        movement.x += playerSpeed * deltaTime.asSeconds();
    }
    playerShape->move( movement );

    sf::Vector2f position = playerShape->getPosition();
    if ( !map.isInsideBounds( position ) ) {
        if ( position.x < 0 ) {
            position.x = 0;
        }
        if ( position.y < 0 ) {
            position.y = 0;
        }
        if ( position.x > map.getWidth() ) {
            position.x = map.getWidth();
        }
        if ( position.y > map.getHeight() ) {
            position.y = map.getHeight();
        }

        playerShape->setPosition( position );
    }
}

END_CONTROLLER_NAMESPACE
