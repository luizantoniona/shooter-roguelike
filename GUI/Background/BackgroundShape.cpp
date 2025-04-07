#include "BackgroundShape.h"

#include <cmath>

BEGIN_GUI_NAMESPACE

BackgroundShape::BackgroundShape() :
    _type( Type::Circle ),
    _shape( nullptr ),
    _speed( 10.0f ),
    _rotationSpeed( 10.0f ),
    _alphaChange( 40.0f ),
    _currentAlpha( 100.0f ) {
}

void BackgroundShape::setType( Type type ) {
    _type = type;

    switch ( type ) {
    case Type::Circle:
        _shape = new sf::CircleShape( 30.f );
        break;
    case Type::Rectangle:
        _shape = new sf::RectangleShape( sf::Vector2f( 80.f, 40.f ) );
        break;
    case Type::Triangle:
        _shape = new sf::CircleShape( 40.f, 3 );
        break;
    }

    if ( _shape ) {
        _shape->setOrigin( _shape->getLocalBounds().width / 2.f, _shape->getLocalBounds().height / 2.f );
    }
}

void BackgroundShape::setPosition( const sf::Vector2f& position ) {
    if ( _shape ) {
        _shape->setPosition( position );
    }
}

void BackgroundShape::setColor( const sf::Color& color ) {
    if ( _shape ) {
        _shape->setFillColor( color );
    }
}

void BackgroundShape::setSpeed( float speed ) {
    _speed = speed;
}

void BackgroundShape::setRotationSpeed( float rotation ) {
    _rotationSpeed = rotation;
}

void BackgroundShape::update( const sf::Time& deltaTime, float windowHeight ) {
    float dt = deltaTime.asSeconds();

    if ( _shape ) {
        _shape->move( 0.f, -_speed * dt );
        _shape->rotate( _rotationSpeed * dt );

        float y = _shape->getPosition().y;
        float height = _shape->getGlobalBounds().height;

        if ( y < -height / 2.f || y > windowHeight + height / 2.f ) {
            _speed *= -1.f;
        }
    }
}

void BackgroundShape::render( sf::RenderWindow& window ) {
    if ( _shape )
        window.draw( *_shape );
}

END_GUI_NAMESPACE