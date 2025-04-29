#include "Entity.h"

BEGIN_ENTITIES_NAMESPACE

Shapes::RegularShape& Entity::getShape() {
    return _shape;
}

void Entity::render( sf::RenderWindow& window ) {
    _shape.render( window );
}

END_ENTITIES_NAMESPACE