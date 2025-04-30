#include "Entity.h"

BEGIN_ENTITIES_NAMESPACE

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
