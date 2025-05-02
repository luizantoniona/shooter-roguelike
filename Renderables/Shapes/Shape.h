#pragma once

#include <SFML/Graphics.hpp>

#include <Renderables/Shapes/ShapesGlobals.h>

BEGIN_SHAPES_NAMESPACE

class Shape {
public:
    virtual ~Shape() = default;

    virtual void setFillColor( const sf::Color& color ) = 0;
    virtual sf::Color getFillColor() const = 0;

    virtual void setOutlineColor( const sf::Color& color ) = 0;
    virtual sf::Color getOutlineColor() const = 0;

    virtual void setOutlineThickness( float thickness ) = 0;
    virtual float getOutlineThickness() const = 0;

    virtual void setPosition( const sf::Vector2f& position ) = 0;
    virtual sf::Vector2f getPosition() const = 0;

    virtual void setRotation( float angle ) = 0;
    virtual float getRotation() const = 0;

    virtual void setScale( const sf::Vector2f& factors ) = 0;
    virtual sf::Vector2f getScale() const = 0;

    virtual void setOrigin( const sf::Vector2f& origin ) = 0;
    virtual sf::Vector2f getOrigin() const = 0;

    virtual std::size_t getPointCount() const = 0;

    virtual sf::Vector2f getGeometricCenter() const = 0;

    virtual sf::FloatRect getLocalBounds() const = 0;

    virtual sf::FloatRect getGlobalBounds() const = 0;

    virtual void move( const sf::Vector2f& offset ) = 0;

    virtual void rotate( float angle ) = 0;

    virtual void scale( const sf::Vector2f& factor ) = 0;

    virtual void render( sf::RenderWindow& window ) = 0;

    virtual void build() = 0;
};

END_SHAPES_NAMESPACE
