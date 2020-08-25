#include <stdio.h>
#include <stdlib.h>
#include "token.h"

/* initializes token with its type, value and location */
token_t* init_token(type type, char* value, unsigned line, unsigned col){
    token_t* token = (token_t* )calloc(1, sizeof(struct TOKEN_STRUCT));
    token->type = type;
    token->value = value;
    token->line_number = line;
    token->col_number = col;
    return token;
}
