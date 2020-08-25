//
//  token.h
//  CompilerLexer
//
//  Created by MacBookPro on 23.08.2020.
//  Copyright © 2020 MacBookPro. All rights reserved.
//

#ifndef token_h
#define token_h

typedef enum {
    IDENTIFIER,
    KEYWORD,
    LITERAL,
    SEMI,
    LPAREN,
    RPAREN,
    LSQUARE,
    RSQUARE,
    LCURLY,
    RCURLY,
    OPERATOR,
    COMMA
} type;

typedef struct TOKEN_STRUCT
{
    type type;
    char* value;
    unsigned int line_number;
    unsigned int col_number;
} token_t;

token_t* init_token(type type, char* value, unsigned line, unsigned col);

#endif /* token_h */
