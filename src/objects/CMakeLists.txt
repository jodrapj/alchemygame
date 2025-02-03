cmake_minimum_required(VERSION 3.11)
project(objects)

set(AlchemyObject_LIB AlchemyObject.cpp AlchemyObject.h)
set(Potion_LIB Potion.cpp Potion.h)

add_library(objects STATIC ${AlchemyObject_LIB} ${Potion_LIB})