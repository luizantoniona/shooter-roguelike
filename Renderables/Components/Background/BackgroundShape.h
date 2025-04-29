#pragma once

#include <SFML/Graphics.hpp>

#include <Renderables/Components/ComponentsGlobals.h>

BEGIN_COMPONENTS_NAMESPACE

class BackgroundShape {
public:
    enum class Type {
        Circle,
        Rectangle,
        Triangle
    };

    BackgroundShape();

    void setType( Type type );
    void setPosition( const sf::Vector2f& position );
    void setColor( const sf::Color& color );
    void setSpeed( float speed );
    void setRotationSpeed( float rotation );

    void update( const sf::Time& deltaTime, float windowHeight );
    void render( sf::RenderWindow& window );

private:
    Type _type;
    sf::Shape* _shape;

    float _speed;
    float _rotationSpeed;
    float _alphaChange;
    float _currentAlpha;
};

END_COMPONENTS_NAMESPACE
