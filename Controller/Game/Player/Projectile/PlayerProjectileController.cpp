#include "PlayerProjectileController.h"

#include <cmath>

BEGIN_CONTROLLER_NAMESPACE

void PlayerProjectileController::updatePlayerProjectile( const sf::Time& deltaTime, Entities::Character& player, Entities::Map& map ) {
    auto& projectiles = player.getProjectiles();

    for ( auto& projectile : projectiles ) {
        sf::Vector2f movement = projectile->getDirection() * projectile->getSpeed() * deltaTime.asSeconds();
        projectile->getShape()->move( movement );
    }

    projectiles.erase(
        std::remove_if(
            projectiles.begin(), projectiles.end(),
            [ &map ]( const Entities::Projectile& projectile ) -> bool {
                return projectile.isOutOfBounds( map.getWidth(), map.getHeight() );
            } ),
        projectiles.end() );
}

void PlayerProjectileController::firePlayerProjectile( const sf::Vector2f& target, const sf::Time& deltaTime, Entities::Character& player ) {

    auto& projectileStatus = player.getProjectileStatus();

    if ( player.getFireClock().getElapsedTime().asSeconds() >= ( 1.0f / projectileStatus.getProjectileFireRate() ) ) {
        sf::Vector2f direction = target - player.getShape()->getPosition();
        float length = std::hypot( direction.x, direction.y );

        if ( length > 0.0f ) {
            direction /= length;

            Entities::Projectile projectile;
            projectile.setDirection( direction );
            projectile.setSpeed( projectileStatus.getProjectileSpeed() );
            projectile.setDamage( projectileStatus.getProjectileDamage() );
            projectile.getShape()->setSides( 3 ); // TODO: Como definir o número de sides? Trocar por circulo?
            projectile.getShape()->setPosition( player.getShape()->getPosition() );
            projectile.getShape()->setSize( projectileStatus.getProjectileSize() );
            projectile.getShape()->build();

            player.getProjectiles().emplace_back( projectile );
            player.getFireClock().restart();
        }
    }
}

END_CONTROLLER_NAMESPACE
