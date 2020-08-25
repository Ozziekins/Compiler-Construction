//
//  lexer.h
//  CompilerLexer
//
//  Created by MacBookPro on 23.08.2020.
//  Copyright © 2020 MacBookPro. All rights reserved.
//

#ifndef lexer_h
#define lexer_h

#include "token.h"

typedef struct LEXER_STRUCT
{
    char c;
    unsigned int i;
    char* contents;
    unsigned int line;
    unsigned int column;
    
} lexer_t;


lexer_t* init_lexer(char* contents);
void lexer_advance(lexer_t* lexer);
void lexer_stepback(lexer_t* lexer);
void lexer_skip_whitespace(lexer_t* lexer);
token_t* lexer_get_next_token(lexer_t* lexer);
token_t* lexer_collect_string(lexer_t* lexer);
token_t* lexer_collect_value(lexer_t* lexer);
token_t* lexer_collect_id(lexer_t* lexer);
char* lexer_get_current_char_as_string(lexer_t* lexer, token_t* token);
token_t* lexer_advance_with_token(lexer_t* lexer, token_t* token);

#endif /* lexer_h */
