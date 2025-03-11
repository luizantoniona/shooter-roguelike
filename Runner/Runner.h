#pragma once

#include <SFML/Graphics.hpp>

#include <Runner/RunnerGlobals.h>

BEGIN_RUNNER_NAMESPACE

class Runner {
public:
    Runner();
    virtual ~Runner() = default;

    virtual void handleInput( const sf::Event& event, const sf::Time& deltaTime ) = 0;
    virtual void update( sf::RenderWindow& window, const sf::Time& deltaTime ) = 0;
    virtual void render( sf::RenderWindow& window ) = 0;
};

END_RUNNER_NAMESPACE