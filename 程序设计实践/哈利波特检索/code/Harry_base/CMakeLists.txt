cmake_minimum_required(VERSION 3.28)
project(Harry)

set(CMAKE_CXX_STANDARD 17)

add_executable(Harry main.cpp)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
