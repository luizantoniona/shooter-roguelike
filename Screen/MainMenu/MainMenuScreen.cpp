#include "MainMenuScreen.h"

#include <Manager/Asset/FontManager.h>
#include <Screen/ScreenType.h>

using Manager::FontManager;

BEGIN_SCREEN_NAMESPACE

MainMenuScreen::MainMenuScreen( ScreenManager& screenManager ) :
    Screen(),
    _selectedOption( ScreenType::UNKNOW ),
    _buttons( {} ),
    _screenManager( screenManager ) {

    _font = FontManager::instance().font( FontType::Arial );

    initMenu();
}

void MainMenuScreen::handleInput( const sf::Event& event, sf::Time& deltaTime ) {

    if ( event.type == sf::Event::MouseMoved ) {
        sf::Vector2f mousePos( event.mouseMove.x, event.mouseMove.y );
        _selectedOption = ScreenType::UNKNOW;

        for ( size_t i = 0; i < _buttons.size(); ++i ) {
            if ( _buttons[ i ].isMouseOver( mousePos ) ) {
                _selectedOption = static_cast<ScreenType>( i );
                break;
            }
        }
    }

    if ( event.type == sf::Event::MouseButtonPressed ) {
        if ( event.mouseButton.button == sf::Mouse::Left && _selectedOption != ScreenType::UNKNOW ) {
            _screenManager.setScreen( _selectedOption );
        }
    }
}

void MainMenuScreen::update( sf::RenderWindow& window, sf::Time& deltaTime ) {
    for ( size_t i = 0; i < _buttons.size(); ++i ) {
        if ( i == static_cast<int>( _selectedOption ) ) {
            _buttons[ i ].setFillColor( sf::Color::Red );
        } else {
            _buttons[ i ].setFillColor( sf::Color::White );
        }
    }
}

void MainMenuScreen::render( sf::RenderWindow& window ) {
    window.draw( _title );

    for ( const auto& button : _buttons ) {
        button.render( window );
    }
}

void MainMenuScreen::initMenu() {

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

bool MainMenuScreen::isMouseOverOption( const sf::Text& option, const sf::Vector2f& mousePos ) {
    return option.getGlobalBounds().contains( mousePos );
}

END_SCREEN_NAMESPACE
