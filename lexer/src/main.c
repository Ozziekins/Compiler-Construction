#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/lexer.h"

#define INF 99999999

int main(int argc, char const *argv[])
{
	char ch;
    char* program = (char*)calloc(1, sizeof(char));
    program[0] = '\0';
    unsigned index = 0;
    FILE *fp = fopen("src/suite.txt", "r");
    
    if (fp == NULL) {
        printf("Error while opening the file.\n");
        exit(-1);
    }
    
    while((ch = fgetc(fp)) != EOF) {
        program = (char*) realloc(program, (strlen(program) + 1)* sizeof(char));
        program[index++] = ch;
    }
    
    fclose(fp);

	lexer_T* lexer = init_lexer(program);

	token_T* token = (void*)0;

	static const char *type_arr[] ={"TOKEN_KEYWORD",		// func, is, end, if, then, else, end, print, return, loop, var, while, for, in
		"TOKEN_IDENT",										// any identifier
		"TOKEN_STRING",										// "some string"
		"TOKEN_NUMBER",										// 7 45
		"TOKEN_COMMA",										// ,
		"TOKEN_SEMI",										// ;
		"TOKEN_LPAREN",										// (
		"TOKEN_RPAREN",										// )
		"TOKEN_ASSIGNMENT",									// :=
		"TOKEN_PLUS",										// +
		"TOKEN_MINUS",										// -
		"TOKEN_MULT",										// *
		"TOKEN_DIV",										// /
		"TOKEN_RARR",										// ]
		"TOKEN_LARR",										// [
		"TOKEN_RTUPLE",										// }
		"TOKEN_LTUPLE",										// {
		"TOKEN_EQUAL",										// =
		"TOKEN_NEQ",										// /=
		"TOKEN_FUNC",										// =>
		"TOKEN_LESS",										// <
		"TOKEN_LEQ",										// <=
		"TOKEN_GREAT",										// >
		"TOKEN_GEQ",										// >=
		"TOKEN_RANGE",										// ..
		"TOKEN_DOT",										// .
		"TOKEN_EOF"};

	while ((token = get_next(lexer)) != (void*)0)
	{
		printf("%s, %s, %d, %d\n", type_arr[token->type], token->value, token->line_num, token->tok_num);
	}

	token = init_token(TOKEN_EOF, "EOF", INF, INF);
	printf("%s, %s, %d, %d\n", type_arr[token->type], token->value, token->line_num, token->tok_num);
	return 0;
}