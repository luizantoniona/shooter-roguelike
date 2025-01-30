#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include <Manager/ScreenManager.h>
#include <Screens/Screen.h>
#include <Screens/ScreenGlobals.h>

using Manager::ScreenManager;
using Screens::Screen;

BEGIN_SCREEN_NAMESPACE

class MainMenuScreen : public Screen {
public:
    MainMenuScreen( int windowWidth, int windowHeight, ScreenManager& screenManager );

    void handleInput( const sf::Event& event, sf::Time& deltaTime ) override;
    void update( sf::Time& deltaTime ) override;
    void render( sf::RenderWindow& window ) override;

private:
    void initMenu();
    bool isMouseOverOption( const sf::Text& option, const sf::Vector2f& mousePos );

    ScreenManager& _screenManager;

    sf::Font _font;
    sf::Text _title;
    std::vector<sf::Text> _menuOptions;
    int _selectedOption;
};

END_SCREEN_NAMESPACE
