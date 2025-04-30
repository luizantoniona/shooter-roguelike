#pragma once

#include <memory>

#include <Factory/FactoryGlobals.h>

#include <Entities/Map/Map.h>
#include <Entities/Map/MapType.h>

BEGIN_FACTORY_NAMESPACE

class MapFactory {
public:
    static std::unique_ptr<Entities::Map> generateMap( const MapType& mapType );

private:
    static std::string mapFileNameByType( const MapType& mapType );
};

END_FACTORY_NAMESPACE
