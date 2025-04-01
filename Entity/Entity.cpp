#include "Entity.h"

BEGIN_ENTITY_NAMESPACE

RegularShape& Entity::getShape() {
    return _shape;
}

END_ENTITY_NAMESPACE