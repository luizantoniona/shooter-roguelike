#include "Panel.h"

BEGIN_GUI_NAMESPACE

Panel::Panel() :
    Component( "Panel" ), _position( 0.f, 0.f ) {
    _background.setSize( { 0.f, 0.f } );
    _background.setFillColor( sf::Color::Transparent );
}

void Panel::setSize( float width, float height ) {
    _background.setSize( sf::Vector2f( width, height ) );
}

void Panel::addComponent( Component* component, const sf::Vector2f& localPosition ) {
    _components.emplace_back( component, localPosition );
}

void Panel::setPosition( float x, float y ) {
    _position = { x, y };
    _background.setPosition( _position );
}

void Panel::setBackgroundColor( sf::Color color ) {
    _background.setFillColor( color );
}

void Panel::update( const sf::Time& deltaTime ) {
    for ( auto& [ component, _ ] : _components ) {
        component->update( deltaTime );
    }
}

void Panel::render( sf::RenderWindow& window ) {
    window.draw( _background );
    for ( auto& [ component, localPos ] : _components ) {
        sf::RenderStates states;
        states.transform.translate( _position + localPos );
        window.draw( *dynamic_cast<const sf::Drawable*>( component ), states );
    }
}

END_GUI_NAMESPACE