#include <fstream>
#include "Lexer.h"
#include <sstream>
#include <iostream>


int main(int argc, char *argv[]) {
    std::string srcInput;
    if(argc==1) {
        printf("\nRun with filename: ./a.out <source_file>");
        exit(0);
    } else if(argc==2) { 
        srcInput = argv[1];
    } 
    
    //Reading the source code
    std::ifstream sourceCode(srcInput);
    std::string str;

    if(sourceCode){
        std::ostringstream ss;
        ss << sourceCode.rdbuf(); // reading data
        str = ss.str();
    } else{

        std::cout << "\n\n Error reading file\n \n";
        exit(228);
    }
    sourceCode.close();

    Lexer sas = Lexer(str);
    while (sas.getNextToken().type != Token::TOKEN_EOF);

    std::vector<Token> list = sas.getTokenList();
    for (auto i = list.begin(); i != list.end(); ++i) 
        std::cout << (*i).type << (*i).value << "\n";
    return 0;
}
