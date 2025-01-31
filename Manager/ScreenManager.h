#pragma once

#include <SFML/Graphics.hpp>

#include <Manager/ManagerGlobals.h>

#include <Screen/Screen.h>
#include <Screen/ScreenType.h>

using Screens::Screen;
using Screens::ScreenType;

BEGIN_MANAGER_NAMESPACE

class ScreenManager {
public:
    ScreenManager();

    void setScreen( const ScreenType& screenType );
    void addScreen( const ScreenType& screenType, Screen* screen );
    void handleInput( const sf::Event& event, sf::Time& deltaTime );
    void update( sf::RenderWindow& window, sf::Time& deltaTime );
    void render( sf::RenderWindow& window );

private:
    std::map<ScreenType, Screen*> _screens;
    Screen* _activeScreen;

    void createScreen( const ScreenType& screenType );
};

END_MANAGER_NAMESPACE
