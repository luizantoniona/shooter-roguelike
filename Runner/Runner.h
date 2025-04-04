#pragma once

#include <SFML/Graphics.hpp>

#include <Runner/RunnerGlobals.h>

#include <Runner/RunnerType.h>

using RunnerCallback = std::function<void( const Runners::RunnerType& runnerType )>;

BEGIN_RUNNER_NAMESPACE

class Runner {
public:
    Runner();
    virtual ~Runner() = default;

    virtual void handleInput( const sf::Event& event, const sf::Time& deltaTime ) = 0;
    virtual void update( sf::RenderWindow& window, const sf::Time& deltaTime ) = 0;
    virtual void render( sf::RenderWindow& window ) = 0;

    void setRunnerCallback( RunnerCallback callback );

protected:
    RunnerCallback _runnerCallback;
};

END_RUNNER_NAMESPACE