#pragma once

#include <SFML/Graphics.hpp>

#include <Renderables/Shapes/ShapesGlobals.h>

#include <Renderables/Shapes/Shape.h>

BEGIN_SHAPES_NAMESPACE

class RegularShape : public Shape {
public:
    RegularShape();

    void setPosition( const sf::Vector2f& position ) override;
    sf::Vector2f getPosition() const override;

    void setColor( const sf::Color& color ) override;
    sf::Color getColor() const override;

    void setSize( const float size ) override;
    float getSize() const override;

    void setSides( int sides ) override;
    int getSides() const override;

    void setOutlineColor( const sf::Color& color );
    void setOutlineThickness( float thickness );

    sf::FloatRect getGlobalBounds() const override;

    void build() override;

    void render( sf::RenderWindow& window ) override;
    void move( const sf::Vector2f& offset ) override;

private:
    int _sides;
    float _size;
    sf::ConvexShape _shape;
};

END_SHAPES_NAMESPACE
