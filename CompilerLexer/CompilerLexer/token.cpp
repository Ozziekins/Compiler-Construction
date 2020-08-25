//
//  token.cpp
//  CompilerLexer
//
//  Created by MacBookPro on 23.08.2020.
//  Copyright © 2020 MacBookPro. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "token.h"

token_t* init_token(type type, char* value, unsigned line, unsigned col){
    token_t* token = (token_t* )calloc(1, sizeof(struct TOKEN_STRUCT));
    token->type = type;
    token->value = value;
    token->line_number = line;
    token->col_number = col;
    return token;
}
