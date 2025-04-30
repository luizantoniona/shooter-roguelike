#pragma once

#include "EntitiesGlobals.h"

#include <SFML/Graphics.hpp>

#include <Renderables/Renderable.h>
#include <Renderables/Shapes/Shape.h>

BEGIN_ENTITIES_NAMESPACE

class Entity : public Renderables::Renderable {
public:
    Entity() = default;
    virtual ~Entity() = default;

    void setShape( std::unique_ptr<Shapes::Shape> shape );
    Shapes::Shape* getShape();

    void render( sf::RenderWindow& window ) override;

protected:
    std::unique_ptr<Shapes::Shape> _shape;
};

END_ENTITIES_NAMESPACE
