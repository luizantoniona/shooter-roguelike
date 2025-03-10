#include "AbstractManager.h"

#include <SFML/Graphics.hpp>

BEGIN_MANAGER_NAMESPACE

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
}

END_MANAGER_NAMESPACE