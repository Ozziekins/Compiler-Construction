cmake_minimum_required(VERSION 3.17)
project(Lexer_or_smth)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lexer_or_smth main.cpp Lexer.cpp include/Lexer.h Token.cpp include/Token.h)