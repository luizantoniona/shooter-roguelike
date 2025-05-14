#include "RegularShape.h"

#include <cmath>

BEGIN_SHAPES_NAMESPACE

RegularShape::RegularShape() :
    _sides( 0 ),
    _size( 0.f ),
    _shape() {
}

std::unique_ptr<Shape> RegularShape::clone() const {
    return std::make_unique<RegularShape>( *this );
}

void RegularShape::setFillColor( const sf::Color& color ) {
    _shape.setFillColor( color );
}

sf::Color RegularShape::getFillColor() const {
    return _shape.getFillColor();
}

void RegularShape::setOutlineColor( const sf::Color& color ) {
    _shape.setOutlineColor( color );
}

sf::Color RegularShape::getOutlineColor() const {
    return _shape.getOutlineColor();
}

void RegularShape::setOutlineThickness( float thickness ) {
    _shape.setOutlineThickness( thickness );
}

float RegularShape::getOutlineThickness() const {
    return _shape.getOutlineThickness();
}

void RegularShape::setPosition( const sf::Vector2f& position ) {
    _shape.setPosition( position );
}

sf::Vector2f RegularShape::getPosition() const {
    return _shape.getPosition();
}

void RegularShape::setRotation( float angle ) {
    _shape.setRotation( angle );
}

float RegularShape::getRotation() const {
    return _shape.getRotation();
}

void RegularShape::setScale( const sf::Vector2f& factors ) {
    _shape.setScale( factors );
}

sf::Vector2f RegularShape::getScale() const {
    return _shape.getScale();
}

void RegularShape::setOrigin( const sf::Vector2f& origin ) {
    _shape.setOrigin( origin );
}

sf::Vector2f RegularShape::getOrigin() const {
    return _shape.getOrigin();
}

std::size_t RegularShape::getPointCount() const {
    return _shape.getPointCount();
}

sf::Vector2f RegularShape::getGeometricCenter() const {
    return _shape.getOrigin();
}

sf::FloatRect RegularShape::getLocalBounds() const {
    return _shape.getLocalBounds();
}

sf::FloatRect RegularShape::getGlobalBounds() const {
    return _shape.getGlobalBounds();
}

void RegularShape::move( const sf::Vector2f& offset ) {
    _shape.move( offset );
}

void RegularShape::rotate( float angle ) {
    _shape.rotate( angle );
}

void RegularShape::scale( const sf::Vector2f& factor ) {
    _shape.scale( factor );
}

void RegularShape::render( sf::RenderWindow& window ) {
    window.draw( _shape );
}

void RegularShape::build() {
    _shape.setPointCount( _sides );

    float angleStep = 2.f * 3.14159265f / _sides;

    for ( int i = 0; i < _sides; ++i ) {
        float angle = i * angleStep - 3.14159265f / 2.f;
        sf::Vector2f point( _size * std::cos( angle ), _size * std::sin( angle ) );
        _shape.setPoint( i, point );
    }
}

void RegularShape::setSize( float size ) {
    _size = size;
}

float RegularShape::getSize() const {
    return _size;
}

void RegularShape::setSides( int sides ) {
    _sides = sides;
}

int RegularShape::getSides() const {
    return _sides;
}

END_SHAPES_NAMESPACE
