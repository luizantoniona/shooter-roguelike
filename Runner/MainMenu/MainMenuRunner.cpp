#include "MainMenuRunner.h"

#include <Manager/Asset/FontManager.h>

BEGIN_RUNNER_NAMESPACE

MainMenuRunner::MainMenuRunner() :
    Runner(),
    _buttons( {} ),
    _selectedOption( Runners::RunnerType::NONE ) {

    _font = Managers::FontManager::instance().font( FontType::Arial );

    initMenu();
}

MainMenuRunner::~MainMenuRunner() {
}

void MainMenuRunner::handleInput( sf::RenderWindow& window, const sf::Event& event, const sf::Time& deltaTime ) {

    sf::Vector2f mousePos = window.mapPixelToCoords( sf::Mouse::getPosition( window ) );

    for ( auto& button : _buttons ) {
        button.handleEvent( event, mousePos );
    }
}

void MainMenuRunner::update( sf::RenderWindow& window, const sf::Time& deltaTime ) {
}

void MainMenuRunner::render( sf::RenderWindow& window ) {
    window.setView( window.getDefaultView() );
    _labelTitle.render( window );

    for ( const auto& button : _buttons ) {
        // button.render( window );
    }
}

void MainMenuRunner::initMenu() {

    _labelTitle.setFont( _font );
    _labelTitle.setText( "Roguelike" );
    _labelTitle.setCharacterSize( 50 );
    _labelTitle.setColor( sf::Color::White );
    _labelTitle.setOutline( sf::Color::Green, 2 );
    _labelTitle.setPosition( 200, 100 );
    _labelTitle.setAlignment( GUI::Label::Alignment::Center, 800 );
    _labelTitle.setStyle( sf::Text::Bold );
    _labelTitle.setFade( 1.0f );

    std::vector<std::string> options = { "Start Game", "Upgrades", "Settings", "Exit" };

    for ( size_t i = 0; i < options.size(); ++i ) {
        GUI::Button button;
        button.setFont( _font );
        button.setCharacterSize( 24 );
        button.setPosition( 250, 200 + i * 50 );
        _buttons.push_back( button );
    }
}

bool MainMenuRunner::isMouseOverOption( const sf::Text& option, const sf::Vector2f& mousePos ) {
    return option.getGlobalBounds().contains( mousePos );
}

END_RUNNER_NAMESPACE
