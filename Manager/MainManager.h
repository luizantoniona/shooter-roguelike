#pragma once

#include <SFML/Graphics.hpp>

#include <Manager/ManagerGlobals.h>

#include <Runner/Game/GameRunner.h>
#include <Runner/MainMenu/MainMenuRunner.h>
#include <Runner/Runner.h>
#include <Runner/RunnerType.h>
#include <Runner/Settings/SettingsRunner.h>
#include <Runner/Upgrade/UpgradeRunner.h>

BEGIN_MANAGER_NAMESPACE

class MainManager {
public:
    MainManager();

    void run();

    void processEvents( sf::Time& deltaTime );
    void update( sf::Time& deltaTime );
    void render();
    void adjustView();

    std::function<void( Runners::RunnerType )> runnersCallback();

private:
    sf::RenderWindow _window;
    sf::View _view;

    std::unique_ptr<Runners::Runner> _currentRunner;
    std::unique_ptr<Runners::GameRunner> _gameRunner;
    std::unique_ptr<Runners::UpgradeRunner> _upgradeRunner;
    std::unique_ptr<Runners::SettingsRunner> _settingsRunner;
    std::unique_ptr<Runners::MainMenuRunner> _mainMenuRunner;
};

END_MANAGER_NAMESPACE
