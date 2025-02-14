cmake_minimum_required(VERSION 3.11)
project(objects)

set(alchemy_d "./Alchemy")
set(AlchemyObject_LIB ${alchemy_d}/AlchemyObject.cpp ${alchemy_d}/AlchemyObject.h)
set(Potion_LIB ${alchemy_d}/Potion.cpp ${alchemy_d}/Potion.h)
set(Entity_LIB entity.cpp entity.h)

add_library(objects STATIC ${AlchemyObject_LIB} ${Potion_LIB} ${Entity_LIB})