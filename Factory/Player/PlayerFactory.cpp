#include "PlayerFactory.h"

#include <jsoncpp/json/json.h>

#include <Helper/Json/JsonHelper.h>

using Helper::JsonHelper;

namespace {
constexpr const char* ATTACK_KEY = "attack";
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

std::unique_ptr<Entities::Character> PlayerFactory::createPlayer( const Entities::Map& map ) {
    std::string filePath = "Asset/Player/Player.json";
    Json::Value playerJson = JsonHelper::loadJson( filePath );

    auto player = std::make_unique<Entities::Character>();

    auto& playerShape = player->getShape();
    playerShape.setSides( 3 );
    playerShape.setRadius( 20.f );
    playerShape.setPosition( sf::Vector2f( map.getWidth() / 2.0, map.getHeight() / 2.0 ) );
    playerShape.setColor( sf::Color::Green );
    playerShape.build();

    auto& playerStatus = player->getStatus();
    playerStatus.setAttack( playerJson[ ATTACK_KEY ].asInt() );
    playerStatus.setHealth( playerJson[ HEALTH_KEY ].asInt() );
    playerStatus.setSpeed( playerJson[ SPEED_KEY ].asInt() );
    playerStatus.setGold( playerJson[ GOLD_KEY ].asInt() );

    Json::Value playerProjectileStatusJson = playerJson[ PROJECTILE_STATUS_KEY ];
    auto& playerProjectileStatus = player->getProjectileStatus();
    playerProjectileStatus.setProjectileFireRate( playerProjectileStatusJson[ PROJECTILE_FIRE_RATE_KEY ].asFloat() );
    playerProjectileStatus.setProjectileSpeed( playerProjectileStatusJson[ PROJECTILE_SPEED_KEY ].asFloat() );
    playerProjectileStatus.setProjectileSize( playerProjectileStatusJson[ PROJECTILE_SIZE_KEY ].asFloat() );
    playerProjectileStatus.setProjectileDamage( playerProjectileStatusJson[ PROJECTILE_DAMAGE_KEY ].asInt() );

    return player;
}

END_FACTORY_NAMESPACE