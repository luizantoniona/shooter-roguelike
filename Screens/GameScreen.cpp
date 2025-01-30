#include "GameScreen.h"

BEGIN_SCREEN_NAMESPACE

GameScreen::GameScreen( int windowWidth, int windowHeight ) : Screen( windowWidth, windowHeight ) {
}

void GameScreen::handleInput( const sf::Event& event, sf::Time& deltaTime ) {
    if ( event.type == sf::Event::KeyPressed ) {
        if ( event.key.code == sf::Keyboard::Escape ) {
        }
    }
}

void GameScreen::update( sf::Time& deltaTime ) {
}

void GameScreen::render( sf::RenderWindow& window ) {
}

END_SCREEN_NAMESPACE
