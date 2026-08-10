cmake_minimum_required(VERSION 3.10.0)
project(Media-Tractor VERSION 0.1.0 LANGUAGES C CXX)

add_executable(Media-Tractor src/main.cpp)

include(CTest)
enable_testing()