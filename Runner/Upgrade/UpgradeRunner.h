#pragma once

#include <SFML/Graphics.hpp>

#include <Runner/RunnerGlobals.h>

#include <Runner/Runner.h>

BEGIN_RUNNER_NAMESPACE

class UpgradeRunner : public Runner {
public:
    UpgradeRunner();
    ~UpgradeRunner();

    void handleInput( const sf::Event& event, const sf::Time& deltaTime ) override = 0;
    void update( sf::RenderWindow& window, const sf::Time& deltaTime ) override = 0;
    void render( sf::RenderWindow& window ) override = 0;
};

END_RUNNER_NAMESPACE