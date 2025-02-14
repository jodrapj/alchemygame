cmake_minimum_required(VERSION 3.11)
project(alchemyobjects)

set(AlchemyObject_LIB AlchemyObject.cpp AlchemyObject.h)
set(Potion_LIB Potion.cpp Potion.h)

add_library(alchemyobjects STATIC ${AlchemyObject_LIB} ${Potion_LIB})