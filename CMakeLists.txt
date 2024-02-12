cmake_minimum_required(VERSION 3.26)
project(modern-cpp CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

set(HELPER_SRC)

set(IDIOMS_SRC
        src/idioms/crtp.cpp
        src/idioms/raii.cpp
        src/idioms/rtr.cpp
        src/idioms/sfinae.cpp
        src/idioms/cpy_swap.cpp)

set(CPP17_SRC
    src/cpp17/splicing.cpp)

add_executable(modern_cpp ${HELPER_SRC} ${IDIOMS_SRC} ${CPP17_SRC} src/main.cpp)
target_include_directories(modern_cpp PRIVATE include/)
