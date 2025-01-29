#pragma once

#include <SFML/Graphics.hpp>

#include <Screens/Screen.h>
#include <Screens/ScreenGlobals.h>

using Screens::Screen;

BEGIN_SCREEN_NAMESPACE

class GameScreen : public Screen {
public:
    GameScreen( int windowWidth, int windowHeight );

    void handleInput( const sf::Event& event ) override;
    void update() override;
    void render( sf::RenderWindow& window ) override;

private:
};

END_SCREEN_NAMESPACE
