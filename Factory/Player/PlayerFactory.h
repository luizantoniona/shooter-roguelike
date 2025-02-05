#pragma once

#include <Factory/FactoryGlobals.h>

#include <Entity/Map/Map.h>
#include <Entity/Player/Player.h>

using Entity::Map;
using Entity::Player;

BEGIN_FACTORY_NAMESPACE

class PlayerFactory {
public:
    static Player* createPlayer( const Map& map );
};

END_FACTORY_NAMESPACE