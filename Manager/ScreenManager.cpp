#include "ScreenManager.h"

#include <Screen/Game/GameScreen.h>
#include <Screen/MainMenu/MainMenuScreen.h>
#include <Screen/ScreenType.h>
#include <Screen/Upgrade/UpgradeScreen.h>

using Screens::GameScreen;
using Screens::MainMenuScreen;
using Screens::ScreenType;
using Screens::UpgradeScreen;

BEGIN_MANAGER_NAMESPACE

ScreenManager::ScreenManager( int windowWidth, int windowHeight ) :
    _activeScreen( nullptr ) {

    addScreen( ScreenType::MainMenuScreen, new MainMenuScreen( windowWidth, windowHeight, *this ) );
    addScreen( ScreenType::GameScreen, new GameScreen( windowWidth, windowHeight ) );
    addScreen( ScreenType::UpgradeScreen, new UpgradeScreen( windowWidth, windowHeight ) );
    setScreen( ScreenType::MainMenuScreen );
}

void ScreenManager::setScreen( const ScreenType& screenType ) {
    _activeScreen = _screens.at( screenType );
}

void ScreenManager::addScreen( const ScreenType& screenType, Screen* screen ) {
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
