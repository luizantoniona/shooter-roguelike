#include "HealthBar.h"

BEGIN_GUI_NAMESPACE

HealthBar::HealthBar( float maxHealth ) :
    Bar( "healthBar", 200, 20, sf::Color::Black, sf::Color::Green ), _maxHealth( maxHealth ) {
}

void HealthBar::setHealth( float health ) {
    float percentage = health / _maxHealth;
    setValue( percentage );

    if ( percentage > 0.6f ) {
        _fill.setFillColor( sf::Color::Green );
    } else if ( percentage > 0.3f ) {
        _fill.setFillColor( sf::Color::Yellow );
    } else {
        _fill.setFillColor( sf::Color::Red );
    }
}

END_GUI_NAMESPACE