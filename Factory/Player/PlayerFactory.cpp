#include "PlayerFactory.h"

#include <jsoncpp/json/json.h>

#include <Helper/Json/JsonHelper.h>

using Helper::JsonHelper;

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

static std::unique_ptr<Entities::Character> createPlayer( const Entities::Map& map ) {
    std::string filePath = "Asset/Player/Player.json";
    Json::Value playerJson = JsonHelper::loadJson( filePath );

    auto player = std::make_unique<Entities::Character>();
    player->getShape().setSides( 3 );
    player->getShape().setRadius( 20.f );
    player->getShape().setPosition( sf::Vector2f( map.getWidth() / 2.0, map.getHeight() / 2.0 ) );
    player->getShape().setColor( sf::Color::Green );
    player->getShape().build();

    Json::Value playerStatusJson = playerJson[ PLAYER_STATUS_KEY ];
    player->getStatus().setHealth( playerStatusJson[ HEALTH_KEY ].asInt() );
    player->getStatus().setSpeed( playerStatusJson[ SPEED_KEY ].asInt() );
    player->getStatus().setGold( playerStatusJson[ GOLD_KEY ].asInt() );

    Json::Value playerProjectileStatusJson = playerStatusJson[ PROJECTILE_STATUS_KEY ];
    player->getProjectileStatus().setProjectileFireRate( playerProjectileStatusJson[ PROJECTILE_FIRE_RATE_KEY ].asFloat() );
    player->getProjectileStatus().setProjectileSpeed( playerProjectileStatusJson[ PROJECTILE_SPEED_KEY ].asFloat() );
    player->getProjectileStatus().setProjectileSize( playerProjectileStatusJson[ PROJECTILE_SIZE_KEY ].asFloat() );
    player->getProjectileStatus().setProjectileDamage( playerProjectileStatusJson[ PROJECTILE_DAMAGE_KEY ].asInt() );

    return player;
}

END_FACTORY_NAMESPACE