#pragma once

#include <SFML/Graphics.hpp>

#include <Entity/EntityGlobals.h>
#include <Entity/Map/Map.h>
#include <Entity/Shape.h>

BEGIN_ENTITY_NAMESPACE

class Player : public Shape {
public:
    Player( int sides, float radius, const sf::Vector2f& position, const sf::Color& color, const Map& map );
    ~Player();

    void handleInput( const sf::Event& event );
    void update( sf::Time& deltaTime );
    void render( sf::RenderWindow& window );

private:
    const Map& _map;
};

END_ENTITY_NAMESPACE