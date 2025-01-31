#include "Button.h"

BEGIN_GUI_NAMESPACE

Button::Button( const sf::String& text, const sf::Font& font, unsigned int characterSize, sf::Color color, sf::Color fillColor ) {
    _text.setFont( font );
    _text.setString( text );
    _text.setCharacterSize( characterSize );
    _text.setFillColor( color );

    _shape.setSize( sf::Vector2f( _text.getLocalBounds().width, _text.getLocalBounds().height ) );
    _shape.setFillColor( fillColor );
}

void Button::setPosition( float x, float y ) {
    _text.setPosition( x, y );
    _shape.setPosition( x, y );
}

void Button::setFillColor( const sf::Color& textColor, const sf::Color& rectangleColor ) {
    _text.setFillColor( textColor );
    _shape.setFillColor( rectangleColor );
}

void Button::setText( const sf::String& text ) {
    _text.setString( text );
    _shape.setSize( sf::Vector2f( _text.getLocalBounds().width, _text.getLocalBounds().height ) );
}

bool Button::isMouseOver( const sf::Vector2f& mousePos ) const {
    return _text.getGlobalBounds().contains( mousePos );
}

void Button::render( sf::RenderWindow& window ) const {
    window.draw( _shape );
    window.draw( _text );
}

END_GUI_NAMESPACE