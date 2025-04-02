#include "Bar.h"

float clip( float n, float lower, float upper ) {
    return std::max( lower, std::min( n, upper ) );
}

BEGIN_GUI_NAMESPACE

Bar::Bar( std::string componentName, float width, float height, sf::Color backgroundColor, sf::Color fillColor ) :
    Component( componentName ),
    _value( 1.0f ) {
    _background.setSize( { width, height } );
    _background.setFillColor( backgroundColor );

    _fill.setSize( { width, height } );
    _fill.setFillColor( fillColor );
}

void Bar::update( sf::Time& deltaTime ) {
}

void Bar::render( sf::RenderWindow& window ) {
    window.draw( _background );
    window.draw( _fill );
}

void Bar::setValue( float value ) {
    _value = clip( value, 0.0f, 1.0f );
    _fill.setSize( { _background.getSize().x * _value, _background.getSize().y } );
}

END_GUI_NAMESPACE