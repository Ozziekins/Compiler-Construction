#include "Lexer.h"
#include "iostream"
#include <algorithm>
extern void yyerror(const char *);

//Advance one character
void Lexer::advance() {

    //To properly display new line and position on it
    if (currentChar == '\n' || currentChar == 10) {
        currentPosOnLine = 0;
        currentLine++;
    }

    //Going to the next character
    if (currentChar != 0 && currentIndex < contents.length()) {

        if (currentChar == '\t')
            currentPosOnLine += 4;
        else
            currentPosOnLine++;

        currentIndex++;
        currentChar = contents[currentIndex];

    } else {
        yyerror("Something went wrong while advancing.\n");
    }
}

Token Lexer::getNextToken() {
    while (currentChar != 0 && currentIndex < contents.length()) {

        //Will do nothing if there are no whitespaces
        while (currentChar == ' ' || currentChar == 10 || currentChar == '\t') {
            advance();
        }

        if (currentChar == 0)
            break;
        else if (currentChar == '"' || isdigit(currentChar))
            return readLiteral();
        else if (isalpha(currentChar))
            return readIdentifier();
        else
            return registerToken();
    }
    Token token_null = Token(YYEOF, "NULL (END)", currentLine, currentPosOnLine);
    tokenList.push_back(token_null);
    return token_null; //This can only happen in the end?
}

Token Lexer::readLiteral() {

    std::string tokenValue;
    Token finalToken;


    //Reading numbers
    if (isdigit(currentChar)) {
        bool dot_encountered = false;

        while (isdigit(currentChar) || //TODO check in fthis line can cause segfaults!!!!!!!!!!!!!!!!!!!!!!!!!
                ( currentChar == '.' && isdigit(contents[currentIndex + 1])
                && isdigit(contents[currentIndex - 1]) && !dot_encountered) ) {

            if (currentChar == '.')
                dot_encountered = true;

            tokenValue += currentChar;
            advance();
        }



        if (dot_encountered){
            Token token = Token(TOKEN_REAL_LITERAL, tokenValue, currentLine, currentPosOnLine - tokenValue.length());
            tokenList.push_back(token);
            finalToken = token;
        }
        else{
            Token token = Token(TOKEN_INT_LITERAL, tokenValue, currentLine, currentPosOnLine - tokenValue.length());
            tokenList.push_back(token);
            finalToken = token; //TODO check -1
        }
    }
    //For actual strings
    else {
        //Skipping the current "
        advance();

        //Is finding the position of the next " really more efficient than reallocating several times?
        unsigned int quotePosition = contents.find('"', currentIndex);
        unsigned int stringLength = quotePosition - currentIndex;

        //Getting value as substring
        tokenValue = contents.substr(currentIndex, stringLength);

        //Saving result now; so that we won't have problems because of moving forward in the source code
        Token token = Token(TOKEN_STRING_LITERAL, tokenValue, currentLine, currentPosOnLine - 1);
        tokenList.push_back(token);
        finalToken = token;

        //Move to the end of the string; after semicolon
        this->currentIndex = quotePosition + 1;
        this->currentChar = contents[currentIndex];
        this->currentPosOnLine += stringLength + 1; //+1 is to account for the first quote
    }


    return finalToken;
}

Token Lexer::readIdentifier() {
    std::string unknownTokenValue;

    while (isalnum(currentChar)) {
        unknownTokenValue += currentChar;
        advance();
    }

    if (specialCharMappings.count(std::string() + unknownTokenValue) != 0) {
        Token token = Token(specialCharMappings[std::string()+unknownTokenValue], unknownTokenValue, currentLine, currentPosOnLine - unknownTokenValue.length());
        tokenList.push_back(token);
        return token;
    }
    else {
        Token token = Token(TOKEN_IDENTIFIER, unknownTokenValue, currentLine, currentPosOnLine - unknownTokenValue.length());
        tokenList.push_back(token);
        return token;
    }
}

//For tokens other than Identifiers and Strings
Token Lexer::registerToken() {

    //Just read the token to properly classify it later; it is UNKNOWN now
    Token finalToken = readUntilTokenDetected();

    if (currentChar != '\0') {
        advance();
    }

    return finalToken;
}

Token Lexer::readUntilTokenDetected() {

    std::string unknownTokenValue;


    unsigned int tokenStart = currentPosOnLine;


    // Collecting PURELY single character tokens
    if (specialCharMappings.count(std::string() + currentChar) != 0 && currentChar != '+' && currentChar != '=' &&
        currentChar != '<' && currentChar != '/' && currentChar != '+') {

        unknownTokenValue = std::string() + currentChar;
        return Token(specialCharMappings[unknownTokenValue], unknownTokenValue, currentLine, tokenStart);
    }
    //Going until its end if it is not a single char
    else
        while (currentChar != ' ' && currentChar != '\n' && currentChar != 0 && currentChar != 32 && !isalnum(currentChar)) {

            unknownTokenValue += currentChar; //Concatenate
            char nextChar = contents[currentIndex + 1];

            //This is to complete reading some tokens without implementing going back
            if (nextChar == ' ' || nextChar == '\n' || nextChar == '\0' || isalnum(nextChar) || nextChar == '"')
                break;
            else
                advance();
        }

    //Special case for single characters with identifiers
    if (specialCharMappings.count(std::string() + unknownTokenValue) != 0) {
        Token token = Token(specialCharMappings[std::string() + unknownTokenValue], unknownTokenValue, currentLine, tokenStart);
        tokenList.push_back(token);
        return token;
    } else {


        std::cout << "\n\n READ A STRANGE THING \n \n";
        Token token = Token(TOKEN_UNKNOWN, unknownTokenValue, currentLine, tokenStart);
        tokenList.push_back(token);
        return token;
    }
}

std::vector<Token> Lexer::getTokenList() {
    return tokenList;
}


