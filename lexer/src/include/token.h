#ifndef TOKEN_H
#define TOKEN_H

typedef struct TOKEN_STRUCT
{
	enum
	{
		TOKEN_KEYWORD,		// func, is, end, if, then, else, end, print, return, loop, var, while, for, in
		TOKEN_IDENT,		// any identifier
		TOKEN_STRING,		// "some string"
		TOKEN_NUMBER,		// 7 45
		TOKEN_COMMA,		// ,
		TOKEN_SEMI,			// ;
		TOKEN_LPAREN,		// (
		TOKEN_RPAREN,		// )
		TOKEN_ASSIGNMENT,	// :=
		TOKEN_PLUS,			// +
		TOKEN_MINUS,		// -
		TOKEN_MULT,			// *
		TOKEN_DIV,			// /
		TOKEN_RARR,			// ]
		TOKEN_LARR,			// [
		TOKEN_RTUPLE,		// }
		TOKEN_LTUPLE,		// {
		TOKEN_EQUAL,		// =
		TOKEN_NEQ,			// /=
		TOKEN_FUNC,			// =>
		TOKEN_LESS,			// <
		TOKEN_LEQ,			// <=
		TOKEN_GREAT,		// >
		TOKEN_GEQ,			// >=
		TOKEN_RANGE,		// ..
		TOKEN_DOT,			// .
		TOKEN_EOF,			// end of the file
	} type;

	char* value;

	int line_num;

	int tok_num;

} token_T;

token_T* init_token(int type, char* value, int line_num, int tok_num);

#endif