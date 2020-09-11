Build Grammar with (make sure you have bison version >= 3.0)
```
~$ bison -d grammar.yy
```

create executable using 
```
~$ g++ -std=c++11 grammar.tab.cc Lexer.cpp Token.cpp
```

Run the executable using
```
./a.out source_code.d 
```
{Now we need to print the errors to the console or into a file}
