#include "GameScreen.h"

BEGIN_SCREEN_NAMESPACE

GameScreen::GameScreen( int windowWidth, int windowHeight )
    : Screen( windowWidth, windowHeight ), _map( windowWidth, windowHeight ),
      _player( 6, 20.0f, sf::Vector2f( windowWidth / 2.0, windowHeight / 2.0 ), sf::Color::Green, _map ), _enemies( {} ) {

    for ( int i = 0; i < 5; ++i ) {
        sf::Vector2f position( std::rand() % windowWidth, std::rand() % windowHeight );
        if ( _map.isInsideBounds( position ) ) {
            _enemies.emplace_back( 6, 20.0f, position, sf::Color::Red );
        }
    }
}

void GameScreen::handleInput( const sf::Event& event, sf::Time& deltaTime ) {
    _inputHandler.handleInput( event, _player );
}

void GameScreen::update( sf::RenderWindow& window, sf::Time& deltaTime ) {
    _updateHandler.update( deltaTime, _player, _enemies, _map );
}

void GameScreen::render( sf::RenderWindow& window ) {

    sf::View view = window.getView();
    view.setCenter( _player.getPosition() );
    window.setView( view );

    _map.render( window );

    _player.render( window );

    for ( auto& enemy : _enemies ) {
        enemy.render( window );
    }
}

END_SCREEN_NAMESPACE
