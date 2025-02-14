cmake_minimum_required(VERSION 3.11)
project(graphics)

set(TEXTURE_LIB texture.cpp texture.h)

add_library(graphics STATIC ${TEXTURE_LIB})