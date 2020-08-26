#include <fstream>
#include "include/Lexer.h"
#include <sstream>
#include <iostream>


int main() {

    //Reading the source code
    std::ifstream sourceCode("../source_code.d");
    std::string str;

    if(sourceCode){
        std::ostringstream ss;
        ss << sourceCode.rdbuf(); // reading data
        str = ss.str();
    } else{

        std::cout << "\n\n Error reading file\n \n";
        exit(228);
    }


    Lexer sas = Lexer(str);
    while (sas.getNextToken().type != Token::TOKEN_EOF);

    sourceCode.close();
    return 0;
}
