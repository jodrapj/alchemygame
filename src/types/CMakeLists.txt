cmake_minimum_required(VERSION 3.11)
project(types)

set(MATRIX matrix.cpp matrix.h)

add_library(types STATIC ${MATRIX})