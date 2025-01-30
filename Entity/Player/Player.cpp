#include "Player.h"

BEGIN_ENTITY_NAMESPACE

Player::Player( int sides, float radius, const sf::Vector2f& position, const sf::Color& color )
    : Shape( sides, radius, position, color ) {
}

Player::~Player() {
}

void Player::handleInput( const sf::Event& event ) {
    if ( event.type == sf::Event::KeyPressed ) {
        switch ( event.key.code ) {
        case sf::Keyboard::W:
            move( sf::Vector2f( 0, -10 ) );
            break;
        case sf::Keyboard::S:
            move( sf::Vector2f( 0, 10 ) );
            break;
        case sf::Keyboard::A:
            move( sf::Vector2f( -10, 0 ) );
            break;
        case sf::Keyboard::D:
            move( sf::Vector2f( 10, 0 ) );
            break;
        default:
            break;
        }
    }
}

void Player::update() {
}

void Player::render( sf::RenderWindow& window ) {
    Shape::render( window );
}

END_ENTITY_NAMESPACE