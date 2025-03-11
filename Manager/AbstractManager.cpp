#include "AbstractManager.h"

BEGIN_MANAGER_NAMESPACE

AbstractManager::AbstractManager( sf::RenderWindow& window, sf::View& view ) :
    _window( window ),
    _view( view ) {
}

int AbstractManager::run() {

    sf::Clock clock;
    while ( _window.isOpen() ) {

        sf::Time deltaTime = clock.restart();

        sf::Event event;
        while ( _window.pollEvent( event ) ) {
            if ( event.type == sf::Event::Closed ) {
                _window.close();
            }
            handleInput( event, deltaTime );
        }

        update( _window, deltaTime );
        render( _window );
    }

    return 0;
}

END_MANAGER_NAMESPACE