#include "EnemyFactory.h"

#include <Helper/Color/ColorHelper.h>
#include <Helper/Json/JsonHelper.h>

using Helper::ColorHelper;
using Helper::JsonHelper;

namespace {
constexpr const char* HEALTH_KEY = "health";
constexpr const char* SPEED_KEY = "speed";
constexpr const char* SIDES_KEY = "sides";
constexpr const char* SIZE_KEY = "size";
constexpr const char* COLOR_KEY = "color";
} // namespace

BEGIN_FACTORY_NAMESPACE

std::unique_ptr<Enemy> EnemyFactory::createEnemy( Player* player, std::string enemyType ) {
    std::string filePath = "Asset/Enemy/Enemy.json";
    Json::Value enemyJson = JsonHelper::loadJson( filePath )[ enemyType ];

    auto enemy = std::make_unique<Enemy>( player );
    enemy->setHealth( enemyJson[ HEALTH_KEY ].asInt() );
    enemy->setSpeed( enemyJson[ SPEED_KEY ].asFloat() );
    enemy->getShape().setSides( enemyJson[ SIDES_KEY ].asInt() );
    enemy->getShape().setRadius( enemyJson[ SIZE_KEY ].asFloat() );
    enemy->getShape().setColor( ColorHelper::colorFromString( enemyJson[ COLOR_KEY ].asString() ) );
    enemy->getShape().build();

    return enemy;
}

END_FACTORY_NAMESPACE