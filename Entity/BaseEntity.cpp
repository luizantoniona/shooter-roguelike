#include "BaseEntity.h"

BEGIN_ENTITY_NAMESPACE

RegularShape& BaseEntity::getShape() {
    return _shape;
}

void BaseEntity::render( sf::RenderWindow& window ) {
    _shape.render( window );
}

END_ENTITY_NAMESPACE