#pragma once

#include <SFML/Graphics.hpp>

#include <Entity/EntityGlobals.h>

#include <Shape/Regular/RegularShape.h>

using Shapes::RegularShape;

BEGIN_ENTITY_NAMESPACE

class Entity {
public:
    Entity() = default;
    virtual ~Entity() = default;

    RegularShape& getShape();

protected:
    RegularShape _shape;
};

END_ENTITY_NAMESPACE