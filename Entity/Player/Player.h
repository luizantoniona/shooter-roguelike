#pragma once

#include <SFML/Graphics.hpp>

#include <Entity/EntityGlobals.h>

#include <Entity/BaseEntity.h>
#include <Entity/Map/Map.h>
#include <Entity/Player/PlayerProjectileStatus.h>
#include <Entity/Player/PlayerStatus.h>
#include <Entity/Projectile/Projectile.h>

BEGIN_ENTITY_NAMESPACE

class Player : public BaseEntity {
public:
    Player( const Map& map );
    ~Player();

    PlayerStatus& getPlayerStatus();
    PlayerProjectileStatus& getPlayerProjectileStatus();

    std::vector<Projectile>& getProjectiles();

    void handleInput( const sf::Event& event );

    void update( const sf::RenderWindow& window, const sf::Time& deltaTime ) override;
    void render( sf::RenderWindow& window ) override;

private:
    const Map& _map;
    PlayerStatus _status;
    PlayerProjectileStatus _projectileStatus;

    sf::Clock _fireClock;
    std::vector<Projectile> _projectiles;

    void updatePosition( const sf::RenderWindow& window, const sf::Time& deltaTime );
    void updateProjectiles( const sf::RenderWindow& window, const sf::Time& deltaTime );

    void fireProjectile( const sf::Vector2f& target );
};

END_ENTITY_NAMESPACE
