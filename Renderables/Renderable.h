#pragma once

#include "RenderablesGlobals.h"

#include <SFML/Graphics.hpp>

BEGIN_RENDERABLES_NAMESPACE

class Renderable {
public:
    virtual ~Renderable() = default;

    virtual void render( sf::RenderWindow& window ) = 0;
};

END_RENDERABLES_NAMESPACE
