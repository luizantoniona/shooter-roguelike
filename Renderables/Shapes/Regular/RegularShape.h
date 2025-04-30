#pragma once

#include <SFML/Graphics.hpp>

#include <Renderables/Entities/Shapes/ShapesGlobals.h>

BEGIN_SHAPES_NAMESPACE

class RegularShape {
public:
    RegularShape();

    void setSides( int sides );
    int getSides() const;

    void setRadius( float radius );
    float getRadius() const;

    void setPosition( const sf::Vector2f& position );
    sf::Vector2f getPosition() const;

    void setColor( const sf::Color& color );
    sf::Color getColor() const;

    void setOutlineColor( const sf::Color& color );
    void setOutlineThickness( float thickness );

    sf::FloatRect getGlobalBounds() const;

    void render( sf::RenderWindow& window );
    void move( const sf::Vector2f& offset );

    void build();

private:
    int _sides;
    float _radius;
    sf::ConvexShape _shape;
};

END_SHAPES_NAMESPACE
