#include "Entity.h"

BEGIN_ENTITIES_NAMESPACE

Entity::Entity( const Entity& other ) {
    if ( other._shape ) {
        _shape = other._shape->clone();
    }
}

void Entity::setShape( std::unique_ptr<Shapes::Shape> shape ) {
    _shape = std::move( shape );
}

Shapes::Shape* Entity::getShape() {
    return _shape.get();
}

void Entity::render( sf::RenderWindow& window ) {
    if ( _shape ) {
        _shape->render( window );
    }
}

END_ENTITIES_NAMESPACE
