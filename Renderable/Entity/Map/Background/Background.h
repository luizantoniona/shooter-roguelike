#pragma once

#include <SFML/Graphics.hpp>

#include <Entity/EntityGlobals.h>

BEGIN_ENTITY_NAMESPACE

class Background {
public:
    Background();
    ~Background();

    virtual void update( sf::Time& deltaTime );
    virtual void render( sf::RenderWindow& window );
};

END_ENTITY_NAMESPACE