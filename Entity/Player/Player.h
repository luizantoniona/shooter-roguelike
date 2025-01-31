#pragma once

#include <SFML/Graphics.hpp>

#include <Entity/EntityGlobals.h>

#include <Entity/Map/Map.h>
#include <Entity/Shape.h>
#include <Entity/Skill/Projectile.h>

BEGIN_ENTITY_NAMESPACE

class Player : public Shape {
public:
    Player( int sides, float radius, const sf::Vector2f& position, const sf::Color& color, const Map& map );
    ~Player();

    void handleInput( const sf::Event& event );
    void update( const sf::RenderWindow& window, sf::Time& deltaTime );
    void render( sf::RenderWindow& window );

    std::vector<Projectile>& getProjectiles();

private:
    const Map& _map;
    float _fireRate;
    sf::Clock _fireClock;
    std::vector<Projectile> _projectiles;

    void updatePosition( sf::Time& deltaTime );
    void updateProjectiles( sf::Time& deltaTime );

    void fireProjectile( const sf::Vector2f& target );
};

END_ENTITY_NAMESPACE