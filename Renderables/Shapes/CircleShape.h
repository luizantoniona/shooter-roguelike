#pragma once

#include <SFML/Graphics.hpp>

#include <Renderables/Shapes/ShapesGlobals.h>

#include <Renderables/Shapes/Shape.h>

BEGIN_SHAPES_NAMESPACE

class CircleShape : public Shape {
public:
    CircleShape();
    std::unique_ptr<Shape> clone() const override;

    void setFillColor( const sf::Color& color ) override;
    sf::Color getFillColor() const override;

    void setOutlineColor( const sf::Color& color ) override;
    sf::Color getOutlineColor() const override;

    void setOutlineThickness( float thickness ) override;
    float getOutlineThickness() const override;

    void setPosition( const sf::Vector2f& position ) override;
    sf::Vector2f getPosition() const override;

    void setRotation( float angle ) override;
    float getRotation() const override;

    void setScale( const sf::Vector2f& factors ) override;
    sf::Vector2f getScale() const override;

    void setOrigin( const sf::Vector2f& origin ) override;
    sf::Vector2f getOrigin() const override;

    std::size_t getPointCount() const override;

    sf::Vector2f getGeometricCenter() const override;

    sf::FloatRect getLocalBounds() const override;

    sf::FloatRect getGlobalBounds() const override;

    void move( const sf::Vector2f& offset ) override;

    void rotate( float angle ) override;

    void scale( const sf::Vector2f& factor ) override;

    void render( sf::RenderWindow& window ) override;

    void build() override;

    void setRadius( float radius );
    float getRadius() const;

private:
    sf::CircleShape _shape;
};

END_SHAPES_NAMESPACE
