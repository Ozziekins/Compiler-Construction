#ifndef TOKEN_H
#define TOKEN_H
typedef struct TOKEN_STRUCT
{ 
	enum{
		TOKEN_ID,
		TOKEN_EQUALS,
		TOKEN_STRING,
		TOKEN_SEMI,
		TOKEN_LPARENT,
		TOKEN_RPARENT,
		TOKEN_COMMA,
		TOKEN_PLUS,
		TOKEN_MINUS,
		TOKEN_MULT,
		TOKEN_RBRACE,
		TOKEN_LBRACE,
		TOKEN_RCBRACE,
		TOKEN_LCBRACE,
		TOKEN_LESS,
		TOKEN_MORE

	} type;

	char* value;

} token_T;

token_T* init_token(int type, char* value);
#endif