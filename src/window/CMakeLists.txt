cmake_minimum_required(VERSION 3.11)
set(CMAKE_CXX_STANDARD 11)

project(window)

set(WINDOW_LIB window.cpp window.h)
set(Events_LIB events.cpp events.h)

add_library(window STATIC ${WINDOW_LIB} ${Events_LIB})