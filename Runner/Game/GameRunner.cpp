#include "GameRunner.h"

#include <Factory/Map/MapFactory.h>
#include <Factory/Player/PlayerFactory.h>
#include <GUI/Bar/HealthBar.h>

BEGIN_RUNNER_NAMESPACE

GameRunner::GameRunner() :
    Runner(),
    _map( Factories::MapFactory::generateMap( MapType::WORLD1_STAGE1 ) ),
    _player( Factories::PlayerFactory::createPlayer( *_map ) ),
    _enemies() {

    createComponents();

    std::srand( std::time( nullptr ) );
}

GameRunner::~GameRunner() {
}

void GameRunner::handleInput( const sf::Event& event, const sf::Time& deltaTime ) {

    if ( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape ) {
    }

    _inputController.handleInput( event, *_player );
}

void GameRunner::update( sf::RenderWindow& window, const sf::Time& deltaTime ) {
    _gameController.update( window, deltaTime, *_player, _enemies, *_map );
    _guiController.updateComponents( *_player, _components );
}

void GameRunner::render( sf::RenderWindow& window ) {

    // _map->render( window );

    // _player->render( window );

    // for ( auto& enemy : _enemies ) {
    //     enemy->render( window );
    // }

    window.setView( window.getDefaultView() );
    for ( auto& component : _components ) {
        component->render( window );
    }

    sf::View view = window.getView();
    view.setCenter( _player->getShape().getPosition() );
    window.setView( view );
}

void GameRunner::createComponents() {
    _components.emplace_back( std::make_unique<GUI::HealthBar>( 100.0f ) );
}

END_RUNNER_NAMESPACE