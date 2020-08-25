#include "include/token.h"
#include <stdlib.h>

token_T* init_token(int type, char* value, int line_num, int tok_num)
{
	token_T* token = calloc(1, sizeof(struct TOKEN_STRUCT));
	token->type = type;
	token->value = value;
	token->line_num = line_num;
	token->tok_num = tok_num;

	return token;
}