#pragma once

#include <SFML/Graphics.hpp>

#include <Entity/Map/Map.h>
#include <Screens/Screen.h>
#include <Screens/ScreenGlobals.h>

using Entity::Map;
using Screens::Screen;

BEGIN_SCREEN_NAMESPACE

class GameScreen : public Screen {
public:
    GameScreen( int windowWidth, int windowHeight );

    void handleInput( const sf::Event& event, sf::Time& deltaTime ) override;
    void update( sf::Time& deltaTime ) override;
    void render( sf::RenderWindow& window ) override;

private:
    Map _map;
};

END_SCREEN_NAMESPACE
