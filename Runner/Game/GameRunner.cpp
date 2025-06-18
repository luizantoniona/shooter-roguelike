#include "GameRunner.h"

#include <Controller/GUI/GUIController.h>
#include <Controller/Game/GameController.h>
#include <Controller/Input/InputController.h>
#include <Controller/Render/RenderController.h>
#include <Factory/Character/CharacterFactory.h>
#include <Factory/Map/MapFactory.h>
#include <Renderables/Components/Bar/HealthBar.h>

BEGIN_RUNNER_NAMESPACE

GameRunner::GameRunner() :
    Runner(),
    _map( Factories::MapFactory::generateMap( MapType::WORLD1_STAGE1 ) ),
    _player( Factories::CharacterFactory::createCharacter( true ) ),
    _enemies(),
    _components(),
    _gameState( GameState::PLAYING ) {

    _player->getShape()->setPosition( sf::Vector2f( _map->getHeight() / 2, _map->getWidth() / 2 ) );

    createComponents();
}

GameRunner::~GameRunner() {}

void GameRunner::handleInput( sf::RenderWindow& window, const sf::Event& event, const sf::Time& deltaTime ) {

    if ( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape ) {
        _runnerCallback( RunnerType::MENU );
    }

    Controllers::InputController::handleInput( event, *_player );
}

void GameRunner::update( sf::RenderWindow& window, const sf::Time& deltaTime ) {
    Controllers::GameController::update( window, deltaTime, *_player, _enemies, *_map, _gameState );
    Controllers::GUIController::updateComponents( *_player, _components );

}

void GameRunner::render( sf::RenderWindow& window ) {

    Controllers::RenderController::render( window, *_player, _enemies, *_map );

    window.setView( window.getDefaultView() );
    for ( auto& component : _components ) {
        component->render( window );
    }

    sf::View view = window.getView();
    view.setCenter( _player->getShape()->getPosition() );
    window.setView( view );
}

void GameRunner::createComponents() {
    _components.emplace_back( std::make_unique<Components::HealthBar>( 100.0f ) );
}

END_RUNNER_NAMESPACE
