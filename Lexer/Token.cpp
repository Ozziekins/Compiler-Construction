#include "include/Token.h"
#include <iostream>


std::ostream &operator<<(std::ostream &lhs,const Token::typeEnum e) {
    switch(e) {
        case Token::TOKEN_IDENTIFIER: lhs << "TOKEN_IDENTIFIER"; break;
        case Token::TOKEN_OPERATOR: lhs << "TOKEN_OPERATOR"; break;
        case Token::TOKEN_EQUALS: lhs << "TOKEN_EQUALS"; break;
        case Token::TOKEN_LITERAL: lhs << "TOKEN_LITERAL"; break;

        case Token::TOKEN_LPAREN: lhs << "TOKEN_LPAREN"; break;
        case Token::TOKEN_RPAREN: lhs << "TOKEN_RPAREN"; break;

        case Token::TOKEN_LSQUARE: lhs << "TOKEN_LSQUARE"; break;
        case Token::TOKEN_RSQUARE: lhs << "TOKEN_RSQUARE"; break;

        case Token::TOKEN_LCURLY: lhs << "TOKEN_LCURLY"; break;
        case Token::TOKEN_RCURLY: lhs << "TOKEN_RCURLY"; break;

        case Token::TOKEN_SEMI: lhs << "TOKEN_SEMI"; break;
        case Token::TOKEN_COMMA: lhs << "TOKEN_COMMA"; break;
        case Token::TOKEN_EOF: lhs << "TOKEN_EOF"; break;

        case Token::TOKEN_UNKNOWN: lhs << "TOKEN_UNKNOWN"; break;
        case Token::TOKEN_KEYWORD: lhs << "TOKEN_KEYWORD"; break;

        case Token::TOKEN_UNARIZEDSMTH: lhs << "TOKEN_UNARIZEDSMTH"; break;  //TODO PROBABLY KOSTIL

    }
    return lhs;
}

void Token::printInfo() {
    std::cout << this->type << ": ["<< this->value << "] on " << this->line << ':' << this->position<< std::endl;
}

