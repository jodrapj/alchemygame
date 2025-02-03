cmake_minimum_required(VERSION 3.11)
project(alchemygame)

set(test false)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_EXE src/main.cpp)

file(GLOB Alchemy src/alchemy.cpp src/alchemy.h)
file(GLOB NameGen src/namegen.cpp src/namegen.h)

include_directories(src src/objects src/algorithms)

add_library(alchemy STATIC ${Alchemy})
add_library(namegen STATIC ${NameGen})

add_executable(main ${SOURCE_EXE})

add_subdirectory(src/objects)
add_subdirectory(src/types)

target_link_libraries(main objects alchemy namegen types)