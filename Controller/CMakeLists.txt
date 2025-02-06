set(SOURCES
Collision/CollisionController.cpp
GUI/GUIController.cpp
Input/InputController.cpp
Spawn/SpawnController.cpp
Update/UpdateController.cpp
)

target_sources(${PROJECT_NAME} PUBLIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})