#pragma once

#include <SFML/Graphics.hpp>

#include <Manager/ManagerGlobals.h>

BEGIN_MANAGER_NAMESPACE

class MainManager {
public:
    MainManager();
    void run();

private:
    sf::RenderWindow _window;
    sf::View _view;

    void processEvents( sf::Time& deltaTime );
    void update( sf::Time& deltaTime );
    void render();
    void adjustView();
};

END_MANAGER_NAMESPACE