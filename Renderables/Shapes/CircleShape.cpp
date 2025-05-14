#include "CircleShape.h"

BEGIN_SHAPES_NAMESPACE

CircleShape::CircleShape() :
    _shape() {
}

std::unique_ptr<Shape> CircleShape::clone() const {
    return std::make_unique<CircleShape>( *this );
}

void CircleShape::setFillColor( const sf::Color& color ) {
    _shape.setFillColor( color );
}

sf::Color CircleShape::getFillColor() const {
    return _shape.getFillColor();
}

void CircleShape::setOutlineColor( const sf::Color& color ) {
    _shape.setOutlineColor( color );
}

sf::Color CircleShape::getOutlineColor() const {
    return _shape.getOutlineColor();
}

void CircleShape::setOutlineThickness( float thickness ) {
    _shape.setOutlineThickness( thickness );
}

float CircleShape::getOutlineThickness() const {
    return _shape.getOutlineThickness();
}

void CircleShape::setPosition( const sf::Vector2f& position ) {
    _shape.setPosition( position );
}

sf::Vector2f CircleShape::getPosition() const {
    return _shape.getPosition();
}

void CircleShape::setRotation( float angle ) {
    _shape.setRotation( angle );
}

float CircleShape::getRotation() const {
    return _shape.getRotation();
}

void CircleShape::setScale( const sf::Vector2f& factors ) {
    _shape.setScale( factors );
}

sf::Vector2f CircleShape::getScale() const {
    return _shape.getScale();
}

void CircleShape::setOrigin( const sf::Vector2f& origin ) {
    _shape.setOrigin( origin );
}

sf::Vector2f CircleShape::getOrigin() const {
    return _shape.getOrigin();
}

std::size_t CircleShape::getPointCount() const {
    return _shape.getPointCount();
}

sf::Vector2f CircleShape::getGeometricCenter() const {
    return _shape.getOrigin();
}

sf::FloatRect CircleShape::getLocalBounds() const {
    return _shape.getLocalBounds();
}

sf::FloatRect CircleShape::getGlobalBounds() const {
    return _shape.getGlobalBounds();
}

void CircleShape::move( const sf::Vector2f& offset ) {
    _shape.move( offset );
}

void CircleShape::rotate( float angle ) {
    _shape.rotate( angle );
}

void CircleShape::scale( const sf::Vector2f& factor ) {
    _shape.scale( factor );
}

void CircleShape::render( sf::RenderWindow& window ) {
    window.draw( _shape );
}

void CircleShape::build() {
    // Nothing to build for sf::CircleShape
}

void CircleShape::setRadius( float radius ) {
    _shape.setRadius( radius );
}

float CircleShape::getRadius() const {
    return _shape.getRadius();
}

END_SHAPES_NAMESPACE
