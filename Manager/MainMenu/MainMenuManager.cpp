#include "MainMenuManager.h"

#include <Manager/Asset/FontManager.h>

BEGIN_MANAGER_NAMESPACE

MainMenuManager::MainMenuManager() :
    _selectedOption( 0 ),
    _buttons( {} ) {

    _font = FontManager::instance().font( FontType::Arial );

    initMenu();
}

void MainMenuManager::handleInput( const sf::Event& event, sf::Time& deltaTime ) {

    if ( event.type == sf::Event::MouseMoved ) {
        sf::Vector2f mousePos( event.mouseMove.x, event.mouseMove.y );
        // _selectedOption = ScreenType::UNKNOW;

        for ( size_t i = 0; i < _buttons.size(); ++i ) {
            if ( _buttons[ i ].isMouseOver( mousePos ) ) {
                // _selectedOption = static_cast<ScreenType>( i );
                break;
            }
        }
    }

    if ( event.type == sf::Event::MouseButtonPressed ) {
        // if ( event.mouseButton.button == sf::Mouse::Left && _selectedOption != ScreenType::UNKNOW ) {
        //     // _screenManager.setScreen( _selectedOption );
        // }
    }
}

void MainMenuManager::update( sf::RenderWindow& window, sf::Time& deltaTime ) {
    for ( size_t i = 0; i < _buttons.size(); ++i ) {
        if ( i == static_cast<int>( _selectedOption ) ) {
            _buttons[ i ].setFillColor( sf::Color::Red );
        } else {
            _buttons[ i ].setFillColor( sf::Color::White );
        }
    }
}

void MainMenuManager::render( sf::RenderWindow& window ) {
    window.draw( _title );

    for ( const auto& button : _buttons ) {
        button.render( window );
    }
}

void MainMenuManager::initMenu() {

    _title.setFont( _font );
    _title.setString( "Roguelike" );
    _title.setCharacterSize( 50 );
    _title.setFillColor( sf::Color::White );
    _title.setPosition( 200, 100 );

    std::vector<std::string> options = { "Start Game", "Upgrades", "Settings", "Exit" };

    for ( size_t i = 0; i < options.size(); ++i ) {
        Button button( options[ i ], _font, 30 );
        button.setPosition( 250, 200 + i * 50 );
        _buttons.push_back( button );
    }
}

bool MainMenuManager::isMouseOverOption( const sf::Text& option, const sf::Vector2f& mousePos ) {
    return option.getGlobalBounds().contains( mousePos );
}

END_MANAGER_NAMESPACE
