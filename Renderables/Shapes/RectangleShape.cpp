#include "RectangleShape.h"

BEGIN_SHAPES_NAMESPACE

RectangleShape::RectangleShape() :
    _shape() {
}

std::unique_ptr<Shape> RectangleShape::clone() const {
    return std::make_unique<RectangleShape>( *this );
}

void RectangleShape::setFillColor( const sf::Color& color ) {
    _shape.setFillColor( color );
}

sf::Color RectangleShape::getFillColor() const {
    return _shape.getFillColor();
}

void RectangleShape::setOutlineColor( const sf::Color& color ) {
    _shape.setOutlineColor( color );
}

sf::Color RectangleShape::getOutlineColor() const {
    return _shape.getOutlineColor();
}

void RectangleShape::setOutlineThickness( float thickness ) {
    _shape.setOutlineThickness( thickness );
}

float RectangleShape::getOutlineThickness() const {
    return _shape.getOutlineThickness();
}

void RectangleShape::setPosition( const sf::Vector2f& position ) {
    _shape.setPosition( position );
}

sf::Vector2f RectangleShape::getPosition() const {
    return _shape.getPosition();
}

void RectangleShape::setRotation( float angle ) {
    _shape.setRotation( angle );
}

float RectangleShape::getRotation() const {
    return _shape.getRotation();
}

void RectangleShape::setScale( const sf::Vector2f& factors ) {
    _shape.setScale( factors );
}

sf::Vector2f RectangleShape::getScale() const {
    return _shape.getScale();
}

void RectangleShape::setOrigin( const sf::Vector2f& origin ) {
    _shape.setOrigin( origin );
}

sf::Vector2f RectangleShape::getOrigin() const {
    return _shape.getOrigin();
}

std::size_t RectangleShape::getPointCount() const {
    return _shape.getPointCount();
}

sf::Vector2f RectangleShape::getGeometricCenter() const {
    return _shape.getOrigin() + ( _shape.getSize() / 2.f );
}

sf::FloatRect RectangleShape::getLocalBounds() const {
    return _shape.getLocalBounds();
}

sf::FloatRect RectangleShape::getGlobalBounds() const {
    return _shape.getGlobalBounds();
}

void RectangleShape::move( const sf::Vector2f& offset ) {
    _shape.move( offset );
}

void RectangleShape::rotate( float angle ) {
    _shape.rotate( angle );
}

void RectangleShape::scale( const sf::Vector2f& factor ) {
    _shape.scale( factor );
}

void RectangleShape::render( sf::RenderWindow& window ) {
    window.draw( _shape );
}

void RectangleShape::build() {
    // Nothing to build for sf::RectangleShape
}

void RectangleShape::setSize( const sf::Vector2f& size ) {
    _shape.setSize( size );
}

sf::Vector2f RectangleShape::getSize() const {
    return _shape.getSize();
}

END_SHAPES_NAMESPACE
