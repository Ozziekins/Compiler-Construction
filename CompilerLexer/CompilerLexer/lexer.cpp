//
//  lexer.cpp
//  CompilerLexer
//
//  Created by MacBookPro on 23.08.2020.
//  Copyright © 2020 MacBookPro. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"
#include "token.h"

char dkeys[50][10] = {"for", "in", "loop", "end", "print", "var", "is", "then", "not", "and", "or", "xor", "func", "return", "while", "else", "true", "false", "\0"};


lexer_t* init_lexer(char* contents){
    lexer_t* lexer = (lexer_t*)calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->contents = contents;
    lexer->i = 0;
    lexer->c = contents[lexer->i];
    lexer->line = 1;
    lexer->column = 0;
    return lexer;
}

void lexer_advance(lexer_t* lexer){
    if (lexer->c != '\0' && lexer->i < strlen(lexer->contents))
    {
        lexer->i += 1;
        lexer->c = lexer->contents[lexer->i];
        lexer->column += 1;
    }
}

void lexer_stepback(lexer_t* lexer){
    lexer->i -= 1;
    lexer->c = lexer->contents[lexer->i];
    lexer->column -= 1;
}

void lexer_skip_whitespace(lexer_t* lexer){
    while (lexer->c == ' ' || lexer->c == 10)
    {
        lexer_advance(lexer);
    }
}
char* lexer_get_current_char_as_string(lexer_t* lexer){
    char* str = (char*)calloc(2, sizeof(char));
    str[0] = lexer->c;
    str[1] = '\0';
    
    return str;
}

token_t* lexer_get_next_token(lexer_t* lexer){
    while (lexer->c != '\0' && lexer->i < strlen(lexer->contents))
    {
        if (lexer->c == ' ')
            lexer_skip_whitespace(lexer);
        
        if (lexer->c == '"')
            return lexer_collect_string(lexer);
        
        if (isdigit(lexer->c))
            return lexer_collect_value(lexer);
        
        if (isalpha(lexer->c))
            return lexer_collect_id(lexer);
        
        char* operato = (char*)calloc(1, sizeof(char));
        operato[0] = '\0';
        if (lexer->c == '<' || lexer->c == '>' || lexer->c == '/' || lexer->c == ':' || lexer->c == '.' || lexer->c == '=') {
            operato = (char*) realloc(operato, (strlen(operato) + 1)* sizeof(char));
            operato[0] = lexer->c;
            operato[1] = '\0';
            lexer_advance(lexer);

            if (lexer->c == '=' || lexer->c == '.' || lexer->c == '>') {
                operato = (char*) realloc(operato, (strlen(operato) + 1)* sizeof(char));
                operato[1] = lexer->c;
                operato[2] = '\0';
                return lexer_advance_with_token(lexer, init_token(OPERATOR, operato, lexer->line, lexer->column + 1));
            } else {
                lexer_stepback(lexer);
            }
        }
        
        if (lexer->c == '+' || lexer->c == '-' || lexer->c == '/' || lexer->c == '*' || lexer->c == '>' || lexer->c == '<' || lexer->c == '=')
            return lexer_advance_with_token(lexer, init_token(OPERATOR, lexer_get_current_char_as_string(lexer), lexer->line, lexer->column + 1));
        
        switch(lexer->c)
        {
            case ';': return lexer_advance_with_token(lexer, init_token(SEMI, lexer_get_current_char_as_string(lexer), lexer->line, lexer->column + 1)); break;
            case '(': return lexer_advance_with_token(lexer, init_token(LPAREN, lexer_get_current_char_as_string(lexer), lexer->line, lexer->column + 1)); break;
            case ')': return lexer_advance_with_token(lexer, init_token(RPAREN, lexer_get_current_char_as_string(lexer), lexer->line, lexer->column + 1)); break;
            case '[': return lexer_advance_with_token(lexer, init_token(LSQUARE, lexer_get_current_char_as_string(lexer), lexer->line, lexer->column + 1)); break;
            case ']': return lexer_advance_with_token(lexer, init_token(RSQUARE, lexer_get_current_char_as_string(lexer), lexer->line, lexer->column + 1)); break;
            case '{': return lexer_advance_with_token(lexer, init_token(LCURLY, lexer_get_current_char_as_string(lexer), lexer->line, lexer->column + 1)); break;
            case '}': return lexer_advance_with_token(lexer, init_token(RCURLY, lexer_get_current_char_as_string(lexer), lexer->line, lexer->column + 1)); break;
            case ',': return lexer_advance_with_token(lexer, init_token(COMMA, lexer_get_current_char_as_string(lexer), lexer->line, lexer->column + 1)); break;
            case '.': return lexer_advance_with_token(lexer, init_token(OPERATOR, lexer_get_current_char_as_string(lexer), lexer->line, lexer->column + 1)); break;
            case '\n': lexer_advance(lexer); lexer->line += 1; lexer->column = 0; break;
            case '\t': lexer_advance(lexer); lexer->column += 3; break;
            default: lexer_advance(lexer);
        }
    }
    return nullptr;
}

token_t* lexer_collect_string(lexer_t* lexer){
    lexer_advance(lexer);
    char* value = (char*)calloc(1, sizeof(char));
    value[0] = '\0';
    
    while (lexer->c != '"') {
        char* string = lexer_get_current_char_as_string(lexer);
        value = (char*) realloc(value, (strlen(value) + strlen(string) + 1)* sizeof(char));
        strcat(value, string);
        lexer_advance(lexer);
    }
    
    lexer_advance(lexer);
    return init_token(LITERAL, value, lexer->line, lexer->column);
}

token_t* lexer_collect_value(lexer_t* lexer){
    char* value = (char*)calloc(1, sizeof(char));
    value[0] = '\0';
    
    while (isdigit(lexer->c) || lexer->c == '.') {
        char* string = lexer_get_current_char_as_string(lexer);
        value = (char*) realloc(value, (strlen(value) + strlen(string) + 1)* sizeof(char));
        strcat(value, string);
        lexer_advance(lexer);
    }
    
    return init_token(LITERAL, value, lexer->line, lexer->column);
}

token_t* lexer_collect_id(lexer_t* lexer){
    char* value = (char*)calloc(1, sizeof(char));
    value[0] = '\0';
    
    while (isalnum(lexer->c)) {
        char* string = lexer_get_current_char_as_string(lexer);
        value = (char*) realloc(value, (strlen(value) + strlen(string) + 1)* sizeof(char));
        strcat(value, string);
        lexer_advance(lexer);
    }
    
    unsigned i = 0, flag = 0;
    
    while (strcmp(dkeys[i], "\0") != 0) {
        if (strcmp(dkeys[i], value) == 0) {
            flag = 1;
            break;
        }
        i++;
    }
    if (flag) {
        return init_token(KEYWORD, value, lexer->line, lexer->column);
    } else {
        return init_token(IDENTIFIER, value, lexer->line, lexer->column);
    }
}


token_t* lexer_advance_with_token(lexer_t* lexer, token_t* token){
    lexer_advance(lexer);
    return token;
}
