cmake_minimum_required(VERSION 3.26)
project(modern-cpp CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES
    src/crtp.cpp
    src/raii.cpp
    src/main.cpp)

add_executable(modern_cpp ${SOURCES})
target_include_directories(modern_cpp PRIVATE include/)
