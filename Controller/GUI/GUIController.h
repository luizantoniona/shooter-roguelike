#pragma once

#include <Controller/ControllerGlobals.h>

#include <Entity/Character/Character.h>
#include <GUI/Bar/HealthBar.h>
#include <GUI/Component.h>

BEGIN_CONTROLLER_NAMESPACE

class GUIController {
public:
    void updateComponents( Entities::Character& player, std::vector<std::unique_ptr<GUI::Component>>& components );

private:
    void updateHealthBar( GUI::HealthBar& healthBar, Entities::Character& player );
};

END_CONTROLLER_NAMESPACE