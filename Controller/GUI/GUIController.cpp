#include "GUIController.h"

namespace {
constexpr const char* HEALTH_BAR_COMPONENT = "healthBar";
}

BEGIN_CONTROLLER_NAMESPACE

void GUIController::updateComponents( Entities::Player& player, std::vector<std::unique_ptr<GUI::Component>>& components ) {

    for ( auto& component : components ) {

        if ( component.get()->getComponentName() == HEALTH_BAR_COMPONENT ) {

            auto* healthBar = dynamic_cast<GUI::HealthBar*>( component.get() );

            if ( healthBar ) {
                updateHealthBar( *healthBar, player );
                break;
            }
        }
    }
}

void GUIController::updateHealthBar( GUI::HealthBar& healthBar, Entities::Player& player ) {
    const int playerHealth = player.getPlayerStatus().getHealth();

    if ( playerHealth > 0 ) {
        healthBar.setHealth( player.getPlayerStatus().getHealth() );
    }
}

END_CONTROLLER_NAMESPACE