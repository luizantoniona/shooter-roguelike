#pragma once

#include <SFML/Graphics.hpp>

#include <Manager/ManagerGlobals.h>

#include <Controller/Collision/CollisionController.h>
#include <Controller/Input/InputController.h>
#include <Controller/Spawn/SpawnController.h>
#include <Controller/Update/UpdateController.h>
#include <Entity/Enemy/Enemy.h>
#include <Entity/Map/Map.h>
#include <Entity/Player/Player.h>

using Controller::CollisionController;
using Controller::InputController;
using Controller::SpawnController;
using Controller::UpdateController;
using Entity::Enemy;
using Entity::Map;
using Entity::Player;

BEGIN_MANAGER_NAMESPACE

class GameManager {
public:
    GameManager();

    void handleInput( const sf::Event& event, sf::Time& deltaTime );
    void update( sf::RenderWindow& window, sf::Time& deltaTime );
    void render( sf::RenderWindow& window );

private:
    std::unique_ptr<Map> _map;
    std::unique_ptr<Player> _player;
    std::vector<std::unique_ptr<Enemy>> _enemies;

    CollisionController _collisionController;
    InputController _inputController;
    SpawnController _spawnController;
    UpdateController _updateController;
};

END_MANAGER_NAMESPACE