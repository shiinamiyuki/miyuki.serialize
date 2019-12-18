project(miyuki.serialize)

cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD  17)

include_directories(include/)
add_executable(test test/main.cpp)