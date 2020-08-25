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
    if (currentChar != '\0' && currentIndex < contents.length()) {

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
    while (currentChar != '\0' && currentIndex < contents.length()) {

        //Will do nothing if there are no whitespaces
        while (currentChar == ' ' || currentChar == 10 || currentChar == '\t') {
            advance();
        }

        if (isalnum(currentChar))
            return readIdentifier();
        else if (currentChar == '"')
            return readString();
        else
            return registerToken();
    }

    return Token(Token::TOKEN_EOF, "NULL (END)", currentLine, currentPosOnLine); //This can only happen in the end?
}

Token Lexer::readString() {

    //Skipping the current "
    advance();

    //Is finding the position of the next " really more efficient than reallocating several times?
    unsigned int quotePosition = contents.find('"', currentIndex);
    unsigned int stringLength = quotePosition - currentIndex;

    //Does it create trash in memory??
    std::string resultingString = contents.substr(currentIndex, stringLength);

    //Saving result now; so that we won't have problems because of moving forward in the source code
    Token finalToken = Token(Token::TOKEN_LITERAL, resultingString, currentLine, currentPosOnLine - 1);

    //Move to the end of the string; after semicolon
    this->currentIndex = quotePosition + 1;
    this->currentChar = contents[currentIndex];
    this->currentPosOnLine += stringLength + 1; //+1 is to account for the first quote

    return finalToken;
}

Token Lexer::readIdentifier() {
    std::string identifierName;

    while (isalnum(currentChar) || ( currentChar == '.' && isalnum(contents[currentIndex+1]))) {
        identifierName += currentChar;
        advance();
    }

    if ( std::find( keywords.begin(), keywords.end(), identifierName) != keywords.end())
        return Token(Token::TOKEN_KEYWORD, identifierName, currentLine, currentPosOnLine - identifierName.length());
    else if ( std::find( operators.begin(), operators.end(), identifierName) != operators.end())
        return Token(Token::TOKEN_OPERATOR, identifierName, currentLine, currentPosOnLine - identifierName.length());
    else
        return Token(Token::TOKEN_IDENTIFIER, identifierName, currentLine, currentPosOnLine - identifierName.length());
}

//For tokens other than Identifiers and Strings
Token Lexer::registerToken() {

    //Just read the token to properly classify it later; it is UNKNOWN now
    Token finalToken = readUntilWhitespace();

    if (currentChar != '\0') {
        advance();
    }

    return finalToken;
}

Token Lexer::readUntilWhitespace() {

    std::string unknownTokenValue;

    //TODO Does the line really not change???
    unsigned int tokenStart = currentPosOnLine;

    //Special case for single characters with identifiers
    if (specialCharMappings.count(currentChar) != 0){
        return Token(specialCharMappings[currentChar], std::string() + currentChar, currentLine, currentPosOnLine );
    }

    //Going until its end if it is not a single char
    while ( currentChar != ' ' && currentChar != '\n' && currentChar != '\0' && currentChar != 32 ) {
        unknownTokenValue += currentChar;
        advance();
    }

    //Check for operators
    if ( std::find( operators.begin(), operators.end(), unknownTokenValue) != operators.end())
        return Token(Token::TOKEN_OPERATOR, unknownTokenValue, currentLine, tokenStart);
    else if (unknownTokenValue[0] == '+' || unknownTokenValue[0] == '-') //TODO IS THIS A KOSTIL???
        Token(Token::TOKEN_UNARIZEDSMTH, unknownTokenValue, currentLine, tokenStart);
    else{
        std::cout << "\n\n READ A STRANGE THING \n \n";
        return Token(Token::TOKEN_UNKNOWN, unknownTokenValue, currentLine, tokenStart);
    }
}


