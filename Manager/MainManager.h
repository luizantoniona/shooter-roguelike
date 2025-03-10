#pragma once

#include <SFML/Graphics.hpp>

#include <Manager/ManagerGlobals.h>

#include <Manager/Game/GameManager.h>
#include <Manager/MainMenu/MainMenuManager.h>
#include <Manager/Upgrade/UpgradeManager.h>

BEGIN_MANAGER_NAMESPACE

class MainManager {
public:
    MainManager();

    void run();

private:
    sf::RenderWindow _window;
    sf::View _view;

    Manager::GameManager* _gameManager;
    Manager::MainMenuManger* _mainMenuManager;
    Manager::UpgradeManager* _upgradeManager;
};

END_MANAGER_NAMESPACE