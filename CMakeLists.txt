cmake_minimum_required(VERSION 3.15.0)
project(roguelike VERSION 0.1.0 LANGUAGES C CXX)

include_directories( ${includes} )

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

set(EXTERNAL_LIBRARIES
jsoncpp
sfml-audio
sfml-graphics
sfml-system
sfml-window
)

target_link_libraries(${PROJECT_NAME} ${EXTERNAL_LIBRARIES})

add_subdirectory(Controller)
add_subdirectory(Entity)
add_subdirectory(Factory)
add_subdirectory(GUI)
add_subdirectory(Helper)
add_subdirectory(Manager)
add_subdirectory(Runner)
add_subdirectory(Shape)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

file(COPY ${CMAKE_SOURCE_DIR}/Asset DESTINATION ${CMAKE_BINARY_DIR})
