#pragma once

#include <SFML/Graphics.hpp>

#include <Entity/EntityGlobals.h>
#include <Entity/Shape.h>

BEGIN_ENTITY_NAMESPACE

class Player : public Shape {
public:
    Player( int sides, float radius, const sf::Vector2f& position, const sf::Color& color );
    ~Player();

    void handleInput( const sf::Event& event );
    void update();
    void render( sf::RenderWindow& window );
};

END_ENTITY_NAMESPACE