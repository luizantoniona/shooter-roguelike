#include "RegularShape.h"

#include <cmath>

BEGIN_SHAPES_NAMESPACE

RegularShape::RegularShape() :
    _sides( 0 ),
    _radius( 0 ),
    _shape() {
}

void RegularShape::setSides( int sides ) {
    _sides = sides;
}

int RegularShape::getSides() const {
    return _sides;
}

void RegularShape::setRadius( float radius ) {
    _radius = radius;
}

float RegularShape::getRadius() const {
    return _radius;
}

void RegularShape::setPosition( const sf::Vector2f& position ) {
    _shape.setPosition( position );
}

sf::Vector2f RegularShape::getPosition() const {
    return _shape.getPosition();
}

void RegularShape::setColor( const sf::Color& color ) {
    _shape.setFillColor( color );
}

sf::Color RegularShape::getColor() const {
    return _shape.getFillColor();
}

void RegularShape::setOutlineColor( const sf::Color& color ) {
    _shape.setOutlineColor( color );
}

void RegularShape::setOutlineThickness( float thickness ) {
    _shape.setOutlineThickness( thickness );
}

sf::FloatRect RegularShape::getGlobalBounds() const {
    return _shape.getGlobalBounds();
}

void RegularShape::render( sf::RenderWindow& window ) {
    window.draw( _shape );
}

void RegularShape::move( const sf::Vector2f& offset ) {
    _shape.move( offset );
}

void RegularShape::build() {
    _shape.setPointCount( _sides );

    float angleStep = 2 * 3.14159f / _sides;
    for ( int i = 0; i < _sides; ++i ) {
        float angle = i * angleStep - 3.14159f / 2;
        sf::Vector2f point( _radius * cos( angle ), _radius * sin( angle ) );
        _shape.setPoint( i, point );
    }
}

END_SHAPES_NAMESPACE
