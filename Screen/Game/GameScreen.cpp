#include "GameScreen.h"

#include <Factory/Map/MapFactory.h>

using Factory::MapFactory;

BEGIN_SCREEN_NAMESPACE

GameScreen::GameScreen( int windowWidth, int windowHeight, ScreenManager& screenManager ) :
    Screen(),
    _screenManager( screenManager ),
    _map( MapFactory::generateMap( MapType::WORLD1_STAGE1 ) ),
    _player( 3, 20.0f, sf::Vector2f( windowWidth / 2.0, windowHeight / 2.0 ), sf::Color::Green, *_map ),
    _enemies( {} ) {

    std::srand( std::time( nullptr ) );
}

void GameScreen::handleInput( const sf::Event& event, sf::Time& deltaTime ) {

    if ( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape ) {
        _screenManager.setScreen( ScreenType::MainMenuScreen );
    }

    _inputController.handleInput( event, _player );
}

void GameScreen::update( sf::RenderWindow& window, sf::Time& deltaTime ) {
    _updateController.update( window, deltaTime, _player, _enemies, *_map );
    _collisionController.checkCollisions( _player, _enemies );
    _spawnController.checkSpawn( *_map, _enemies );
}

void GameScreen::render( sf::RenderWindow& window ) {

    sf::View view = window.getView();
    view.setCenter( _player.getPosition() );
    window.setView( view );

    _map->render( window );

    _player.render( window );

    for ( auto& enemy : _enemies ) {
        enemy.render( window );
    }
}

END_SCREEN_NAMESPACE
