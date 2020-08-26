# Compiler-Construction
To track the progress of our CC course project  

### How to run the code  
**Step 1:** clone the git repository  
**Step 2:** cd path/to/Lexer  
**Step 3:** in the main.cpp file, edit line 10 to look like  
```std::ifstream sourceCode("./source_code.d");  ```  
**Step 4:** git checkout master
**Step 5:** g++ main.cpp Lexer.cpp include/Lexer.h Token.cpp include/Token.h  
**Step 6:** ./a.out
