#include "MainMenuScreen.h"

#include <Manager/AssetManager.h>
#include <Screens/ScreenType.h>

using Manager::AssetManager;

BEGIN_SCREEN_NAMESPACE

MainMenuScreen::MainMenuScreen( int windowWidth, int windowHeight, ScreenManager& screenManager )
    : Screen( windowWidth, windowHeight ), _screenManager( screenManager ), _selectedOption( -1 ) {

    _font = AssetManager::instance().font( FontType::Arial );

    _title.setFont( _font );
    _title.setString( "Shape Defense" );
    _title.setCharacterSize( 50 );
    _title.setFillColor( sf::Color::White );
    _title.setPosition( 200, 100 );

    initMenu();
}

void MainMenuScreen::handleInput( const sf::Event& event ) {

    if ( event.type == sf::Event::MouseMoved ) {
        sf::Vector2f mousePos( event.mouseMove.x, event.mouseMove.y );
        _selectedOption = -1;

        for ( size_t i = 0; i < _menuOptions.size(); ++i ) {
            if ( isMouseOverOption( _menuOptions[ i ], mousePos ) ) {
                _selectedOption = i;
                break;
            }
        }
    }

    if ( event.type == sf::Event::MouseButtonPressed ) {
        if ( event.mouseButton.button == sf::Mouse::Left && _selectedOption != -1 ) {

            if ( _selectedOption == 0 ) {
                _screenManager.setScreen( ScreenType::GameScreen );
            } else if ( _selectedOption == 4 ) {
                // Sair do jogo
            }
        }
    }
}

void MainMenuScreen::update() {
    for ( size_t i = 0; i < _menuOptions.size(); ++i ) {
        if ( i == _selectedOption ) {
            _menuOptions[ i ].setFillColor( sf::Color::Red );
        } else {
            _menuOptions[ i ].setFillColor( sf::Color::White );
        }
    }
}

void MainMenuScreen::render( sf::RenderWindow& window ) {
    window.draw( _title );

    for ( const auto& option : _menuOptions ) {
        window.draw( option );
    }
}

void MainMenuScreen::initMenu() {
    std::vector<std::string> options = { "Start Game", "Upgrades", "Settings", "Exit" };

    for ( size_t i = 0; i < options.size(); ++i ) {
        sf::Text option;
        option.setFont( _font );
        option.setString( options[ i ] );
        option.setCharacterSize( 30 );
        option.setFillColor( sf::Color::White );
        option.setPosition( 250, 200 + i * 50 );
        _menuOptions.push_back( option );
    }
}

bool MainMenuScreen::isMouseOverOption( const sf::Text& option, const sf::Vector2f& mousePos ) {
    return option.getGlobalBounds().contains( mousePos );
}

END_SCREEN_NAMESPACE
