#pragma once
#include <string>
#include "Token.h"

class Lexer {
    //List of various tokens


    //Hidden variables
    unsigned int currentIndex; //Represents state as one of the enum values
    unsigned int currentLine;
    unsigned int currentPosOnLine;
    std::string contents; //The source code itself
    char currentChar; //Character that we are on


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

        //Deleting all comments in advance
        int found, endl;
        while ( ( found = contents.find("//") ) != std::string::npos){
            endl = contents.find('\n', found);
            contents.replace(found, endl-found,"");
        }

    }
    Token getNextToken();

private:

//TODO ADD THOSE
//    std::vector<std::string> keywords = { "readInt", "readReal","readString"};
//    std::vector<std::string> operators = {"+="};

    std::map<std::string ,Token::typeEnum> specialCharMappings ={
            {";", Token::TOKEN_SEMI},
            {"(", Token::TOKEN_LPAREN},
            {")", Token::TOKEN_RPAREN},
            {"[", Token::TOKEN_LSQUARE},
            {"]", Token::TOKEN_RSQUARE},
            {"{", Token::TOKEN_LCURLY},
            {"}", Token::TOKEN_RCURLY},
            {",", Token::TOKEN_COMMA},
            {":=",Token::TOKEN_ASSIGNMENT},
            {"=>",Token::TOKEN_FUNCTOR},
            {"func",Token::TOKEN_FUNC},
            {"end",Token::TOKEN_END},
            {"if",Token::TOKEN_IF},
            {"then",Token::TOKEN_THEN},
            {"else",Token::TOKEN_ELSE},
            {"print",Token::TOKEN_PRINT},
            {"return",Token::TOKEN_RETURN},
            {"loop",Token::TOKEN_LOOP},
            {"var",Token::TOKEN_VAR},
            {"while",Token::TOKEN_WHILE},
            {"for",Token::TOKEN_FOR},
            {"in",Token::TOKEN_IN},
            {"and",Token::TOKEN_AND},
            {"or",Token::TOKEN_OR},
            {"xor",Token::TOKEN_XOR},
            {"not",Token::TOKEN_NOT},
            {"empty",Token::TOKEN_EMPTY},
            {"int",Token::TOKEN_INT},
            {"real",Token::TOKEN_REAL},
            {"bool",Token::TOKEN_BOOL},
            {"string",Token::TOKEN_STRING},
            {"true",Token::TOKEN_TRUE},
            {"false",Token::TOKEN_FALSE},
            {"is",Token::TOKEN_IS},
            {".",Token::TOKEN_DOT},
            {"+",Token::TOKEN_PLUS},
            {"-",Token::TOKEN_MINUS},
            {"*",Token::TOKEN_MULT},
            {"/",Token::TOKEN_DIV},
            {"=",Token::TOKEN_EQUAL},
            {"/=",Token::TOKEN_NEQ},
            {"<",Token::TOKEN_LESS},
            {"<=",Token::TOKEN_LEQ},
            {">",Token::TOKEN_GREAT},
            {"=>",Token::TOKEN_GEQ},
    };
};

