#pragma once

#include <Manager/ScreenManager.h>
#include <Screen/Screen.h>
#include <Screen/ScreenGlobals.h>

using Manager::ScreenManager;

BEGIN_SCREEN_NAMESPACE

class UpgradeScreen : public Screen {
public:
    UpgradeScreen( int windowWidth, int windowHeight, ScreenManager& screenManager );
};

END_SCREEN_NAMESPACE