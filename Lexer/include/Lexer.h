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
    Token readString();
    Token readIdentifier();
    Token registerToken();
    Token readUntilEnd(); //Is this how we are supposed to read some things???

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

    //Mappings of tokens
    std::vector<std::string> keywords = {"for", "in", "loop", "end", "print", "var", "is", "then", "func", "return", "while", "else",
                                         "true", "false",
                                         "empty","readInt", "readReal","readString",
                                         "bool","int","real","string" }; //Is empty a keyword??
    std::vector<std::string> operators = {"+","-","/","*",">","<","=",".","<=",">=","/=",":=","+=","=>","..","not", "and", "or", "xor"};
    std::map<char,Token::typeEnum> specialCharMappings ={
            {';', Token::TOKEN_SEMI},
            {'(', Token::TOKEN_LPAREN},
            {')', Token::TOKEN_RPAREN},
            {'[', Token::TOKEN_LSQUARE},
            {']', Token::TOKEN_RSQUARE},
            {'{', Token::TOKEN_LCURLY},
            {'}', Token::TOKEN_RCURLY},
            {',', Token::TOKEN_COMMA}
    };
};

