#pragma once

#include <Renderables/Entities/EntitiesGlobals.h>

#include <Renderables/Entities/Entity.h>
#include <Renderables/Entities/Map/Map.h>
#include <Renderables/Entities/Projectile/Projectile.h>

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

END_ENTITIES_NAMESPACE
