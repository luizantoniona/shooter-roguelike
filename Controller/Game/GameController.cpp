#include "GameController.h"


#include <Controller/Game/Collision/Collisioner.h>
#include <Controller/Game/Spawn/Spawner.h>

BEGIN_CONTROLLER_NAMESPACE

void GameController::update( sf::RenderWindow& window, const sf::Time& deltaTime, Entities::Character& player, std::vector<std::unique_ptr<Entities::Character>>& enemies, Entities::Map& map ) {
    // player.update( window, deltaTime );

    // for ( auto& enemy : enemies ) {
    //     enemy->update( window, deltaTime );
    // }

    // map.update( deltaTime );

    Collisioner::checkCollisions( player, enemies );
    Spawner::spawn( map, enemies, player );
}

    // void Enemy::update( const sf::RenderWindow& window, const sf::Time& deltaTime ) {

    //     sf::Vector2f direction = _player.getShape().getPosition() - _shape.getPosition();
    //     float length = std::hypot( direction.x, direction.y );

    //     if ( length > 0.0f ) {
    //         direction /= length;
    //         _shape.move( direction * _speed * deltaTime.asSeconds() );
    //     }
    // }
}

// void Player::update( const sf::RenderWindow& window, const sf::Time& deltaTime ) {
//     updatePosition( window, deltaTime );
//     updateProjectiles( window, deltaTime );

//     sf::View currentView = window.getView();
//     sf::Vector2f mousePosition = window.mapPixelToCoords( sf::Mouse::getPosition( window ), currentView );

//     fireProjectile( mousePosition );
// }

// void Player::render( sf::RenderWindow& window ) {
//     BaseEntity::render( window );

//     for ( auto& projectile : _projectiles ) {
//         projectile.render( window );
//     }
// }

// void Player::updatePosition( const sf::RenderWindow& window, const sf::Time& deltaTime ) {
//     sf::Vector2f movement( 0, 0 );
//     if ( sf::Keyboard::isKeyPressed( sf::Keyboard::W ) ) {
//         movement.y -= 100 * deltaTime.asSeconds();
//     }
//     if ( sf::Keyboard::isKeyPressed( sf::Keyboard::S ) ) {
//         movement.y += 100 * deltaTime.asSeconds();
//     }
//     if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A ) ) {
//         movement.x -= 100 * deltaTime.asSeconds();
//     }
//     if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D ) ) {
//         movement.x += 100 * deltaTime.asSeconds();
//     }
//     _shape.move( movement );

//     sf::Vector2f position = _shape.getPosition();
//     if ( !_map.isInsideBounds( position ) ) {
//         if ( position.x < 0 ) {
//             position.x = 0;
//         }
//         if ( position.y < 0 ) {
//             position.y = 0;
//         }
//         if ( position.x > _map.getWidth() ) {
//             position.x = _map.getWidth();
//         }
//         if ( position.y > _map.getHeight() ) {
//             position.y = _map.getHeight();
//         }
//         _shape.setPosition( position );
//     }
// }

// void Player::updateProjectiles( const sf::RenderWindow& window, const sf::Time& deltaTime ) {
//     for ( auto& projectile : _projectiles ) {
//         projectile.update( window, deltaTime );
//     }

//     _projectiles.erase(
//         std::remove_if(
//             _projectiles.begin(), _projectiles.end(),
//             [ this ]( const Projectile& projectile ) -> bool {
//                 return projectile.isOutOfBounds( _map.getWidth(), _map.getHeight() );
//             } ),
//         _projectiles.end() );
// }

// void Player::fireProjectile( const sf::Vector2f& target ) {
//     if ( _fireClock.getElapsedTime().asSeconds() >= getPlayerProjectileStatus().getProjectileFireRate() ) {
//         sf::Vector2f direction = target - _shape.getPosition();
//         float length = std::hypot( direction.x, direction.y );

//         if ( length > 0.0f ) {
//             direction /= length;

//             Projectile projectile;
//             projectile.setDirection( direction );
//             projectile.setSpeed( getPlayerProjectileStatus().getProjectileSpeed() );
//             projectile.setDamage( getPlayerProjectileStatus().getProjectileDamage() );
//             projectile.getShape().setSides( 3 );
//             projectile.getShape().setPosition( _shape.getPosition() );
//             projectile.getShape().setRadius( getPlayerProjectileStatus().getProjectileSize() );
//             projectile.getShape().build();

//             _projectiles.emplace_back( projectile );
//             _fireClock.restart();
//         }
//     }
// }

// void Projectile::update( const sf::RenderWindow& window, const sf::Time& deltaTime ) {
//     sf::Vector2f movement = _direction * _speed * deltaTime.asSeconds();
//     _shape.move( movement );
// }

END_CONTROLLER_NAMESPACE