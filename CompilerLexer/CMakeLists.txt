cmake_minimum_required(VERSION 3.17)
project(Lexer_or_smth)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lexer_or_smth grammar.tab.cc Lexer.cpp Token.cpp source_code.d grammar.tab.hh ast_nodes.h)