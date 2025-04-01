#include "Character.h"

BEGIN_ENTITY_NAMESPACE

Character::Character() :
    Entity() {
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

std::vector<Projectile>& Character::getProjectiles() {
    return _projectiles;
}

END_ENTITY_NAMESPACE