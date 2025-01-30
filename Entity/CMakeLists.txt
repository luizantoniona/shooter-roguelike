set(SOURCES
Enemy/Enemy.cpp
Map/Map.cpp
Player/Player.cpp
Shape.cpp
Skill/Skill.cpp
)

target_sources(${PROJECT_NAME} PUBLIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})