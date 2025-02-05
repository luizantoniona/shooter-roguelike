#include "Player.h"
#include "Player/PlayerStatus.h"

#include <cmath>

BEGIN_ENTITY_NAMESPACE

Player::Player( int sides, float radius, const sf::Vector2f& position, const sf::Color& color, const Map& map ) :
    Shape(),
    _map( map ) {

    setSides( sides );
    setRadius( radius );
    setPosition( position );
    setColor( color );
    build();
}

Player::~Player() {
}

std::vector<Projectile>& Player::getProjectiles() {
    return _projectiles;
}

PlayerStatus Player::getPlayerStatus() const {
    return _status;
}

void Player::handleInput( const sf::Event& event ) {
}

void Player::update( const sf::RenderWindow& window, const sf::Time& deltaTime ) {
    updatePosition( deltaTime );
    updateProjectiles( deltaTime );

    sf::Vector2f mousePosition = window.mapPixelToCoords( sf::Mouse::getPosition( window ) );
    fireProjectile( mousePosition );
}

void Player::render( sf::RenderWindow& window ) {
    Shape::render( window );

    for ( auto& projectile : _projectiles ) {
        projectile.render( window );
    }
}

void Player::updatePosition( const sf::Time& deltaTime ) {
    sf::Vector2f movement( 0, 0 );
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::W ) ) {
        movement.y -= 100 * deltaTime.asSeconds();
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::S ) ) {
        movement.y += 100 * deltaTime.asSeconds();
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A ) ) {
        movement.x -= 100 * deltaTime.asSeconds();
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D ) ) {
        movement.x += 100 * deltaTime.asSeconds();
    }
    move( movement );

    sf::Vector2f position = getPosition();
    if ( !_map.isInsideBounds( position ) ) {
        if ( position.x < 0 ) {
            position.x = 0;
        }
        if ( position.y < 0 ) {
            position.y = 0;
        }
        if ( position.x > _map.getWidth() ) {
            position.x = _map.getWidth();
        }
        if ( position.y > _map.getHeight() ) {
            position.y = _map.getHeight();
        }
        setPosition( position );
    }
}

void Player::updateProjectiles( const sf::Time& deltaTime ) {
    for ( auto& projectile : _projectiles ) {
        projectile.update( deltaTime );
    }

    _projectiles.erase(
        std::remove_if(
            _projectiles.begin(), _projectiles.end(),
            [ this ]( const Projectile& projectile ) -> bool {
                return projectile.isOutOfBounds( _map.getWidth(), _map.getHeight() );
            } ),
        _projectiles.end() );
}

void Player::fireProjectile( const sf::Vector2f& target ) {
    if ( _fireClock.getElapsedTime().asSeconds() >= _status.getFireRate() ) {
        sf::Vector2f direction = target - getPosition();
        float length = std::hypot( direction.x, direction.y );

        if ( length > 0.0f ) {
            direction /= length;
            _projectiles.emplace_back( getPosition(), direction, 300.0f );
            _fireClock.restart();
        }
    }
}

END_ENTITY_NAMESPACE