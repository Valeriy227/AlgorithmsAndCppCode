cmake_minimum_required(VERSION 3.10)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

add_executable(untitled main.cpp)