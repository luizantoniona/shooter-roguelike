#include "MapFactory.h"

#include <map>
#include <string>

#include <Factory/Map/Wave/WaveFactory.h>
#include <Helper/Json/JsonHelper.h>

using Helper::JsonHelper;

namespace {
constexpr const char* WIDTH_KEY = "width";
constexpr const char* HEIGHT_KEY = "height";
constexpr const char* WORLD_KEY = "world";
constexpr const char* STAGE_KEY = "stage";
constexpr const char* BACKGROUND_KEY = "background";
constexpr const char* WAVES_KEY = "waves";
} // namespace

BEGIN_FACTORY_NAMESPACE

std::unique_ptr<Entities::Map> MapFactory::generateMap( const MapType& mapType ) {
    std::string filePath = "Asset/Maps/" + mapFileNameByType( mapType );
    Json::Value mapJson = JsonHelper::loadJson( filePath );

    auto map = std::make_unique<Entities::Map>();
    map->setWidth( mapJson[ WIDTH_KEY ].asInt() * sf::VideoMode::getDesktopMode().width );
    map->setHeight( mapJson[ HEIGHT_KEY ].asInt() * sf::VideoMode::getDesktopMode().height );
    map->setWorldName( mapJson[ WORLD_KEY ].asString() );
    map->setStageName( mapJson[ STAGE_KEY ].asString() );
    map->setWaves( WaveFactory::generateWaves( mapJson[ WAVES_KEY ] ) );
    map->build();

    return map;
}

std::string MapFactory::mapFileNameByType( const MapType& mapType ) {
    std::map<MapType, std::string> mapTypeToFileName = {
        { MapType::WORLD1_STAGE1, "W1_S01.json" },
        { MapType::WORLD1_STAGE2, "W1_S02.json" } };

    return mapTypeToFileName[ mapType ];
}

END_FACTORY_NAMESPACE
