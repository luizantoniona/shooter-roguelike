#pragma once

#include <SFML/Graphics.hpp>

#include <Factory/FactoryGlobals.h>

#include <Entity/Enemy/Enemy.h>

using Entity::Enemy;

BEGIN_FACTORY_NAMESPACE

class EnemyFactory {
public:
    static Enemy* createEnemy( int health, int speed, int sides, float radius, const sf::Color& color, const sf::Vector2f& position );
};

END_FACTORY_NAMESPACE
