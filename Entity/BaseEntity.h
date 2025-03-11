#pragma once

#include <SFML/Graphics.hpp>

#include <Entity/EntityGlobals.h>

#include <Shape/Regular/RegularShape.h>

using Shapes::RegularShape;

BEGIN_ENTITY_NAMESPACE

class BaseEntity {
public:
    BaseEntity() = default;
    virtual ~BaseEntity() = default;

    RegularShape& getShape();

    virtual void update( const sf::RenderWindow& window, const sf::Time& deltaTime ) = 0;
    virtual void render( sf::RenderWindow& window );

protected:
    RegularShape _shape;
};

END_ENTITY_NAMESPACE