# Compiler-Construction
To track the progress of our CC course project  

## Phase 1: Lexer  
### How to run the code  
**Step 1:** clone the git repository  
**Step 2:** cd path/to/Lexer  
**Step 3:** in the main.cpp file, edit line 10 to look like  
```std::ifstream sourceCode("./source_code.d");  ```  
**Step 4:** git checkout master  
**Step 5:** g++ main.cpp Lexer.cpp include/Lexer.h Token.cpp include/Token.h  
**Step 6:** ./a.out  

## Phase 2: Parser
### How to run the code
**Step 1:** cd path/to/git_directory on your local machine  
**Step 2:** git pull  
**Step 3:** cd LexerGrammar  
**Step 4:** edit the source_code.d according to D language  
**Step 5:** bison -v grammar.yy (make sure to have bison version 3 and above)  
**Step 6:** make