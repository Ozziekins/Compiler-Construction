#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"

const char* get_category(type ntype){
    switch (ntype) {
        case IDENTIFIER: return "IDENTIFIER";
        case KEYWORD: return "KEYWORD";
        case LITERAL: return "LITERAL";
        case SEMI: return "SEMICOLON";
        case LPAREN: return "LPAREN";
        case RPAREN: return "RPAREN";
        case LSQUARE: return "LSQUARE";
        case RSQUARE: return "RSQUARE";
        case LCURLY: return "LCURLY";
        case RCURLY: return "RCURLY";
        case OPERATOR: return "OPERATOR";
        case COMMA: return "COMMA";
        default: return nullptr;
    }
}

int main(int argc, const char * argv[]) {
    char ch;
    char* content = (char*)calloc(1, sizeof(char));
    content[0] = '\0';
    unsigned position = 0;
    FILE *fp = fopen("test.txt", "r");
    
    if (fp == nullptr) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    
    while((ch = fgetc(fp)) != EOF) {
        content = (char*) realloc(content, (strlen(content) + 1)* sizeof(char));
        content[position++] = ch;
    }
    
    fclose(fp);
    
    lexer_t* lexer = init_lexer(content);
                    
    token_t* token = nullptr;
    
    while((token = lexer_get_next_token(lexer)) != nullptr)
    {
        printf("<%s, %s, %d, %d>\n", get_category(token->type), token->value, token->line_number, token->col_number);
    }
    return 0;
}
