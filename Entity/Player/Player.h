#pragma once

#include <SFML/Graphics.hpp>

#include <Entity/EntityGlobals.h>

#include <Entity/Map/Map.h>
#include <Entity/Player/PlayerProjectileStatus.h>
#include <Entity/Player/PlayerStatus.h>
#include <Entity/Shape.h>
#include <Entity/Skill/Projectile.h>

BEGIN_ENTITY_NAMESPACE

class Player : public Shape {
public:
    Player( const Map& map );
    ~Player();

    std::vector<Projectile>& getProjectiles();
    PlayerStatus& getPlayerStatus();
    PlayerProjectileStatus& getPlayerProjectileStatus();

    void handleInput( const sf::Event& event );
    void update( const sf::RenderWindow& window, const sf::Time& deltaTime );
    void render( sf::RenderWindow& window );

private:
    const Map& _map;
    PlayerStatus _status;
    PlayerProjectileStatus _projectileStatus;

    sf::Clock _fireClock;
    std::vector<Projectile> _projectiles;

    void updatePosition( const sf::Time& deltaTime );
    void updateProjectiles( const sf::Time& deltaTime );

    void fireProjectile( const sf::Vector2f& target );
};

END_ENTITY_NAMESPACE
