#pragma once

#include <jsoncpp/json/json.h>

#include <Factory/FactoryGlobals.h>

#include <Entity/Map/Map.h>
#include <Entity/Player/Player.h>

using Entity::Map;
using Entity::Player;

BEGIN_FACTORY_NAMESPACE

class PlayerFactory {
public:
    static std::unique_ptr<Player> createPlayer( const Map& map );

private:
    static Json::Value loadJson( const std::string& filePath );
};

END_FACTORY_NAMESPACE