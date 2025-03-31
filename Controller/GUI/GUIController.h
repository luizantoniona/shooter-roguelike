#pragma once

#include <Controller/ControllerGlobals.h>

#include <Entity/Player/Player.h>
#include <GUI/Bar/HealthBar.h>
#include <GUI/Component.h>

BEGIN_CONTROLLER_NAMESPACE

class GUIController {
public:
    void updateComponents( Entities::Player& player, std::vector<std::unique_ptr<GUI::Component>>& components );

private:
    void updateHealthBar( GUI::HealthBar& healthBar, Entities::Player& player );
};

END_CONTROLLER_NAMESPACE