#include "MainManager.h"

namespace {
constexpr const char* DISPLAY_NAME = "Roguelike";
} // namespace

BEGIN_MANAGER_NAMESPACE

MainManager::MainManager() :
    _window( sf::VideoMode::getDesktopMode(), DISPLAY_NAME, sf::Style::Fullscreen ) {

    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    int windowWidth = desktopMode.width;
    int windowHeight = desktopMode.height;

    _view.reset( sf::FloatRect( 0, 0, float( windowWidth ), float( windowHeight ) ) );
    _window.setView( _view );
}

void MainManager::run() {
    adjustView();

    sf::Clock clock;
    while ( _window.isOpen() ) {

        sf::Time deltaTime = clock.restart();

        processEvents( deltaTime );
        update( deltaTime );
        render();
    }
}

void MainManager::processEvents( sf::Time& deltaTime ) {
    sf::Event event;
    while ( _window.pollEvent( event ) ) {
        if ( event.type == sf::Event::Closed ) {
            _window.close();
        }
        // _screenManager.handleInput( event, deltaTime );
    }
}

void MainManager::update( sf::Time& deltaTime ) {
    // _screenManager.update( _window, deltaTime );
}

void MainManager::render() {
    _window.clear();
    // _screenManager.render( _window );
    _window.display();
}

void MainManager::adjustView() {
    _view.setCenter( float( sf::VideoMode::getDesktopMode().width ) / 2, float( sf::VideoMode::getDesktopMode().height ) / 2 );
    _window.setView( _view );
}

END_MANAGER_NAMESPACE
