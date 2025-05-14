set(SOURCES
Renderable.cpp
)

add_subdirectory(Components)
add_subdirectory(Shapes)

target_sources(${PROJECT_NAME} PUBLIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
