#pragma once

#include <SFML/Graphics.hpp>

class Shape {
public:
    Shape( int sides, float radius, const sf::Vector2f& position, const sf::Color& color );
    void render( sf::RenderWindow& window );
    void move( const sf::Vector2f& offset );
    void setColor( const sf::Color& color );

    void setPosition( const sf::Vector2f& position );
    sf::Vector2f getPosition() const;

protected:
    void updateShape();

private:
    int _sides;
    float _radius;
    sf::Vector2f _position;
    sf::Color _color;
    sf::VertexArray _shape;
};