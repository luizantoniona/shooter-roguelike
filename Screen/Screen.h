#pragma once

#include <SFML/Graphics.hpp>

#include <Screen/ScreenGlobals.h>
#include <Screen/ScreenType.h>

BEGIN_SCREEN_NAMESPACE

class Screen {
public:
    Screen();
    virtual ~Screen() = default;

    virtual void handleInput( const sf::Event& event, sf::Time& deltaTime ) = 0;
    virtual void update( sf::RenderWindow& window, sf::Time& deltaTime ) = 0;
    virtual void render( sf::RenderWindow& window ) = 0;
};

END_SCREEN_NAMESPACE
