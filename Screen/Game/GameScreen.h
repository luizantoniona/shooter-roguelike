#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include <Entity/Enemy/Enemy.h>
#include <Entity/Map/Map.h>
#include <Entity/Player/Player.h>
#include <Handler/InputHandler.h>
#include <Handler/UpdateHandler.h>
#include <Screen/Screen.h>
#include <Screen/ScreenGlobals.h>

using Entity::Enemy;
using Entity::Map;
using Entity::Player;
using Handler::InputHandler;
using Handler::UpdateHandler;
using Screens::Screen;

BEGIN_SCREEN_NAMESPACE

class GameScreen : public Screen {
public:
    GameScreen( int windowWidth, int windowHeight );

    void handleInput( const sf::Event& event, sf::Time& deltaTime ) override;
    void update( sf::RenderWindow& window, sf::Time& deltaTime ) override;
    void render( sf::RenderWindow& window ) override;

private:
    Map _map;
    Player _player;
    std::vector<Enemy> _enemies;
    InputHandler _inputHandler;
    UpdateHandler _updateHandler;
};

END_SCREEN_NAMESPACE
