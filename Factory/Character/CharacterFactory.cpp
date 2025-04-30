#include "CharacterFactory.h"

#include <jsoncpp/json/json.h>

#include <Helper/Json/JsonHelper.h>

using Helper::JsonHelper;

namespace {
constexpr const char* CHARACTER_STATUS_KEY = "status";
constexpr const char* CHARACTER_ATTACK_KEY = "attack";
constexpr const char* CHARACTER_HEALTH_KEY = "health";
constexpr const char* CHARACTER_SPEED_KEY = "speed";
constexpr const char* CHARACTER_GOLD_KEY = "gold";

constexpr const char* PROJECTILE_STATUS_KEY = "projectile_status";
constexpr const char* PROJECTILE_FIRE_RATE_KEY = "projectile_fire_rate";
constexpr const char* PROJECTILE_SPEED_KEY = "projectile_speed";
constexpr const char* PROJECTILE_SIZE_KEY = "projectile_size";
constexpr const char* PROJECTILE_DAMAGE_KEY = "projectile_damage";

constexpr const char* SHAPE_KEY = "shape";

} // namespace

BEGIN_FACTORY_NAMESPACE

std::unique_ptr<Entities::Character> CharacterFactory::createCharacter( const bool isPlayer, const std::string enemyType ) {

    std::string filePath = isPlayer ? "Asset/Player/Player.json" : "Asset/Enemy/Enemy.json";
    Json::Value characterJson = isPlayer ? JsonHelper::loadJson( filePath ) : JsonHelper::loadJson( filePath )[ enemyType ];

    auto character = std::make_unique<Entities::Character>();

    Json::Value characterStatusJson = characterJson[ CHARACTER_STATUS_KEY ];
    auto& characterStatus = character->getStatus();
    characterStatus.setAttack( characterStatusJson[ CHARACTER_ATTACK_KEY ].asInt() );
    characterStatus.setHealth( characterStatusJson[ CHARACTER_HEALTH_KEY ].asInt() );
    characterStatus.setSpeed( characterStatusJson[ CHARACTER_SPEED_KEY ].asInt() );
    characterStatus.setGold( characterStatusJson[ CHARACTER_GOLD_KEY ].asInt() );

    Json::Value projectileStatusJson = characterJson[ PROJECTILE_STATUS_KEY ];
    auto& characterProjectileStatus = character->getProjectileStatus();
    characterProjectileStatus.setProjectileFireRate( projectileStatusJson[ PROJECTILE_FIRE_RATE_KEY ].asFloat() );
    characterProjectileStatus.setProjectileSpeed( projectileStatusJson[ PROJECTILE_SPEED_KEY ].asFloat() );
    characterProjectileStatus.setProjectileSize( projectileStatusJson[ PROJECTILE_SIZE_KEY ].asFloat() );
    characterProjectileStatus.setProjectileDamage( projectileStatusJson[ PROJECTILE_DAMAGE_KEY ].asInt() );

    Json::Value shapeJson = characterJson[ SHAPE_KEY ];
    // TODO: Ao finalizar arquitetura do Shape, setar aqui
    //  auto playerShape = player->getShape();
    //  playerShape->setSides( 3 );
    //  playerShape->setSize( 20.f ); // TODO: Como configurar o tamanho?
    //  playerShape->setPosition( sf::Vector2f( map.getWidth() / 2.0, map.getHeight() / 2.0 ) );
    //  playerShape->setColor( sf::Color::Green );
    //  playerShape->build();

    return character;
}

END_FACTORY_NAMESPACE
