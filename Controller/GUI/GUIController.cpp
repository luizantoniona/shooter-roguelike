#include "GUIController.h"

namespace {
constexpr const char* HEALTH_BAR_COMPONENT = "healthBar";
}

BEGIN_CONTROLLER_NAMESPACE

void GUIController::updateComponents( Entities::Character& player, std::vector<std::unique_ptr<Components::Component>>& components ) {

    for ( auto& component : components ) {

        if ( component.get()->getComponentName() == HEALTH_BAR_COMPONENT ) {

            auto* healthBar = dynamic_cast<Components::HealthBar*>( component.get() );

            if ( healthBar ) {
                updateHealthBar( *healthBar, player );
                break;
            }
        }
    }
}

void GUIController::updateHealthBar( Components::HealthBar& healthBar, Entities::Character& player ) {
    const int playerHealth = player.getStatus().getHealth();

    if ( playerHealth > 0 ) {
        healthBar.setHealth( player.getStatus().getHealth() );
    }
}

END_CONTROLLER_NAMESPACE
