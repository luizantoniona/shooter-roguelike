#pragma once

#include <Entity/EntityGlobals.h>

#include <Entity/Entity.h>
#include <Entity/Map/Map.h>
#include <Entity/Projectile/Projectile.h>

#include "CharacterProjectileStatus.h"
#include "CharacterStatus.h"

BEGIN_ENTITY_NAMESPACE

class Character : public Entity {
public:
    Character();
    ~Character();

    std::unique_ptr<Character> clone() const;

    CharacterStatus& getStatus();
    CharacterProjectileStatus& getProjectileStatus();

    sf::Clock& getFireClock();

    std::vector<Projectile>& getProjectiles();

private:
    // Status
    CharacterStatus _status;
    CharacterProjectileStatus _projectileStatus;

    // Projectiles
    sf::Clock _fireClock;
    std::vector<Projectile> _projectiles;

    // Skills
};

END_ENTITY_NAMESPACE