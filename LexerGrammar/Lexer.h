#pragma once
#include <string>
#include "Token.h"
#include <iostream>

class Lexer {
    //List of various tokens


    //Hidden variables
    unsigned int currentIndex; //Represents state as one of the enum values
    unsigned int currentLine;
    unsigned int currentPosOnLine;
    std::string contents; //The source code itself
    char currentChar; //Character that we are on
    std::vector<Token> tokenList;

    //Hidden functions
    void advance();
    Token readLiteral();
    Token readIdentifier();
    Token registerToken();
    Token readUntilTokenDetected(); //Is this how we are supposed to read some things???

public:
    explicit Lexer(const std::string& code) {

        this->contents = code;
        this->currentChar = code[0];
        this->currentIndex = 0;

        this->currentLine = 1;
        this->currentPosOnLine = 1;
        std::cout << contents;
        //Deleting all comments in advance
        int found, endl;
        while ( ( found = contents.find("//") ) != std::string::npos){
            endl = contents.find('\n', found);
            contents.replace(found, endl-found,"");
        }
        std::cout << contents;
        
    }
    Token getNextToken();
    std::vector<Token> getTokenList();

private:
    std::map<std::string ,yytoken_kind_t> specialCharMappings = {
            {";", TOKEN_SEMI},
            {"(", TOKEN_LPAREN},
            {")", TOKEN_RPAREN},
            {"[", TOKEN_LSQUARE},
            {"]", TOKEN_RSQUARE},
            {"{", TOKEN_LCURLY},
            {"}", TOKEN_RCURLY},
            {",", TOKEN_COMMA},
            {":=",TOKEN_ASSIGNMENT},
            {"=>",TOKEN_FUNCTOR},
            {"func",TOKEN_FUNC},
            {"end",TOKEN_END},
            {"if",TOKEN_IF},
            {"then",TOKEN_THEN},
            {"else",TOKEN_ELSE},
            {"print",TOKEN_PRINT},
            {"return",TOKEN_RETURN},
            {"loop",TOKEN_LOOP},
            {"var",TOKEN_VAR},
            {"while",TOKEN_WHILE},
            {"for",TOKEN_FOR},
            {"in",TOKEN_IN},
            {"and",TOKEN_AND},
            {"or",TOKEN_OR},
            {"xor",TOKEN_XOR},
            {"not",TOKEN_NOT},
            {"empty",TOKEN_EMPTY},
            {"int",TOKEN_INT},
            {"real",TOKEN_REAL},
            {"bool",TOKEN_BOOL},
            {"string",TOKEN_STRING},
            {"true",TOKEN_TRUE},
            {"false",TOKEN_FALSE},
            {"is",TOKEN_IS},
            {".",TOKEN_DOT},
            {"+",TOKEN_PLUS},
            {"-",TOKEN_MINUS},
            {"*",TOKEN_MULT},
            {"/",TOKEN_DIV},
            {"=",TOKEN_EQUAL},
            {"/=",TOKEN_NEQ},
            {"<",TOKEN_LESS},
            {"<=",TOKEN_LEQ},
            {">",TOKEN_GREAT},
            {"=>",TOKEN_GEQ},
            {"+=",TOKEN_INCREMENT},
            {"readString",TOKEN_READSTRING},
            {"readReal",TOKEN_READINT},
            {"readInt",TOKEN_READREAL}
    };
};

