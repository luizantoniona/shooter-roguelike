set(SOURCES
Enemy/Enemy.cpp
Map/Map.cpp
Map/Background/Background.cpp
Map/Wave/Wave.cpp
Map/Wave/WaveEnemyInfo.cpp
Player/Player.cpp
Player/PlayerProjectileStatus.cpp
Player/PlayerStatus.cpp
Shape.cpp
Skill/Projectile.cpp
Skill/Skill.cpp
)

target_sources(${PROJECT_NAME} PUBLIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})