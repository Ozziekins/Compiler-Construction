cmake_minimum_required(VERSION 3.17)
project(Lexer2)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Lexer
        include/Lexer.h
        include/Token.h
        CMakeLists.txt
        Lexer.cpp
        main.cpp
        source_code.d
        Token.cpp)
