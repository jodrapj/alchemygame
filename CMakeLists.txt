cmake_minimum_required(VERSION 3.11)
set(CMAKE_CXX_STANDARD 11)

project(alchemygame)

set(SOURCE_EXE src/main.cpp)

file(GLOB Alchemy src/alchemy.cpp src/alchemy.h)
file(GLOB NameGen src/namegen.cpp src/namegen.h)
file(GLOB Window src/window.cpp src/window.h)

include_directories(
	"${PROJECT_SOURCE_DIR}/src/"
	"${PROJECT_SOURCE_DIR}/src/objects"
	"${PROJECT_SOURCE_DIR}/src/types"
	"${PROJECT_SOURCE_DIR}/lib/SDL/include"
)

add_library(alchemy STATIC ${Alchemy})
add_library(namegen STATIC ${NameGen})
add_library(window STATIC ${Window})

add_executable(main ${SOURCE_EXE})

add_subdirectory(src/objects)
add_subdirectory(src/types)
add_subdirectory(lib/SDL)

if (WIN32)
	target_link_libraries(main SDL2main)
endif()

target_link_libraries(main SDL2-static objects alchemy namegen window types)