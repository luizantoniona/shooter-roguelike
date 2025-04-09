#include "MainManager.h"

namespace {
constexpr const char* DISPLAY_NAME = "Roguelike";
} // namespace

BEGIN_MANAGER_NAMESPACE

MainManager::MainManager() :
    _window( sf::VideoMode::getDesktopMode(), DISPLAY_NAME, sf::Style::Fullscreen ),
    _currentRunner( nullptr ),
    _gameRunner( nullptr ),
    _mainMenuRunner( nullptr ),
    _upgradeRunner( nullptr ) {

    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    int windowWidth = desktopMode.width;
    int windowHeight = desktopMode.height;

    _view.reset( sf::FloatRect( 0, 0, float( windowWidth ), float( windowHeight ) ) );
    _window.setView( _view );

    _mainMenuRunner = std::make_unique<Runners::MainMenuRunner>();
    _mainMenuRunner->setRunnerCallback( this->runnersCallback() );

    _currentRunner = std::move( _mainMenuRunner );
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
        _currentRunner->handleInput( _window, event, deltaTime );
    }
}

void MainManager::update( sf::Time& deltaTime ) {
    _currentRunner->update( _window, deltaTime );
}

void MainManager::render() {
    _window.clear();
    _currentRunner->render( _window );
    _window.display();
}

void MainManager::adjustView() {
    _view.setCenter( float( sf::VideoMode::getDesktopMode().width ) / 2, float( sf::VideoMode::getDesktopMode().height ) / 2 );
    _window.setView( _view );
}

std::function<void( Runners::RunnerType )> MainManager::runnersCallback() {
    return [ this ]( Runners::RunnerType runnerType ) {
        std::unique_ptr<Runners::Runner> oldRunner = std::move( _currentRunner );

        switch ( runnerType ) {
        case Runners::RunnerType::GAME:
            _gameRunner = std::make_unique<Runners::GameRunner>();
            _gameRunner->setRunnerCallback( this->runnersCallback() );
            _currentRunner = std::move( _gameRunner );
            break;
        case Runners::RunnerType::UPGRADE:
            _upgradeRunner = std::make_unique<Runners::UpgradeRunner>();
            _upgradeRunner->setRunnerCallback( this->runnersCallback() );
            _currentRunner = std::move( _upgradeRunner );
            break;
        case Runners::RunnerType::MENU:
        default:
            _mainMenuRunner = std::make_unique<Runners::MainMenuRunner>();
            _mainMenuRunner->setRunnerCallback( this->runnersCallback() );
            _currentRunner = std::move( _mainMenuRunner );
            break;
        }
    };
}

END_MANAGER_NAMESPACE
