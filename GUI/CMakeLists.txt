set(SOURCES
Bar/Bar.cpp
Bar/HealthBar.cpp
Button/Button.cpp
Component.cpp
)

target_sources(${PROJECT_NAME} PUBLIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})