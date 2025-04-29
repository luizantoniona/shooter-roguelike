#pragma once

#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

#include <Factory/FactoryGlobals.h>

#include <Renderables/Entities/Character/Character.h>

BEGIN_FACTORY_NAMESPACE

class EnemyFactory {
public:
    static std::unique_ptr<Entities::Character> createEnemy( std::string enemyType );
};

END_FACTORY_NAMESPACE
