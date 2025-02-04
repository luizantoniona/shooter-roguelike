#pragma once

#include <jsoncpp/json/json.h>

#include <Factory/FactoryGlobals.h>

#include <Entity/Map/Map.h>
#include <Entity/Map/MapType.h>

using Entity::Map;

BEGIN_FACTORY_NAMESPACE

class MapFactory {
public:
    static std::shared_ptr<Map> generateMap( const MapType& mapType );

private:
    static Json::Value loadJson( const std::string& filePath );
    static std::string mapFileNameByType( const MapType& mapType );
};

END_FACTORY_NAMESPACE
