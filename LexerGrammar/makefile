compile: grammar.tab.cc Lexer.cpp Token.cpp source_code.d grammar.tab.hh
	g++ -std=c++11 grammar.tab.cc Lexer.cpp Token.cpp && ./a.out source_code.d

grammar.tab.cc: grammar.yy
	bison -d grammar.yy

clean: 
	rm -f grammar.tab.cc grammar.tab.hh ./a.out