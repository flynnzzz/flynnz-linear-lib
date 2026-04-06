cmake_minimum_required(VERSION 3.18)
project(linearlib C)

add_library(linear)
target_sources(linear PRIVATE src/matrix.c)
target_include_directories(linear PRIVATE "${CMAKE_SOURCE_DIR}/include")
