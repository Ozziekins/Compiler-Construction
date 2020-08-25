#ifndef token_h
#define token_h

/* lists of possible tokens */
typedef enum {
    IDENTIFIER,             // variable names e.g foo
    KEYWORD,                // source language specific identifiers e.g for
    LITERAL,                // constants or strings e.g "good", 40
    SEMI,                   // end of statement character (;)
    LPAREN,                 // (
    RPAREN,                 // )
    LSQUARE,                // [
    RSQUARE,                // ]
    LCURLY,                 // {
    RCURLY,                 // }
    OPERATOR,               // all operators present in source language description e.g >
    COMMA                   // ,
} type;

/* Token structure consisting of the token's type, value and location */
typedef struct TOKEN_STRUCT
{
    type type;
    char* value;
    unsigned int line_number;
    unsigned int col_number;
} token_t;

/* initializes token with its type, value and location */
token_t* init_token(type type, char* value, unsigned line, unsigned col);

#endif /* token_h */
