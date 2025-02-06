#pragma once

#include <SFML/Graphics.hpp>

#include <Entity/EntityGlobals.h>

BEGIN_ENTITY_NAMESPACE

class BaseEntity {
public:
    BaseEntity() = default;
    virtual ~BaseEntity() = default;

    virtual void update( const sf::RenderWindow& window, const sf::Time& deltaTime ) = 0;
    virtual void render( sf::RenderWindow& window ) = 0;
    virtual void handleInput( const sf::Event& event ) = 0;
};

END_ENTITY_NAMESPACE