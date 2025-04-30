#pragma once

#include "EntitiesGlobals.h"

#include <SFML/Graphics.hpp>

#include <Renderables/Entities/Shapes/Regular/RegularShape.h>
#include <Renderables/Renderable.h>

BEGIN_ENTITIES_NAMESPACE

class Entity : public Renderables::Renderable {
public:
    Entity() = default;
    virtual ~Entity() = default;

    void render( sf::RenderWindow& window ) override;

    Shapes::RegularShape& getShape();

protected:
    Shapes::RegularShape _shape;
};

END_ENTITIES_NAMESPACE
