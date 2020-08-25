#ifndef LEXER_H
#define LEXER_H
#include "token.h"

typedef struct LEXER_STRUCT
{
	char c;
	unsigned int i;
	unsigned int line_count;
	unsigned int tok_count;
	char* test_suite;
} lexer_T;

lexer_T* init_lexer(char* test_suite);

void advance_lexer(lexer_T* lexer);

void advance_lexer_until_new_line(lexer_T* lexer);

void skip_blank(lexer_T* lexer);

void skip_tab(lexer_T* lexer);

token_T* get_next(lexer_T* lexer);

token_T* get_string(lexer_T* lexer);

token_T* get_number(lexer_T* lexer);

token_T* get_assignment(lexer_T* lexer);

token_T* get_keyword_or_identifier(lexer_T* lexer);

token_T* advance_lexer_with_token(lexer_T* lexer, token_T* token);

char* get_current_char_as_string(lexer_T* lexer);

#endif