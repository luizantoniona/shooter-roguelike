#include "GameScreen.h"

#include <memory>

BEGIN_SCREEN_NAMESPACE

GameScreen::GameScreen( int windowWidth, int windowHeight ) : Screen( windowWidth, windowHeight ) {
}

void GameScreen::handleInput( const sf::Event& event ) {
    if ( event.type == sf::Event::KeyPressed ) {
        if ( event.key.code == sf::Keyboard::Escape ) {
        }
    }
}

void GameScreen::update() {
}

void GameScreen::render( sf::RenderWindow& window ) {
}

END_SCREEN_NAMESPACE
