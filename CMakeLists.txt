cmake_minimum_required(VERSION 3.27)
project(collatz)

set(CMAKE_CXX_STANDARD 17)

add_executable(collatz src/main.cpp
        src/parser/parser.cpp
        src/parser/parser.hpp
        src/util/stringutil.cpp
        src/util/stringutil.hpp
        src/collatz.cpp
        src/collatz.hpp
        src/parser/command.cpp
        src/parser/command.hpp
        src/parser/subcommand.hpp
)
