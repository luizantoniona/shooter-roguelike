#include "InputHandler.h"

BEGIN_HANDLER_NAMESPACE

void InputHandler::handleInput( const sf::Event& event, Player& player ) {
    if ( event.type == sf::Event::KeyPressed ) {
        if ( event.key.code == sf::Keyboard::Escape ) {
        }
    }

    player.handleInput( event );
}

END_HANDLER_NAMESPACE