#include "PlayerProjectileController.h"

#include <cmath>

#include <Factory/Shape/ShapeFactory.h>

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
            [ &map ]( std::unique_ptr<Entities::Projectile>& projectile ) -> bool {
                return projectile->isOutOfBounds( map.getWidth(), map.getHeight() );
            } ),
        projectiles.end() );
}

void PlayerProjectileController::firePlayerProjectile( const sf::Vector2f& target, const sf::Time& deltaTime, Entities::Character& player ) {

    auto& projectileStatus = player.getProjectileStatus();

    if ( player.getFireClock().getElapsedTime().asSeconds() >= ( 1.0f / projectileStatus.getProjectileFireRate() ) ) {
        sf::Vector2f origin = player.getShape()->getPosition();
        sf::Vector2f direction = target - origin;
        float length = std::hypot( direction.x, direction.y );

        if ( length > 0.0f ) {
            direction /= length;

            auto projectile = std::make_unique<Entities::Projectile>();
            projectile->setDirection( direction );
            projectile->setSpeed( projectileStatus.getProjectileSpeed() );
            projectile->setDamage( projectileStatus.getProjectileDamage() );

            auto shape = Factories::ShapeFactory::createBulletShape( projectileStatus.getProjectileSize() );
            shape->setPosition( origin );
            projectile->setShape( std::move( shape ) );

            player.getProjectiles().emplace_back( std::move( projectile ) );
            player.getFireClock().restart();
        }
    }
}

END_CONTROLLER_NAMESPACE
