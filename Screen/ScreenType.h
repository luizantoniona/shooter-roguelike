#pragma once

#include <cstdint>

#include <Screen/ScreenGlobals.h>

BEGIN_SCREEN_NAMESPACE

enum class ScreenType : int8_t {
    UNKNOW = -1,
    GameScreen = 0,
    UpgradeScreen = 1,
    SettingsScreen = 2,
    ExitScreen = 3,
    MainMenuScreen = INT8_MAX,
};

END_SCREEN_NAMESPACE
