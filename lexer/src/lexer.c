#include "include/lexer.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define INF 99999999

lexer_T* init_lexer(char* test_suite)
{
	lexer_T* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
	lexer->test_suite = test_suite;
	lexer->i = 0;
	lexer->line_count = 1;
	lexer->tok_count = 0;
	lexer->c = test_suite[lexer->i];

	return lexer;
}

void advance_lexer(lexer_T* lexer)
{
	if (lexer->c != '\0' && lexer->i < strlen(lexer->test_suite))
	{
		lexer->i += 1;
		lexer->c = lexer->test_suite[lexer->i];
	}
}

void advance_lexer_until_new_line(lexer_T* lexer)
{
	while (lexer->c != '\n' && lexer->i < strlen(lexer->test_suite))
	{
		lexer->i += 1;
		lexer->c = lexer->test_suite[lexer->i];
	}
}

void skip_blank(lexer_T* lexer)
{
	while (lexer->c == ' ' || lexer->c == 10)	//10 is new line
	{
		advance_lexer(lexer);
	}
}

void skip_tab(lexer_T* lexer)
{
	if (lexer->c == '\t')	//10 is new line
	{
		advance_lexer(lexer);
	}
}


token_T* get_next(lexer_T* lexer)
{
	while (lexer->c != '\0' && lexer->i < strlen(lexer->test_suite))
	{
		lexer->tok_count += 1;

		if (lexer->c == 10)
		{
			advance_lexer(lexer);
			lexer->line_count += 1;
			lexer->tok_count = 1;
		}

		if (lexer->c == ' ' || lexer->c == 10)	//10 is new line
		{
			skip_blank(lexer);
		}

		if (lexer->c == '\t')
		{
			skip_tab(lexer);
		}

		if (lexer->c == '.')
		{
			char* word = calloc(2, sizeof(char));
			word[0] = lexer->c;
			word[1] = '\0';

			advance_lexer(lexer);
			if (lexer->c == '.')
			{
				char* s = get_current_char_as_string(lexer);
				word = realloc(word, (strlen(word) + strlen(s) + 1) * sizeof(char));
				strcat(word, s);
				advance_lexer(lexer);

				return init_token(TOKEN_RANGE, word, lexer->line_count, lexer->tok_count);
			}
			else
				return init_token(TOKEN_DOT, word, lexer->line_count, lexer->tok_count);
		}

		if (isalnum(lexer->c))
		{
			if (isdigit(lexer->c))
			{
				return get_number(lexer);
			}
			return get_keyword_or_identifier(lexer);
		}

		if (lexer->c == '"')
		{
			return get_string(lexer);
		}

		if (lexer->c == ':')
		{
			return get_assignment(lexer);
		}

		if (lexer->c == '/')
		{
			char* word = calloc(2, sizeof(char));
			word[0] = lexer->c;
			word[1] = '\0';

			advance_lexer(lexer);
			if (lexer->c == '/')
			{
				advance_lexer_until_new_line(lexer);
			}
			else if (lexer->c == '=')
			{
				char* s = get_current_char_as_string(lexer);
				word = realloc(word, (strlen(word) + strlen(s) + 1) * sizeof(char));
				strcat(word, s);

				advance_lexer(lexer);

				return init_token(TOKEN_NEQ, word, lexer->line_count, lexer->tok_count);

			}
			else
			{
				return init_token(TOKEN_DIV, word, lexer->line_count, lexer->tok_count);
			}
		}

		if (lexer->c == '=')
		{
			char* word = calloc(2, sizeof(char));
			word[0] = lexer->c;
			word[1] = '\0';

			advance_lexer(lexer);
			if (lexer->c == '>')
			{
				char* s = get_current_char_as_string(lexer);
				word = realloc(word, (strlen(word) + strlen(s) + 1) * sizeof(char));
				strcat(word, s);

				advance_lexer(lexer);

				return init_token(TOKEN_FUNC, word, lexer->line_count, lexer->tok_count);
			}
			else if (lexer->c == ' ')
			{
				return init_token(TOKEN_EQUAL, word, lexer->line_count, lexer->tok_count);
			}
		}

		if (lexer->c == '<')
		{
			char* word = calloc(2, sizeof(char));
			word[0] = lexer->c;
			word[1] = '\0';

			advance_lexer(lexer);
			if (lexer->c == '=')
			{
				char* s = get_current_char_as_string(lexer);
				word = realloc(word, (strlen(word) + strlen(s) + 1) * sizeof(char));
				strcat(word, s);

				advance_lexer(lexer);
			}

			return init_token(TOKEN_LEQ, word, lexer->line_count, lexer->tok_count);
		}

		if (lexer->c == '>')
		{
			char* word = calloc(2, sizeof(char));
			word[0] = lexer->c;
			word[1] = '\0';

			advance_lexer(lexer);
			if (lexer->c == '=')
			{
				char* s = get_current_char_as_string(lexer);
				word = realloc(word, (strlen(word) + strlen(s) + 1) * sizeof(char));
				strcat(word, s);

				advance_lexer(lexer);
			}

			return init_token(TOKEN_GEQ, word, lexer->line_count, lexer->tok_count);
		}

		switch (lexer->c)
		{
			// case '\n':
			// 	return
			// 	advance_lexer_with_token(lexer, init_token(TOKEN_NL, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
			// 	break;
			// case '\t':
			// 	return
			// 	advance_lexer_with_token(lexer, init_token(TOKEN_TAB, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
			// 	break;
			// case '=':
			// 	return
			// 	advance_lexer_with_token(lexer, init_token(TOKEN_KEYWORD, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
			// 	break;
			// case '=':
			// 	return
			// 	advance_lexer_with_token(lexer, init_token(TOKEN_IDENT, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
			// 	break;
			// case '=':
			// 	return
			// 	advance_lexer_with_token(lexer, init_token(TOKEN_STRING, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
			// 	break;
			// case '=':
			// 	return
			// 	advance_lexer_with_token(lexer, init_token(TOKEN_NUMBER, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
			// 	break;
			case ',':
				return
				advance_lexer_with_token(lexer, init_token(TOKEN_COMMA, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
				break;
			case ';':
				return
				advance_lexer_with_token(lexer, init_token(TOKEN_SEMI, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
				break;
			case '(':
				return
				advance_lexer_with_token(lexer, init_token(TOKEN_LPAREN, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
				break;
			case ')':
				return
				advance_lexer_with_token(lexer, init_token(TOKEN_RPAREN, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
				break;
			// case ':=':
			// 	return
			// 	advance_lexer_with_token(lexer, init_token(TOKEN_ASSIGNMENT, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
			// 	break;
			case '+':
				return
				advance_lexer_with_token(lexer, init_token(TOKEN_PLUS, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
				break;
			case '-':
				return
				advance_lexer_with_token(lexer, init_token(TOKEN_MINUS, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
				break;
			case '*':
				return
				advance_lexer_with_token(lexer, init_token(TOKEN_MULT, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
				break;
			// case '/':
			// 	return
			// 	advance_lexer_with_token(lexer, init_token(TOKEN_DIV, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
			// 	break;
			case ']':
				return
				advance_lexer_with_token(lexer, init_token(TOKEN_RARR, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
				break;
			case '[':
				return
				advance_lexer_with_token(lexer, init_token(TOKEN_LARR, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
				break;
			case '}':
				return
				advance_lexer_with_token(lexer, init_token(TOKEN_RTUPLE, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
				break;
			case '{':
				return
				advance_lexer_with_token(lexer, init_token(TOKEN_LTUPLE, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
				break;
			// case '=':
			// 	return
			// 	advance_lexer_with_token(lexer, init_token(TOKEN_EQUAL, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
			// 	break;
			// case '/=':
			// 	return
			// 	advance_lexer_with_token(lexer, init_token(TOKEN_NEQ, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
			// 	break;
			// case '=>':
			// 	return
			// 	advance_lexer_with_token(lexer, init_token(TOKEN_FUNC, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
			// 	break;
			case '<':
				return
				advance_lexer_with_token(lexer, init_token(TOKEN_LESS, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
				break;
			// case '<=':
			// 	return
			// 	advance_lexer_with_token(lexer, init_token(TOKEN_LEQ, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
			// 	break;
			case '>':
				return
				advance_lexer_with_token(lexer, init_token(TOKEN_GREAT, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
				break;
			// case '>=':
			// 	return
			// 	advance_lexer_with_token(lexer, init_token(TOKEN_GEQ, get_current_char_as_string(lexer), lexer->line_count, lexer->tok_count));
			// 	break;
		}
	}

	return (void*)0;
}

token_T* get_string(lexer_T* lexer)
{
	advance_lexer(lexer);

	char* word = calloc(1, sizeof(char));
	word[0] = '\0';

	while (lexer->c != '"')
	{
		char* s = get_current_char_as_string(lexer);
		word = realloc(word, (strlen(word) + strlen(s) + 1) * sizeof(char));
		strcat(word, s);

		advance_lexer(lexer);
	}

	advance_lexer(lexer);

	return init_token(TOKEN_STRING, word, lexer->line_count, lexer->tok_count);
}

token_T* get_number(lexer_T* lexer)
{
	char* word = calloc(1, sizeof(char));
	word[0] = '\0';

	while (isdigit(lexer->c) || lexer->c == '.')
	{
		char* s = get_current_char_as_string(lexer);
		word = realloc(word, (strlen(word) + strlen(s) + 1) * sizeof(char));
		strcat(word, s);

		advance_lexer(lexer);
	}

	return init_token(TOKEN_NUMBER, word, lexer->line_count, lexer->tok_count);
}

token_T* get_assignment(lexer_T* lexer)
{
	char* word = calloc(1, sizeof(char));
	word[0] = '\0';

	char* s = get_current_char_as_string(lexer);
	word = realloc(word, (strlen(word) + strlen(s) + 1) * sizeof(char));
	strcat(word, s);

	advance_lexer(lexer);
	
	char* t = get_current_char_as_string(lexer);
	word = realloc(word, (strlen(word) + strlen(t) + 1) * sizeof(char));
	strcat(word, t);

	advance_lexer(lexer);

	return init_token(TOKEN_ASSIGNMENT, word, lexer->line_count, lexer->tok_count);
}


token_T* get_keyword_or_identifier(lexer_T* lexer)
{
	static const char *keywords_arr[] ={"func", "is", "end", "if", "then", "else", "end", "print", "return", "loop", "var", "while", "for", "in", "and", "or", "xor", "empty", "int", "real", "bool", "string", "true", "false"};
	int len = sizeof(keywords_arr)/sizeof(keywords_arr[0]);

	char* word = calloc(1, sizeof(char));
	word[0] = '\0';

	while (isalnum(lexer->c) || lexer->c == '_')
	{
		char* s = get_current_char_as_string(lexer);
		word = realloc(word, (strlen(word) + strlen(s) + 1) * sizeof(char));
		strcat(word, s);

		advance_lexer(lexer);
	}

	int i;

	for (int i = 0; i < len; ++i)
	{
		if (!strcmp(keywords_arr[i], word))
		{
			return init_token(TOKEN_KEYWORD, word, lexer->line_count, lexer->tok_count);
		}
	}
	return init_token(TOKEN_IDENT, word, lexer->line_count, lexer->tok_count);
}

token_T* advance_lexer_with_token(lexer_T* lexer, token_T* token)
{
	advance_lexer(lexer);

	return token;
}

char* get_current_char_as_string(lexer_T* lexer)
{
	char* str = calloc(2, sizeof(char));
	str[0] = lexer->c;
	str[1] = '\0';

	return str;
}