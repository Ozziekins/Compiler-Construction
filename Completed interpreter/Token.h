#pragma once
#include <utility>
#include <vector>
#include "string"
#include "map"
#include "ast_nodes.h"
#include "grammar.tab.hh"


class Token {
public:
    yytoken_kind_t type;
    std::string value;
    unsigned int line,position;

public:
    Token(){}; //To create empty objects
    Token(yytoken_kind_t t_type, const std::string& t_value, unsigned int t_line,unsigned int t_position){
        this->type = t_type;
        this->value = t_value;
        this->line = t_line;
        this->position = t_position;
    }

};
