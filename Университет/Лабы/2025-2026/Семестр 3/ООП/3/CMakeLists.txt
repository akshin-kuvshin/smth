cmake_minimum_required(VERSION 3.28.3)
project(oop_lab3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wfloat-equal")
set(SOURCES sources/main.cpp sources/SFile.cpp sources/SKbrd.cpp sources/SQueue.cpp)
include_directories("headers/")

add_executable(${PROJECT_NAME} ${SOURCES})
