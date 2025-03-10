#pragma once

#include <SFML/Graphics.hpp>

#include <Manager/ManagerGlobals.h>

#include <GUI/Button/Button.h>

using GUI::Button;

BEGIN_MANAGER_NAMESPACE

class MainMenuManger {
public:
    MainMenuManger();

    void handleInput( const sf::Event& event, sf::Time& deltaTime );
    void update( sf::RenderWindow& window, sf::Time& deltaTime );
    void render( sf::RenderWindow& window );

private:
    void initMenu();
    bool isMouseOverOption( const sf::Text& option, const sf::Vector2f& mousePos );

    int _selectedOption;
    sf::Font _font;
    sf::Text _title;
    std::vector<Button> _buttons;
};

END_MANAGER_NAMESPACE