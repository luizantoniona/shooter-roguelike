set(SOURCES
Entity.cpp
Character/Character.cpp
Character/CharacterStatus.cpp
Character/CharacterProjectileStatus.cpp
Map/Map.cpp
Map/Wave/Wave.cpp
Map/Wave/WaveEnemyInfo.cpp
Projectile/Projectile.cpp
Skill/Skill.cpp
)

add_subdirectory(Shapes)

target_sources(${PROJECT_NAME} PUBLIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
