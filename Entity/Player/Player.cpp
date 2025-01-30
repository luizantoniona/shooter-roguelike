#include "Player.h"

BEGIN_ENTITY_NAMESPACE

Player::Player( int sides, float radius, const sf::Vector2f& position, const sf::Color& color, const Map& map )
    : Shape( sides, radius, position, color ), _map( map ) {
}

Player::~Player() {
}

void Player::handleInput( const sf::Event& event ) {
}

void Player::update( sf::Time& deltaTime ) {
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

void Player::render( sf::RenderWindow& window ) {
    Shape::render( window );
}

END_ENTITY_NAMESPACE