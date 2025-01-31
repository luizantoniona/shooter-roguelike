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

ScreenManager::ScreenManager() :
    _activeScreen( nullptr ) {

    setScreen( ScreenType::MainMenuScreen );
}

void ScreenManager::setScreen( const ScreenType& screenType ) {
    if ( _screens.find( screenType ) == _screens.end() ) {
        createScreen( screenType );
    }

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

void ScreenManager::createScreen( const ScreenType& screenType ) {

    int windowWidth = sf::VideoMode::getDesktopMode().width;
    int windowHeight = sf::VideoMode::getDesktopMode().height;

    switch ( screenType ) {
    case ScreenType::MainMenuScreen:
        addScreen( ScreenType::MainMenuScreen, new MainMenuScreen( *this ) );
        break;
    case ScreenType::GameScreen:
        addScreen( ScreenType::GameScreen, new GameScreen( windowWidth, windowHeight, *this ) );
        break;
    case ScreenType::UpgradeScreen:
        addScreen( ScreenType::UpgradeScreen, new UpgradeScreen() );
        break;
    default:
        break;
    }
}

END_MANAGER_NAMESPACE
