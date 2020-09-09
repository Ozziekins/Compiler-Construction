#include "include/Token.h"
#include <iostream>


std::ostream &operator<<(std::ostream &lhs,const Token::typeEnum e) {
    switch(e) {
        case Token::TOKEN_IDENTIFIER: lhs << "TOKEN_IDENTIFIER"; break;
        case Token::TOKEN_OPERATOR: lhs << "TOKEN_OPERATOR"; break;
        case Token::TOKEN_KEYWORD: lhs << "TOKEN_KEYWORD"; break;
        case Token::TOKEN_STRING_LITERAL: lhs << "TOKEN_STRING_LITERAL"; break;
        case Token::TOKEN_UNKNOWN: lhs << "TOKEN_UNKNOWN"; break;
        case Token::TOKEN_SEMI: lhs << "TOKEN_SEMI"; break;
        case Token::TOKEN_LPAREN: lhs << "TOKEN_LPAREN"; break;
        case Token::TOKEN_RPAREN: lhs << "TOKEN_RPAREN"; break;
        case Token::TOKEN_LSQUARE: lhs << "TOKEN_LSQUARE"; break;
        case Token::TOKEN_RSQUARE: lhs << "TOKEN_RSQUARE"; break;
        case Token::TOKEN_LCURLY: lhs << "TOKEN_LCURLY"; break;
        case Token::TOKEN_RCURLY: lhs << "TOKEN_RCURLY"; break;
        case Token::TOKEN_COMMA: lhs << "TOKEN_COMMA"; break;
        case Token::TOKEN_EOF: lhs << "TOKEN_EOF"; break;
        case Token::TOKEN_ASSIGNMENT: lhs << "TOKEN_ASSIGNMENT"; break;
        case Token::TOKEN_FUNCTOR: lhs << "TOKEN_FUNCTOR"; break;
        case Token::TOKEN_INT_LITERAL: lhs << "TOKEN_INT_LITERAL"; break;
        case Token::TOKEN_REAL_LITERAL: lhs << "TOKEN_REAL_LITERAL"; break;
        case Token::TOKEN_FUNC: lhs << "TOKEN_FUNC"; break;
        case Token::TOKEN_END: lhs << "TOKEN_END"; break;
        case Token::TOKEN_IF: lhs << "TOKEN_IF"; break;
        case Token::TOKEN_THEN: lhs << "TOKEN_THEN"; break;
        case Token::TOKEN_ELSE: lhs << "TOKEN_ELSE"; break;
        case Token::TOKEN_PRINT: lhs << "TOKEN_PRINT"; break;
        case Token::TOKEN_RETURN: lhs << "TOKEN_RETURN"; break;
        case Token::TOKEN_LOOP: lhs << "TOKEN_LOOP"; break;
        case Token::TOKEN_VAR: lhs << "TOKEN_VAR"; break;
        case Token::TOKEN_WHILE: lhs << "TOKEN_WHILE"; break;
        case Token::TOKEN_FOR: lhs << "TOKEN_FOR"; break;
        case Token::TOKEN_IN: lhs << "TOKEN_IN"; break;
        case Token::TOKEN_AND: lhs << "TOKEN_AND"; break;
        case Token::TOKEN_OR: lhs << "TOKEN_OR"; break;
        case Token::TOKEN_XOR: lhs << "TOKEN_XOR"; break;
        case Token::TOKEN_NOT: lhs << "TOKEN_NOT"; break;
        case Token::TOKEN_EMPTY: lhs << "TOKEN_EMPTY"; break;
        case Token::TOKEN_INT: lhs << "TOKEN_INT"; break;
        case Token::TOKEN_REAL: lhs << "TOKEN_REAL"; break;
        case Token::TOKEN_BOOL: lhs << "TOKEN_BOOL"; break;
        case Token::TOKEN_STRING: lhs << "TOKEN_STRING"; break;
        case Token::TOKEN_TRUE: lhs << "TOKEN_TRUE"; break;
        case Token::TOKEN_FALSE: lhs << "TOKEN_FALSE"; break;
        case Token::TOKEN_IS: lhs << "TOKEN_IS"; break;
        case Token::TOKEN_DOT: lhs << "TOKEN_DOT"; break;
        case Token::TOKEN_PLUS: lhs << "TOKEN_PLUS"; break;
        case Token::TOKEN_MINUS: lhs << "TOKEN_MINUS"; break;
        case Token::TOKEN_MULT: lhs << "TOKEN_MULT"; break;
        case Token::TOKEN_DIV: lhs << "TOKEN_DIV"; break;
        case Token::TOKEN_EQUAL: lhs << "TOKEN_EQUAL"; break;
        case Token::TOKEN_NEQ: lhs << "TOKEN_NEQ"; break;
        case Token::TOKEN_LESS: lhs << "TOKEN_LESS"; break;
        case Token::TOKEN_LEQ: lhs << "TOKEN_LEQ"; break;
        case Token::TOKEN_GREAT: lhs << "TOKEN_GREAT"; break;
        case Token::TOKEN_GEQ: lhs << "TOKEN_GEQ"; break;
        case Token::TOKEN_INCREMENT: lhs << "TOKEN_INCREMENT"; break;
        case Token::TOKEN_READINT: lhs << "TOKEN_READINT"; break;
        case Token::TOKEN_READREAL: lhs << "TOKEN_READREAL"; break;
        case Token::TOKEN_READSTRING: lhs << "TOKEN_READSTRING"; break;
    }
    return lhs;
}

void Token::printInfo() {
    std::cout << this->type << ": ["<< this->value << "] on " << this->line << ':' << this->position<< std::endl;
}

