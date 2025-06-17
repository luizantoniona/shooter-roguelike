#include "UpgradeRunner.h"

BEGIN_RUNNER_NAMESPACE

UpgradeRunner::UpgradeRunner() :
    Runner() {}

UpgradeRunner::~UpgradeRunner() {}

void UpgradeRunner::handleInput( sf::RenderWindow& window, const sf::Event& event, const sf::Time& deltaTime ) {

    if ( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape ) {
        _runnerCallback( RunnerType::MENU );
    }

}

void UpgradeRunner::update( sf::RenderWindow& window, const sf::Time& deltaTime ) {}

void UpgradeRunner::render( sf::RenderWindow& window ) {}

END_RUNNER_NAMESPACE
