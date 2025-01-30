#pragma once

#include <SFML/Graphics.hpp>

#include <Entity/EntityGlobals.h>
#include <Entity/Shape.h>

BEGIN_ENTITY_NAMESPACE

class Enemy : public Shape {
public:
    Enemy( int sides, float radius, const sf::Vector2f& position, const sf::Color& color );
    ~Enemy();

    void update( sf::Time& deltaTime );
    void render( sf::RenderWindow& window );
};

END_ENTITY_NAMESPACE