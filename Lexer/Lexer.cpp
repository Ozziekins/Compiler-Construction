#include "include/Lexer.h"
#include "iostream"
#include <algorithm>

//Advance one character
void Lexer::advance() {

    //To properly display new line and position on it
    if (currentChar == '\n') {
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
        std::cout << "Something is wrong when advancing!??\n";
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

    return Token(Token::TOKEN_EOF, "NULL (END)", currentLine, currentPosOnLine); //This can only happen in the end?
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

        finalToken = Token(Token::TOKEN_NUMBER, tokenValue, currentLine, currentPosOnLine - 1); //TODO check -1
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
        finalToken = Token(Token::TOKEN_STRING_LITERAL, tokenValue, currentLine, currentPosOnLine - 1);

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
        return Token(specialCharMappings[std::string()+unknownTokenValue], unknownTokenValue, currentLine, currentPosOnLine - unknownTokenValue.length());
    }
    else
        return Token(Token::TOKEN_IDENTIFIER, unknownTokenValue, currentLine, currentPosOnLine - unknownTokenValue.length());
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

    //Going until its end if it is not a single char
    while (currentChar != ' ' && currentChar != '\n' && currentChar != 0 && currentChar != 32 && !isalnum(currentChar)) {

        unknownTokenValue += currentChar; //Concatenate
        //This is to complete reading some tokens without implementing going back
        if (contents[currentIndex + 1] == ' ' || contents[currentIndex + 1] == '\n' ||
            contents[currentIndex + 1] == '\0' || isalnum(contents[currentIndex + 1]) || contents[currentIndex + 1] == ';')
            break;
        else
            advance();
    }

    //Special case for single characters with identifiers
    if (specialCharMappings.count(std::string() + unknownTokenValue) != 0) {
        return Token(specialCharMappings[std::string()+unknownTokenValue], unknownTokenValue, currentLine, tokenStart);
    }
    else {
        std::cout << "\n\n READ A STRANGE THING \n \n";
        return Token(Token::TOKEN_UNKNOWN, unknownTokenValue, currentLine, tokenStart);
    }
}


