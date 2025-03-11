set(SOURCES
Asset/FontManager.cpp
Game/GameManager.cpp
MainMenu/MainMenuManager.cpp
Upgrade/UpgradeManager.cpp
AbstractManager.cpp
MainManager.cpp
)

target_sources(${PROJECT_NAME} PUBLIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})