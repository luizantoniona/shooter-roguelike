#pragma once

#include <SFML/Graphics.hpp>

#include <Runner/RunnerGlobals.h>

#include <Controller/Collision/CollisionController.h>
#include <Controller/Input/InputController.h>
#include <Controller/Spawn/SpawnController.h>
#include <Controller/Update/UpdateController.h>
#include <Entity/Enemy/Enemy.h>
#include <Entity/Map/Map.h>
#include <Entity/Player/Player.h>
#include <Runner/Runner.h>

BEGIN_RUNNER_NAMESPACE

class GameRunner : public Runner {
public:
    GameRunner();
    ~GameRunner();

    void handleInput( const sf::Event& event, const sf::Time& deltaTime ) override;
    void update( sf::RenderWindow& window, const sf::Time& deltaTime ) override;
    void render( sf::RenderWindow& window ) override;

private:
    std::unique_ptr<Entities::Map> _map;
    std::unique_ptr<Entities::Player> _player;
    std::vector<std::unique_ptr<Entities::Enemy>> _enemies;

    Controllers::CollisionController _collisionController;
    Controllers::InputController _inputController;
    Controllers::SpawnController _spawnController;
    Controllers::UpdateController _updateController;
};

END_RUNNER_NAMESPACE