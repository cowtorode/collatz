cmake_minimum_required(VERSION 3.27)
project(collatz)

set(CMAKE_CXX_STANDARD 17)

add_executable(collatz src/main.cpp
        src/parser.cpp
        src/parser.hpp
        src/util/stringutil.cpp
        src/util/stringutil.hpp
        src/collatz.cpp
        src/collatz.hpp)
