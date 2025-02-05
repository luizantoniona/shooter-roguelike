#include "PlayerFactory.h"

#include <fstream>
#include <iostream>
#include <memory>

namespace {
constexpr const char* PLAYER_STATUS_KEY = "player_status";
constexpr const char* HEALTH_KEY = "health";
constexpr const char* SPEED_KEY = "speed";
constexpr const char* GOLD_KEY = "gold";
constexpr const char* PROJECTILE_STATUS_KEY = "projectile_status";
constexpr const char* PROJECTILE_FIRE_RATE_KEY = "projectile_fire_rate";
constexpr const char* PROJECTILE_SPEED_KEY = "projectile_speed";
constexpr const char* PROJECTILE_SIZE_KEY = "projectile_size";
constexpr const char* PROJECTILE_DAMAGE_KEY = "projectile_damage";
} // namespace

BEGIN_FACTORY_NAMESPACE

std::unique_ptr<Player> PlayerFactory::createPlayer( const Map& map ) {
    std::string filePath = "Asset/Player/Player.json";
    Json::Value playerJson = loadJson( filePath );

    auto player = std::make_unique<Player>( map );
    player->setSides( 3 );
    player->setRadius( 20.f );
    player->setPosition( sf::Vector2f( map.getWidth() / 2.0, map.getHeight() / 2.0 ) );
    player->setColor( sf::Color::Green );

    Json::Value playerStatusJson = playerJson[ PLAYER_STATUS_KEY ];
    player->getPlayerStatus().setHealth( playerStatusJson[ HEALTH_KEY ].asInt() );
    player->getPlayerStatus().setSpeed( playerStatusJson[ SPEED_KEY ].asInt() );
    player->getPlayerStatus().setGold( playerStatusJson[ GOLD_KEY ].asInt() );

    Json::Value playerProjectileStatusJson = playerStatusJson[ PROJECTILE_STATUS_KEY ];
    player->getPlayerProjectileStatus().setProjectileFireRate( playerProjectileStatusJson[ PROJECTILE_FIRE_RATE_KEY ].asFloat() );
    player->getPlayerProjectileStatus().setProjectileSpeed( playerProjectileStatusJson[ PROJECTILE_SPEED_KEY ].asFloat() );
    player->getPlayerProjectileStatus().setProjectileSize( playerProjectileStatusJson[ PROJECTILE_SIZE_KEY ].asFloat() );
    player->getPlayerProjectileStatus().setProjectileDamage( playerProjectileStatusJson[ PROJECTILE_DAMAGE_KEY ].asFloat() );

    player->build();

    return player;
}

Json::Value PlayerFactory::loadJson( const std::string& filePath ) {
    std::ifstream file( filePath );
    if ( !file.is_open() ) {
        std::cerr << "Could not open file: " << filePath << std::endl;
        return Json::Value();
    }

    Json::Value jsonData;
    file >> jsonData;
    return jsonData;
}

END_FACTORY_NAMESPACE