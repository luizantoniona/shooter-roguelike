#include "MapFactory.h"

#include <map>

BEGIN_FACTORY_NAMESPACE

MapFactory::generateMap( const MapType& mapType ) {
    // TODO: Ler json e criar mapa
    return new Map();
}

char* MapFactory::mapFileNameByType( const MapType& mapType ) {
    std::map<MapType, std::string> mapTypeToFileName = {
        { MapType::WORLD1_STAGE1, "W1_S01.json" },
        { MapType::WORLD1_STAGE2, "W1_S02.json" } };
}

END_FACTORY_NAMESPACE