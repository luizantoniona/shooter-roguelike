#pragma once

#include <Manager/ScreenManager.h>
#include <Screen/Screen.h>
#include <Screen/ScreenGlobals.h>

using Manager::ScreenManager;

BEGIN_SCREEN_NAMESPACE

class UpgradeScreen : public Screen {
public:
    UpgradeScreen();

    void handleInput( const sf::Event& event, sf::Time& deltaTime ) override;
    void update( sf::RenderWindow& window, sf::Time& deltaTime ) override;
    void render( sf::RenderWindow& window ) override;
};

END_SCREEN_NAMESPACE