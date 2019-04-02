cmake_minimum_required(VERSION 3.12)
project(game)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/../SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "${PROJECT_SOURCE_DIR}/../SFML-2.5.1/lib")
set(SFML_DIR "${PROJECT_SOURCE_DIR}/../SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(SFMLApp main.cpp  game/Game.h game/level.cpp game/level.h game/Map.cpp game/Map.h game/image.cpp game/image.cpp game/image.h io/input.cpp io/input.h io/output.cpp io/output.h game/object.cpp game/object.h)
target_link_libraries (SFMLApp sfml-graphics sfml-window sfml-system)