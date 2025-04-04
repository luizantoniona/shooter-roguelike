#pragma once

#include <SFML/Graphics.hpp>

#include <Runner/RunnerGlobals.h>

#include <Controller/GUI/GUIController.h>
#include <Controller/Input/InputController.h>
#include <Entity/Character/Character.h>
#include <Entity/Map/Map.h>
#include <GUI/Component.h>
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
    void createComponents();

private:
    std::unique_ptr<Entities::Map> _map;
    std::unique_ptr<Entities::Character> _player;
    std::vector<std::unique_ptr<Entities::Character>> _enemies;
    std::vector<std::unique_ptr<GUI::Component>> _components;

    Controllers::GUIController _guiController;
    Controllers::InputController _inputController;
};

END_RUNNER_NAMESPACE