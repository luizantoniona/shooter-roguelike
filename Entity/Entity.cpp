#include "Entity.h"

BEGIN_ENTITY_NAMESPACE

RegularShape& Entity::getShape() {
    return _shape;
}

void Entity::render( sf::RenderWindow& window ) {
    _shape.render( window );
}

END_ENTITY_NAMESPACE