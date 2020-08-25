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


lexer_t* init_lexer(char* contents);                    /* Initializes lexer with source program text which will be used for building tokens */
void lexer_advance(lexer_t* lexer);                     /* Read next character from source language text */
void lexer_stepback(lexer_t* lexer);                    /* Read previous character from source language text */
void lexer_skip_whitespace(lexer_t* lexer);             /* Removes blank spaces from source language text */
token_t* lexer_get_next_token(lexer_t* lexer);          /* Builds upcoming token based on how they begin in source language text*/
token_t* lexer_build_string(lexer_t* lexer);            /* Builds string literal tokens */
token_t* lexer_collect_value(lexer_t* lexer);           /* Builds constant literal tokens */
token_t* lexer_collect_identifier(lexer_t* lexer);      /* Builds indentifier(variable) tokens */
char* lexer_get_current_char(lexer_t* lexer, token_t* token);       /* Get current character as a string */
token_t* lexer_advance_with_token(lexer_t* lexer, token_t* token);  /* Consume created tokens */
void lexer_remove_comment(lexer_t* lexer);              /* Removes comments (begin with #) from source language text */

#endif /* lexer_h */
