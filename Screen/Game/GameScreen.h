#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include <Screen/ScreenGlobals.h>

#include <Controller/Collision/CollisionController.h>
#include <Controller/Input/InputController.h>
#include <Controller/Spawn/SpawnController.h>
#include <Controller/Update/UpdateController.h>
#include <Entity/Enemy/Enemy.h>
#include <Entity/Map/Map.h>
#include <Entity/Player/Player.h>
#include <Screen/Screen.h>

using Controller::CollisionController;
using Controller::InputController;
using Controller::SpawnController;
using Controller::UpdateController;
using Entity::Enemy;
using Entity::Map;
using Entity::Player;
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

    CollisionController _collisionController;
    InputController _inputController;
    SpawnController _spawnController;
    UpdateController _updateController;
};

END_SCREEN_NAMESPACE
