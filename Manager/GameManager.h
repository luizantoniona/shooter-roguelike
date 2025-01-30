#pragma once

#include <SFML/Graphics.hpp>

#include <Manager/ManagerGlobals.h>
#include <Manager/ScreenManager.h>

using Manager::ScreenManager;

BEGIN_MANAGER_NAMESPACE

class GameManager {
public:
    GameManager();
    void run();

private:
    sf::RenderWindow _window;
    sf::View _view;
    ScreenManager _screenManager;

    void processEvents( sf::Time& deltaTime );
    void update( sf::Time& deltaTime );
    void render();
    void adjustView();
};

END_MANAGER_NAMESPACE
