#pragma once

#include <SFML/Graphics.hpp>

#include <Renderables/Shapes/ShapesGlobals.h>

BEGIN_SHAPES_NAMESPACE

class Shape {
public:
    virtual ~Shape() = default;

    virtual void setPosition( const sf::Vector2f& pos ) = 0;
    virtual sf::Vector2f getPosition() const = 0;

    virtual void setColor( const sf::Color& color ) = 0;
    virtual sf::Color getColor() const = 0;

    virtual void setSize( const float size ) = 0;
    virtual float getSize() const = 0;

    virtual void setSides( const int sides ) = 0;
    virtual int getSides() const = 0;

    virtual sf::FloatRect getGlobalBounds() const = 0;

    virtual void build() = 0;

    virtual void render( sf::RenderWindow& window ) = 0;
    virtual void move( const sf::Vector2f& offset ) = 0;
};

END_SHAPES_NAMESPACE
