#pragma once

#include <SFML/Graphics.hpp>

#include <Manager/ManagerGlobals.h>

#include <Runner/Game/GameRunner.h>
#include <Runner/MainMenu/MainMenuRunner.h>
#include <Runner/Runner.h>
#include <Runner/Upgrade/UpgradeRunner.h>

using Runners::GameRunner;
using Runners::MainMenuRunner;
using Runners::Runner;
using Runners::UpgradeRunner;

BEGIN_MANAGER_NAMESPACE

class MainManager {
public:
    MainManager();

    void run();

    void processEvents( sf::Time& deltaTime );
    void update( sf::Time& deltaTime );
    void render();
    void adjustView();

private:
    sf::RenderWindow _window;
    sf::View _view;

    Runner* _currentRunner;
    GameRunner* _gameRunner;
    MainMenuRunner* _mainMenuRunner;
    UpgradeRunner* _upgradeRunner;
};

END_MANAGER_NAMESPACE