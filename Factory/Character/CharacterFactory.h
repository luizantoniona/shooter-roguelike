#pragma once

#include <memory>

#include <Factory/FactoryGlobals.h>

#include <Entities/Character/Character.h>

BEGIN_FACTORY_NAMESPACE

class CharacterFactory {
public:
    static std::unique_ptr<Entities::Character> createCharacter( const bool isPlayer = true, const std::string enemyType = "" );
};

END_FACTORY_NAMESPACE
