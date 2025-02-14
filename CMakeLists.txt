cmake_minimum_required(VERSION 3.11)
set(CMAKE_CXX_STANDARD 11)
set(SDL_CMAKE_DEBUG_POSTFIX "d" 
     CACHE STRING "Name suffix for debug builds") 

project(alchemygame)

set(SOURCE_EXE src/main.cpp)
set(SDL2IMAGE_AVIF OFF)
set(SDL2IMAGE_WEBP OFF)

file(GLOB Alchemy src/alchemy.cpp src/alchemy.h)
file(GLOB NameGen src/namegen.cpp src/namegen.h)
file(GLOB Window src/window.cpp src/window.h)
file(GLOB App src/app.cpp src/app.h)

include_directories(
	"${PROJECT_SOURCE_DIR}/src/"
	"${PROJECT_SOURCE_DIR}/src/objects"
	"${PROJECT_SOURCE_DIR}/src/types"
	"${PROJECT_SOURCE_DIR}/src/graphics"
	"${PROJECT_SOURCE_DIR}/lib/SDL/include"
	"${PROJECT_SOURCE_DIR}/lib/SDL_image/include"
)

add_library(alchemy STATIC ${Alchemy})
add_library(namegen STATIC ${NameGen})
add_library(app STATIC ${App})

add_executable(main ${SOURCE_EXE})

add_subdirectory(src/window)
add_subdirectory(src/objects)
add_subdirectory(src/types)
add_subdirectory(lib/SDL)
add_subdirectory(lib/SDL_image)
add_subdirectory(src/graphics)

if (WIN32)
    add_custom_command(
        TARGET main POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:SDL2::SDL2>" "$<TARGET_FILE_DIR:main>"
        VERBATIM
    )
	add_custom_command(
        TARGET main POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:SDL2_image::SDL2_image>" "$<TARGET_FILE_DIR:main>"
        VERBATIM
    )
endif()

target_link_libraries(main 
    SDL2 SDL2_image 
    objects alchemy namegen
    graphics window
    types)

if (WIN32)
	target_link_libraries(main SDL2main)
endif()