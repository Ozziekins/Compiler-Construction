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
        TOKEN_EQUALS,
        TOKEN_LITERAL,
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

        TOKEN_UNARIZEDSMTH //TODO PROBABLY KOSTIL
    } type;

private:
    std::string value;
    unsigned int line,position;

    friend std::ostream& operator<<(std::ostream& lhs,typeEnum e); // Overloading the operator for easier printing


public:
    void printInfo();

    Token(){}; //To create empty objects
    Token(typeEnum t_type, const std::string& t_value,unsigned int t_line,unsigned int t_position){
        this->type = t_type;
        this->value = t_value;
        this->line = t_line;
        this->position = t_position;

        printInfo(); //TODO REMOVE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }

};
