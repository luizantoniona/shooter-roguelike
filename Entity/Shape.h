#pragma once

#include <SFML/Graphics.hpp>

class Shape {
public:
    Shape();

    void setSides( int sides );
    int getSides() const;

    void setRadius( float radius );
    float getRadius() const;

    void setPosition( const sf::Vector2f& position );
    sf::Vector2f getPosition() const;

    void setColor( const sf::Color& color );
    sf::Color getColor() const;

    void build();

    sf::FloatRect getGlobalBounds() const;

    void render( sf::RenderWindow& window );
    void move( const sf::Vector2f& offset );

protected:
    void updateShape();

private:
    int _sides;
    float _radius;
    sf::Vector2f _position;
    sf::Color _color;
    sf::VertexArray _shape;
};