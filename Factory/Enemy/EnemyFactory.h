#pragma once

#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

#include <Factory/FactoryGlobals.h>

#include <Entity/Enemy/Enemy.h>
#include <Entity/Player/Player.h>

using Entities::Enemy;
using Entities::Player;

BEGIN_FACTORY_NAMESPACE

class EnemyFactory {
public:
    static std::unique_ptr<Enemy> createEnemy( Player& player, std::string enemyType );
};

END_FACTORY_NAMESPACE
