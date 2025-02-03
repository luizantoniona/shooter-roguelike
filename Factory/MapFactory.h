#pragma once

#include <Asset/MapType.h>
#include <Entity/Map/Map.h>
#include <Factory/FactoryGlobals.h>

using Entity::Map;

BEGIN_FACTORY_NAMESPACE

class MapFactory {
public:
    static Map* generateMap( const MapType& mapType );

private:
    static char* mapFileNameByType( const MapType& mapType );
};

END_FACTORY_NAMESPACE
