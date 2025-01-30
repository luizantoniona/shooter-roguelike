#include "Shape.h"

#include <cmath>

Shape::Shape( int sides, float radius, const sf::Vector2f& position, const sf::Color& color )
    : _sides( sides ), _radius( radius ), _position( position ), _color( color ), _shape( sf::TrianglesFan ) {

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

void Shape::setColor( const sf::Color& color ) {
    _color = color;
    updateShape();
}

void Shape::setPosition( const sf::Vector2f& position ) {
    _position = position;
    updateShape();
}

sf::Vector2f Shape::getPosition() const {
    return _position;
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