#pragma once

#include "EntitiesGlobals.h"

#include <SFML/Graphics.hpp>

#include <Renderables/Renderable.h>
#include <Renderables/Shapes/Shape.h>

BEGIN_ENTITIES_NAMESPACE

class Entity : public Renderables::Renderable {
public:
    Entity() = default;
    Entity( const Entity& other );
    virtual ~Entity() = default;

    void render( sf::RenderWindow& window ) override;

    std::vector<std::unique_ptr<Shapes::Shape> >& getShapes();
    void setShapes( std::vector<std::unique_ptr<Shapes::Shape> > shapes );
    void clearShapes();

    Shapes::Shape& getShape( std::size_t index = 0 );
    void addShape( std::unique_ptr<Shapes::Shape> shape );
    void removeShape( std::size_t index = 0 );

protected:
    std::vector<std::unique_ptr<Shapes::Shape> > _shapes;
};

END_ENTITIES_NAMESPACE
