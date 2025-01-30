#include "ScreenManager.h"

BEGIN_MANAGER_NAMESPACE

ScreenManager::ScreenManager() : _activeScreen( nullptr ) {
}

void ScreenManager::setScreen( const ScreenType& screenType ) {
    _activeScreen = _screens.at( screenType );
}

void ScreenManager::addScreen( const ScreenType& screenType, std::shared_ptr<Screen> screen ) {
    _screens[ screenType ] = screen;
}

void ScreenManager::handleInput( const sf::Event& event, sf::Time& deltaTime ) {
    if ( _activeScreen ) {
        _activeScreen->handleInput( event, deltaTime );
    }
}

void ScreenManager::update( sf::RenderWindow& window, sf::Time& deltaTime ) {
    if ( _activeScreen ) {
        _activeScreen->update( window, deltaTime );
    }
}

void ScreenManager::render( sf::RenderWindow& window ) {
    if ( _activeScreen ) {
        _activeScreen->render( window );
    }
}

END_MANAGER_NAMESPACE
