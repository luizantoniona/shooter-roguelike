#include "Character.h"

BEGIN_ENTITIES_NAMESPACE

Character::Character() :
    Entity(),
    _status(),
    _projectileStatus(),
    _fireClock(),
    _projectiles() {
}

Character::~Character() {
}

std::unique_ptr<Character> Character::clone() const {
    return std::make_unique<Character>( *this );
}

CharacterStatus& Character::getStatus() {
    return _status;
}

CharacterProjectileStatus& Character::getProjectileStatus() {
    return _projectileStatus;
}

sf::Clock& Character::getFireClock() {
    return _fireClock;
}

std::vector<Projectile>& Character::getProjectiles() {
    return _projectiles;
}

END_ENTITIES_NAMESPACE
