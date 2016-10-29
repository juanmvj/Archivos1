cmake_minimum_required(VERSION 2.8.9)
project(Archivos)

include_directories(include)

set(SOURCES src/Archivos.cpp src/main.cpp)

add_executable(Archivos ${SOURCES})
