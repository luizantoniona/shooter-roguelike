#pragma once

#include <Entities/EntitiesGlobals.h>

#include <Entities/Entity.h>
#include <Entities/Map/Map.h>
#include <Entities/Projectile/Projectile.h>

#include "CharacterProjectileStatus.h"
#include "CharacterStatus.h"

BEGIN_ENTITIES_NAMESPACE

class Character : public Entity {
public:
    Character();
    ~Character();

    std::unique_ptr<Character> clone() const;

    CharacterStatus& getStatus();
    CharacterProjectileStatus& getProjectileStatus();

    sf::Clock& getFireClock();

    std::vector<std::unique_ptr<Projectile>>& getProjectiles();

private:
    // Status
    CharacterStatus _status;
    CharacterProjectileStatus _projectileStatus;

    // Projectiles
    sf::Clock _fireClock;
    std::vector<std::unique_ptr<Projectile>> _projectiles;

    // Skills
};

END_ENTITIES_NAMESPACE
