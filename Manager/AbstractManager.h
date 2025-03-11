#pragma once

#include <SFML/Graphics.hpp>

#include <Manager/ManagerGlobals.h>

BEGIN_MANAGER_NAMESPACE

class AbstractManager {
public:
    AbstractManager( sf::RenderWindow& window, sf::View& view );
    virtual int run();

protected:
    sf::RenderWindow& _window;
    sf::View& _view;

private:
    virtual void handleInput( const sf::Event& event, const sf::Time& deltaTime ) = 0;
    virtual void update( sf::RenderWindow& window, const sf::Time& deltaTime ) = 0;
    virtual void render( sf::RenderWindow& window ) = 0;
};

END_MANAGER_NAMESPACE