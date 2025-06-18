#include "SettingsRunner.h"

BEGIN_RUNNER_NAMESPACE

SettingsRunner::SettingsRunner() :
    Runner() {}

SettingsRunner::~SettingsRunner() {}

void SettingsRunner::handleInput( sf::RenderWindow& window, const sf::Event& event, const sf::Time& deltaTime ) {

    if ( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape ) {
        _runnerCallback( RunnerType::MENU );
    }
}

void SettingsRunner::update( sf::RenderWindow& window, const sf::Time& deltaTime ) {}

void SettingsRunner::render( sf::RenderWindow& window ) {}

END_RUNNER_NAMESPACE
