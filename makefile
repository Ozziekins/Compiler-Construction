compile: grammar.tab.cc Lexer.cpp Token.cpp source_code.d grammar.tab.hh ast_nodes.o
	g++ -std=c++2a grammar.tab.cc Lexer.cpp Token.cpp ast_nodes.o && ./a.out source_code.d

ast_nodes.o: ast_nodes.cpp ast_nodes.h traverse.cpp traverse.h evaluate.cpp evaluate.h
	g++ -std=c++2a -c ast_nodes.cpp -o ast_nodes.o

grammar.tab.cc: grammar.yy
	bison -d grammar.yy

clean: 
	rm -f grammar.tab.cc grammar.tab.hh ./a.out