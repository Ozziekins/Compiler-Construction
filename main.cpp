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
    std::ifstream sourceFile;
    std::string sourceCode;
    sourceFile.open(srcInput);
    std::string str;

    while(getline(sourceFile, str)){
        sourceCode += str; // reading data
    }
    sourceFile.close();

    Lexer sas = Lexer(sourceCode);
    while (sas.getNextToken().type != TOKEN_EOF);

    std::vector<Token> list = sas.getTokenList();
    for (auto i = list.begin(); i != list.end(); ++i) 
        std::cout << (*i).type << (*i).value << "\n";
    return 0;
}
