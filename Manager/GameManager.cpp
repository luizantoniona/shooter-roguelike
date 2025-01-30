#include "GameManager.h"

#include <Screens/GameScreen.h>
#include <Screens/MainMenuScreen.h>
#include <Screens/ScreenType.h>

using Screens::GameScreen;
using Screens::MainMenuScreen;
using Screens::ScreenType;

namespace {
constexpr const char* DISPLAY_NAME = "Roguelike";
} // namespace

BEGIN_MANAGER_NAMESPACE

GameManager::GameManager() : _window( sf::VideoMode::getDesktopMode(), DISPLAY_NAME, sf::Style::Fullscreen ), _screenManager() {

    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    int windowWidth = desktopMode.width;
    int windowHeight = desktopMode.height;

    _view.reset( sf::FloatRect( 0, 0, float( windowWidth ), float( windowHeight ) ) );
    _window.setView( _view );

    _screenManager.addScreen( ScreenType::MainMenuScreen,
                              std::make_shared<MainMenuScreen>( windowWidth, windowHeight, _screenManager ) );
    _screenManager.addScreen( ScreenType::GameScreen, std::make_shared<GameScreen>( windowWidth, windowHeight ) );

    _screenManager.setScreen( ScreenType::MainMenuScreen );
}

void GameManager::run() {
    adjustView();

    sf::Clock clock;
    while ( _window.isOpen() ) {

        sf::Time deltaTime = clock.restart();

        processEvents( deltaTime );
        update( deltaTime );
        render();
    }
}

void GameManager::processEvents( sf::Time& deltaTime ) {
    sf::Event event;
    while ( _window.pollEvent( event ) ) {
        if ( event.type == sf::Event::Closed ) {
            _window.close();
        }
        _screenManager.handleInput( event, deltaTime );
    }
}

void GameManager::update( sf::Time& deltaTime ) {
    _screenManager.update( deltaTime );
}

void GameManager::render() {
    _window.clear();
    _screenManager.render( _window );
    _window.display();
}

void GameManager::adjustView() {
    _view.setCenter( float( sf::VideoMode::getDesktopMode().width ) / 2, float( sf::VideoMode::getDesktopMode().height ) / 2 );
    _window.setView( _view );
}

END_MANAGER_NAMESPACE
