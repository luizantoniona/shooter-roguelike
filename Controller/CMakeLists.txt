set(SOURCES
Game/GameController.cpp
Game/Collision/CollisionController.cpp
Game/Enemy/EnemyController.cpp
Game/Player/PlayerController.cpp
Game/Player/Projectile/PlayerProjectileController.cpp
Game/Spawn/SpawnController.cpp
GUI/GUIController.cpp
Input/InputController.cpp
Render/RenderController.cpp
)

target_sources(${PROJECT_NAME} PUBLIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})