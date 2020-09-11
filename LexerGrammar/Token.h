#pragma once
#include <utility>
#include <vector>
#include "string"
#include "map"

class Token {
public:
    enum typeEnum: unsigned int{
        TOKEN_IDENTIFIER,
        TOKEN_OPERATOR,
        TOKEN_KEYWORD,
        TOKEN_STRING_LITERAL,
        TOKEN_UNKNOWN,
        TOKEN_SEMI,
        TOKEN_LPAREN,
        TOKEN_RPAREN,
        TOKEN_LSQUARE,
        TOKEN_RSQUARE,
        TOKEN_LCURLY,
        TOKEN_RCURLY,
        TOKEN_COMMA,
        TOKEN_EOF,
        TOKEN_ASSIGNMENT,
        TOKEN_FUNCTOR,
        TOKEN_INT_LITERAL,
        TOKEN_REAL_LITERAL,
        TOKEN_FUNC,
        TOKEN_END,
        TOKEN_IF,
        TOKEN_THEN,
        TOKEN_ELSE,
        TOKEN_PRINT,
        TOKEN_RETURN,
        TOKEN_LOOP,
        TOKEN_VAR,
        TOKEN_WHILE,
        TOKEN_FOR,
        TOKEN_IN,
        TOKEN_AND,
        TOKEN_OR,
        TOKEN_XOR,
        TOKEN_NOT,
        TOKEN_EMPTY,
        TOKEN_INT,
        TOKEN_REAL,
        TOKEN_BOOL,
        TOKEN_STRING,
        TOKEN_TRUE,
        TOKEN_FALSE,
        TOKEN_IS,
        TOKEN_DOT,
        TOKEN_PLUS,
        TOKEN_MINUS,
        TOKEN_MULT,
        TOKEN_DIV,
        TOKEN_EQUAL,
        TOKEN_NEQ,
        TOKEN_LESS,
        TOKEN_LEQ,
        TOKEN_GREAT,
        TOKEN_GEQ,
        TOKEN_INCREMENT,
        TOKEN_READINT,
        TOKEN_READREAL,
        TOKEN_READSTRING

    } type;
    std::string value;
    unsigned int line,position;

public:

    Token(){}; //To create empty objects
    Token(typeEnum t_type, const std::string& t_value, unsigned int t_line,unsigned int t_position){
        this->type = t_type;
        this->value = t_value;
        this->line = t_line;
        this->position = t_position;
    }

};
