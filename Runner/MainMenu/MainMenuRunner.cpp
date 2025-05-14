#include "MainMenuRunner.h"

#include <SFML/Graphics.hpp>

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
    _background.update( deltaTime );
}

void MainMenuRunner::render( sf::RenderWindow& window ) {
    window.setView( window.getDefaultView() );

    _background.render( window );

    _labelTitle.render( window );

    for ( auto& button : _buttons ) {
        button.render( window );
    }
}

void MainMenuRunner::initMenu() {

    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    sf::Vector2f windowSize( static_cast<float>( desktopMode.width ), static_cast<float>( desktopMode.height ) );

    float centerX = windowSize.x / 2.f;

    _labelTitle.setFont( _font );
    _labelTitle.setText( "Roguelike" );
    _labelTitle.setCharacterSize( windowSize.y * 0.05f );
    _labelTitle.setColor( sf::Color::White );
    _labelTitle.setOutline( sf::Color::Green, 2 );
    _labelTitle.setPosition( centerX, windowSize.y * 0.15f );
    _labelTitle.setAlignment( Components::Label::Alignment::Center, windowSize.x );
    _labelTitle.setStyle( sf::Text::Bold );
    _labelTitle.setFade( 1.0f );

    float buttonWidth = windowSize.x * 0.25f;
    float buttonHeight = windowSize.y * 0.05f;
    float startY = windowSize.y * 0.35f;
    float spacing = windowSize.y * 0.08f;

    std::vector<std::pair<std::string, RunnerType>> options = {
        { "Start Game", RunnerType::GAME },
        { "Upgrades", RunnerType::UPGRADE },
        { "Settings", RunnerType::SETTINGS },
        { "Exit", RunnerType::EXIT },
    };

    for ( std::size_t i = 0; i < options.size(); ++i ) {
        Components::Button button;
        button.setFont( _font );
        button.setCharacterSize( windowSize.y * 0.03f );
        button.setText( options[ i ].first );
        button.setPosition( centerX - ( buttonWidth / 2.0f ), startY + i * spacing );
        button.setSize( buttonWidth, buttonHeight );
        // button.setAlignment( Components::Button::Alignment::Center );
        button.setCallback( [ this, type = options[ i ].second ]() { _runnerCallback( type ); } );
        _buttons.push_back( button );
    }
}

END_RUNNER_NAMESPACE
