#include "InputController.h"

BEGIN_CONTROLLER_NAMESPACE

void InputController::handleInput( const sf::Event& event, Player& player ) {
    if ( event.type == sf::Event::KeyPressed ) {
        if ( event.key.code == sf::Keyboard::Escape ) {
        }
    }

    // player.handleInput( event );
}

END_CONTROLLER_NAMESPACE