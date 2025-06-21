#pragma once

#include <Controller/ControllerGlobals.h>

#include <Entities/Character/Character.h>
#include <Renderables/Components/Bar/HealthBar.h>
#include <Renderables/Components/Component.h>

BEGIN_CONTROLLER_NAMESPACE

class GUIController {
public:
    static void updateComponents( Entities::Character& player, std::vector<std::unique_ptr<Components::Component> >& components );

private:
    static void updateHealthBar( Components::HealthBar& healthBar, Entities::Character& player );
};

END_CONTROLLER_NAMESPACE
