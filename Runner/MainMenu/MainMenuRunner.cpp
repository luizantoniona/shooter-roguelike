#include "MainMenuRunner.h"

#include <Manager/Asset/FontManager.h>

BEGIN_RUNNER_NAMESPACE

MainMenuRunner::MainMenuRunner() :
    Runner(),
    _selectedOption( Runners::RunnerType::NONE ),
    _buttons( {} ) {

    _font = Managers::FontManager::instance().font( FontType::Arial );

    initMenu();
}

MainMenuRunner::~MainMenuRunner() {
}

void MainMenuRunner::handleInput( const sf::Event& event, const sf::Time& deltaTime ) {

    if ( event.type == sf::Event::MouseMoved ) {
        sf::Vector2f mousePos( event.mouseMove.x, event.mouseMove.y );

        for ( size_t i = 0; i < _buttons.size(); ++i ) {
            if ( _buttons[ i ].isMouseOver( mousePos ) ) {
                switch ( i ) {
                case 0:
                    _selectedOption = Runners::RunnerType::GAME;
                    break;
                case 1:
                    _selectedOption = Runners::RunnerType::UPGRADE;
                    break;
                default:
                    _selectedOption = Runners::RunnerType::NONE;
                    break;
                }
            }
        }
    }

    if ( event.type == sf::Event::MouseButtonPressed && _runnerCallback ) {
        if ( event.mouseButton.button == sf::Mouse::Left && _selectedOption != Runners::RunnerType::NONE ) {
            _runnerCallback( _selectedOption );
        }
    }
}

void MainMenuRunner::update( sf::RenderWindow& window, const sf::Time& deltaTime ) {
    for ( size_t i = 0; i < _buttons.size(); ++i ) {

        if ( i == static_cast<int>( _selectedOption ) ) {
            _buttons[ i ].setFillColor( sf::Color::Red );

        } else {
            _buttons[ i ].setFillColor( sf::Color::White );
        }
    }
}

void MainMenuRunner::render( sf::RenderWindow& window ) {
    window.setView( window.getDefaultView() );
    window.draw( _title );

    for ( const auto& button : _buttons ) {
        button.render( window );
    }
}

void MainMenuRunner::initMenu() {

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

bool MainMenuRunner::isMouseOverOption( const sf::Text& option, const sf::Vector2f& mousePos ) {
    return option.getGlobalBounds().contains( mousePos );
}

END_RUNNER_NAMESPACE
