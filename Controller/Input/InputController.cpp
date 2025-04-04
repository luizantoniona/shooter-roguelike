#include "InputController.h"

BEGIN_CONTROLLER_NAMESPACE

void InputController::handleInput( const sf::Event& event, Entities::Character& player ) {
    if ( event.type == sf::Event::KeyPressed ) {
        if ( event.key.code == sf::Keyboard::Escape ) {
        }
    }
}

END_CONTROLLER_NAMESPACE