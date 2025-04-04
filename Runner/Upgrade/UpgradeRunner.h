#pragma once

#include <SFML/Graphics.hpp>

#include <Runner/RunnerGlobals.h>

#include <Runner/Runner.h>

BEGIN_RUNNER_NAMESPACE

class UpgradeRunner : public Runner {
public:
    UpgradeRunner();
    ~UpgradeRunner();

    void handleInput( const sf::Event& event, const sf::Time& deltaTime ) override;
    void update( sf::RenderWindow& window, const sf::Time& deltaTime ) override;
    void render( sf::RenderWindow& window ) override;
};

END_RUNNER_NAMESPACE