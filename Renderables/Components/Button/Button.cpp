#include "Button.h"

BEGIN_COMPONENTS_NAMESPACE

Button::Button() :
    Component( "Button" ), _hovered( false ) {
    _background.setSize( { 150.f, 50.f } );
    _defaultColor = sf::Color::Transparent;
    _hoverColor = sf::Color::Red;
    _background.setFillColor( _defaultColor );

    _text.setCharacterSize( 20 );
    _text.setFillColor( sf::Color::White );
}

void Button::setText( const std::string& text ) {
    _text.setString( text );
    sf::FloatRect bounds = _text.getLocalBounds();
    _text.setOrigin( bounds.left + bounds.width / 2, bounds.top + bounds.height / 2 );
    _text.setPosition( _background.getPosition() + _background.getSize() / 2.f );
}

void Button::setFont( const sf::Font& font ) {
    _text.setFont( font );
}

void Button::setCharacterSize( unsigned int size ) {
    _text.setCharacterSize( size );
}

void Button::setSize( float width, float height ) {
    _background.setSize( { width, height } );
    _text.setPosition( _background.getPosition() + _background.getSize() / 2.f );
}

void Button::setPosition( float x, float y ) {
    _background.setPosition( x, y );
    _text.setPosition( _background.getPosition() + _background.getSize() / 2.f );
}

void Button::setColors( sf::Color textColor, sf::Color backgroundColor, sf::Color hoverColor ) {
    _text.setFillColor( textColor );
    _defaultColor = backgroundColor;
    _hoverColor = hoverColor;
    _background.setFillColor( _defaultColor );
}

void Button::setCallback( std::function<void()> callback ) {
    _callback = std::move( callback );
}

void Button::update( const sf::Time& /*deltaTime*/ ) {
}

void Button::render( sf::RenderWindow& window ) {
    window.draw( _background );
    window.draw( _text );
}

void Button::handleEvent( const sf::Event& event, const sf::Vector2f& mousePosition ) {
    bool contains = _background.getGlobalBounds().contains( mousePosition );
    if ( contains && !_hovered ) {
        _hovered = true;
        _background.setFillColor( _hoverColor );

    } else if ( !contains && _hovered ) {
        _hovered = false;
        _background.setFillColor( _defaultColor );
    }

    if ( contains && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left ) {
        if ( _callback )
            _callback();
    }
}

END_COMPONENTS_NAMESPACE