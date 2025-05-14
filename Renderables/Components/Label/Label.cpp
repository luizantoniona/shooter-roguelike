#include "Label.h"

BEGIN_COMPONENTS_NAMESPACE

Label::Label() :
    Component( "Label" ) {
}

void Label::setText( const std::string& text ) {
    _text.setString( text );
}

void Label::setFont( const sf::Font& font ) {
    _text.setFont( font );
}

void Label::setCharacterSize( unsigned int size ) {
    _text.setCharacterSize( size );
}

void Label::setPosition( float x, float y ) {
    _text.setPosition( x, y );
}

void Label::setColor( sf::Color color ) {
    _text.setFillColor( color );
}

void Label::setOutline( sf::Color color, float thickness ) {
    _text.setOutlineColor( color );
    _text.setOutlineThickness( thickness );
}

void Label::setAlignment( Alignment alignment, float containerWidth ) {
    float textWidth = _text.getLocalBounds().width;
    float xPos = _text.getPosition().x;

    if ( alignment == Alignment::Center ) {
        xPos = ( containerWidth - textWidth ) / 2;
    } else if ( alignment == Alignment::Right ) {
        xPos = containerWidth - textWidth;
    }

    _text.setPosition( xPos, _text.getPosition().y );
}

void Label::setStyle( sf::Uint32 style ) {
    _text.setStyle( style );
}

void Label::setFade( float alpha ) {
    sf::Color color = _text.getFillColor();
    color.a = static_cast<sf::Uint8>( alpha * 255 );
    _text.setFillColor( color );
}

void Label::update( const sf::Time& deltaTime ) {
}

void Label::render( sf::RenderWindow& window ) {
    window.draw( _text );
}

END_COMPONENTS_NAMESPACE
