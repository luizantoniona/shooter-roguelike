set(SOURCES
Enemy/EnemyFactory.cpp
Map/Background/BackgroundFactory.cpp
Map/Wave/WaveFactory.cpp
Map/MapFactory.cpp
Player/PlayerFactory.cpp
)

target_sources(${PROJECT_NAME} PUBLIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})