#include "Shape.h"

#include <cmath>

Shape::Shape() :
    _sides( 3 ),
    _radius( 0 ),
    _position( 0, 0 ),
    _color( sf::Color::White ),
    _shape( sf::TrianglesFan ) {
}

void Shape::setSides( int sides ) {
    _sides = sides;
}

int Shape::getSides() const {
    return _sides;
}

void Shape::setRadius( float radius ) {
    _radius = radius;
}

float Shape::getRadius() const {
    return _radius;
}

void Shape::setColor( const sf::Color& color ) {
    _color = color;
}

sf::Color Shape::getColor() const {
    return _color;
}

void Shape::setPosition( const sf::Vector2f& position ) {
    _position = position;
}

sf::Vector2f Shape::getPosition() const {
    return _position;
}

void Shape::build() {

    _shape.append( sf::Vertex( _position, _color ) );

    float angleStep = 2 * 3.14159f / _sides;
    for ( int i = 0; i <= _sides; ++i ) {
        float angle = i * angleStep;
        sf::Vector2f point( _position.x + _radius * cos( angle ), _position.y + _radius * sin( angle ) );
        _shape.append( sf::Vertex( point, _color ) );
    }
}

void Shape::render( sf::RenderWindow& window ) {
    window.draw( _shape );
}

void Shape::move( const sf::Vector2f& offset ) {
    _position += offset;
    updateShape();
}

sf::FloatRect Shape::getGlobalBounds() const {
    return _shape.getBounds();
}

void Shape::updateShape() {
    _shape.clear();
    _shape.append( sf::Vertex( _position, _color ) );

    float angleStep = 2 * 3.14159f / _sides;
    for ( int i = 0; i <= _sides; ++i ) {
        float angle = i * angleStep;
        sf::Vector2f point( _position.x + _radius * cos( angle ), _position.y + _radius * sin( angle ) );
        _shape.append( sf::Vertex( point, _color ) );
    }
}