#include "Player.h"

#include <cmath>

BEGIN_ENTITY_NAMESPACE

Player::Player( int sides, float radius, const sf::Vector2f& position, const sf::Color& color, const Map& map )
    : Shape( sides, radius, position, color ), _map( map ), _fireRate( 0.5f ) {
}

Player::~Player() {
}

void Player::handleInput( const sf::Event& event ) {
}

void Player::update( const sf::RenderWindow& window, sf::Time& deltaTime ) {
    updatePosition( deltaTime );
    updateProjectiles( deltaTime );

    sf::Vector2i mousePosition = sf::Mouse::getPosition( window );
    sf::Vector2f mousePositionF( static_cast<float>( mousePosition.x ), static_cast<float>( mousePosition.y ) );
    fireProjectile( mousePositionF );
}

void Player::render( sf::RenderWindow& window ) {
    Shape::render( window );

    for ( auto& projectile : _projectiles ) {
        projectile.render( window );
    }
}

std::vector<Projectile>& Player::getProjectiles() {
    return _projectiles;
}

void Player::updatePosition( sf::Time& deltaTime ) {
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

void Player::updateProjectiles( sf::Time& deltaTime ) {
    for ( auto& projectile : _projectiles ) {
        projectile.update( deltaTime );
    }

    _projectiles.erase( std::remove_if( _projectiles.begin(), _projectiles.end(),
                                        [ this ]( const Projectile& projectile ) -> bool {
                                            return projectile.isOutOfBounds( _map.getWidth(), _map.getHeight() );
                                        } ),
                        _projectiles.end() );
}

void Player::fireProjectile( const sf::Vector2f& target ) {
    if ( _fireClock.getElapsedTime().asSeconds() >= _fireRate ) {
        sf::Vector2f direction = target - getPosition();
        float length = std::sqrt( direction.x * direction.x + direction.y * direction.y );
        direction /= length;
        _projectiles.emplace_back( getPosition(), direction, 300.0f );
        _fireClock.restart();
    }
}

END_ENTITY_NAMESPACE