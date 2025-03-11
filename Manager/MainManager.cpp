#include "MainManager.h"

namespace {
constexpr const char* DISPLAY_NAME = "Roguelike";
} // namespace

BEGIN_MANAGER_NAMESPACE

MainManager::MainManager() :
    _window( sf::VideoMode::getDesktopMode(), DISPLAY_NAME, sf::Style::Fullscreen ),
    _currentManager( nullptr ),
    _gameManager( nullptr ),
    _mainMenuManager( nullptr ),
    _upgradeManager( nullptr ) {

    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    int windowWidth = desktopMode.width;
    int windowHeight = desktopMode.height;

    _view.reset( sf::FloatRect( 0, 0, float( windowWidth ), float( windowHeight ) ) );
    _window.setView( _view );

    _gameManager = new GameManager( _window, _view );
    _currentManager = dynamic_cast<Manager::AbstractManager*>( _gameManager );
}

void MainManager::run() {
    if ( _currentManager ) {
        _currentManager->run();
    }
}

END_MANAGER_NAMESPACE
