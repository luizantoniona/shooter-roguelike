set(SOURCES
)

add_subdirectory(Entity)
add_subdirectory(GUI)
add_subdirectory(Shape)

target_sources(${PROJECT_NAME} PUBLIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})