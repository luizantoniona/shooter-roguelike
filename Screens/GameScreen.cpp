#include "GameScreen.h"

BEGIN_SCREEN_NAMESPACE

GameScreen::GameScreen( int windowWidth, int windowHeight )
    : Screen( windowWidth, windowHeight ), _map( windowWidth, windowHeight ),
}

void GameScreen::handleInput( const sf::Event& event, sf::Time& deltaTime ) {
    if ( event.type == sf::Event::KeyPressed ) {
        if ( event.key.code == sf::Keyboard::Escape ) {
        }
    }
}

void GameScreen::update( sf::Time& deltaTime ) {
    _map.update( deltaTime );
}

void GameScreen::render( sf::RenderWindow& window ) {
    _map.render( window );
}

END_SCREEN_NAMESPACE
