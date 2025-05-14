set(SOURCES
Character/CharacterFactory.cpp
Map/Wave/WaveFactory.cpp
Map/MapFactory.cpp
Shape/ShapeFactory.cpp
)

target_sources(${PROJECT_NAME} PUBLIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
