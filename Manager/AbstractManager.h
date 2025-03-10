#pragma once

#include <Manager/ManagerGlobals.h>

BEGIN_MANAGER_NAMESPACE

class AbstractManager {
public:
    virtual int run();

protected:
    sf::RenderWindow& _window;
    sf::View& _view;

private:
    virtual void handleInput( const sf::Event& event, const sf::Time& deltaTime );
    virtual void update( sf::RenderWindow& window, const sf::Time& deltaTime );
    virtual void render( sf::RenderWindow& window );
};

END_MANAGER_NAMESPACE