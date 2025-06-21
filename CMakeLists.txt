cmake_minimum_required(VERSION 3.15.0)
project(shooter-roguelike VERSION 0.1.0 LANGUAGES C CXX)

add_executable(${PROJECT_NAME} main.cpp)

file(GLOB_RECURSE SOURCES
    Controller/*.cpp
    Entities/*.cpp
    Factory/*.cpp
    Helper/*.cpp
    Manager/*.cpp
    Renderables/*.cpp
    Runner/*.cpp
)

file(GLOB_RECURSE HEADERS
    Controller/*.h
    Entities/*.h
    Factory/*.h
    Helper/*.h
    Manager/*.h
    Renderables/*.h
    Runner/*.h
)

target_sources(${PROJECT_NAME} PUBLIC ${SOURCES} ${HEADERS})

set(EXTERNAL_LIBRARIES
jsoncpp
sfml-audio
sfml-graphics
sfml-system
sfml-window
)

target_link_libraries(${PROJECT_NAME} ${EXTERNAL_LIBRARIES})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

file(COPY ${CMAKE_SOURCE_DIR}/Asset DESTINATION ${CMAKE_BINARY_DIR})
