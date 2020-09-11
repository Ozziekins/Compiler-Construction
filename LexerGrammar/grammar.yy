%require "3.0"
%define api.pure full

%code {
    #include <fstream>
    #include "Lexer.h"
    #include <sstream>
    #include <iostream>
    int yylex (YYSTYPE *lvalp);
    void yyerror(const char *error);
}


// Miscellaneous
%token TOKEN_ASSIGNMENT      //:=
%token TOKEN_FUNCTOR         // =>
%token TOKEN_EOF
%token TOKEN_UNKNOWN

// Identifiers
%token TOKEN_IDENTIFIER

// Literals
%token TOKEN_INT_LITERAL
%token TOKEN_REAL_LITERAL
%token TOKEN_STRING_LITERAL   // note that this string is different from type string which is a keyword
%token TOKEN_TRUE
%token TOKEN_FALSE

// Keywords
%token TOKEN_FUNC
%token TOKEN_END
%token TOKEN_IF 
%token TOKEN_THEN
%token TOKEN_ELSE
%token TOKEN_PRINT
%token TOKEN_RETURN
%token TOKEN_LOOP
%token TOKEN_VAR
%token TOKEN_WHILE
%token TOKEN_FOR 
%token TOKEN_IN 
%token TOKEN_AND 
%token TOKEN_OR 
%token TOKEN_XOR
%token TOKEN_NOT
%token TOKEN_IS

// Types
%token TOKEN_EMPTY
%token TOKEN_INT 
%token TOKEN_REAL
%token TOKEN_BOOL
%token TOKEN_STRING

// Delimiters
%token TOKEN_LPAREN          // (
%token TOKEN_RPAREN          // )
%token TOKEN_LSQUARE         // [
%token TOKEN_RSQUARE         // ]
%token TOKEN_LCURLY          // {
%token TOKEN_RCURLY          // }
%token TOKEN_SEMI            // ;
%token TOKEN_COMMA           // ,
%token TOKEN_DOT             // .

// Operators
%token TOKEN_PLUS            // +
%token TOKEN_MINUS           // -
%token TOKEN_MULT            // *
%token TOKEN_DIV             // /
%token TOKEN_EQUAL           // =
%token TOKEN_NEQ             // /=
%token TOKEN_LESS            // <
%token TOKEN_LEQ             // <=
%token TOKEN_GREAT           // >
%token TOKEN_GEQ             // >=
%token TOKEN_INCREMENT       // +=

// Input
%token TOKEN_READINT
%token TOKEN_READREAL
%token TOKEN_READSTRING

%%
Program : Body                              //{$$}
        ;
Body : /* empty */                              //{$$ = null; }
     | Declaration Body                         
     | Statement Body                           
     | Expression Body                          
     ;
Declaration : TOKEN_VAR TOKEN_IDENTIFIER TOKEN_SEMI                                 
            | TOKEN_VAR TOKEN_IDENTIFIER TOKEN_ASSIGNMENT Expression TOKEN_SEMI     
            ;
Expression : Relation                           //{$$}
           | Relation TOKEN_AND Relation        //{$$ = $1 && $3; }
           | Relation TOKEN_OR Relation         //{$$ = $1 || $3; }
           | Relation TOKEN_XOR Relation        //{$$ = xor($1, $3); }
           ;
Relation : Factor                               //{$$}
         | Factor TOKEN_LESS Factor             //{$$ = $1 < $3; }
         | Factor TOKEN_LEQ Factor              //{$$ = $1 <= $3; }
         | Factor TOKEN_GREAT Factor            //{$$ = $1 > $3; }
         | Factor TOKEN_GEQ Factor              //{$$ = $1 >= $3; }
         | Factor TOKEN_EQUAL Factor            //{$$ = $1 == $3; }
         | Factor TOKEN_NEQ Factor              //{$$ = $1 != $3; }
         ;
Factor : Term                                   //{$$}
       | Term TOKEN_PLUS Factor                 //{$$ = $1 + $3; }
       | Term TOKEN_MINUS Factor                //{$$ = $1 - $3; }
       ;
Term : Unary                                    //{$$}
     | Unary TOKEN_MULT Term                    //{$$ = $1 * $3; }
     | Unary TOKEN_DIV Term                     //{$$ = $1 / $3; }
     ;
Unary : Primary                                 //{$$}
      | TOKEN_PLUS Primary                      //{$$ = + $2; }
      | TOKEN_MINUS Primary                     //{$$ = - $2; }
      | TOKEN_NOT Primary                       //{$$ = ! $2; }
      | Literal                                 //{$$}
      | TOKEN_LPAREN Expression TOKEN_RPAREN    //{( $2 ); }
      | TOKEN_PLUS Primary TOKEN_IS TypeIndicator           //{type(+$2); }
      | TOKEN_MINUS Primary TOKEN_IS TypeIndicator          //{type(-$2); }
      | TOKEN_NOT Primary TOKEN_IS TypeIndicator            //{!type($2); }
      | Primary TOKEN_IS TypeIndicator                      //{type($2); }
      ;
Primary : TOKEN_IDENTIFIER Tails                //{$$ = $1 $2; }
        | Literal
        | TOKEN_READINT
        | TOKEN_READREAL
        | TOKEN_READSTRING
        ;
Tails : /* empty */                             //{$$ = null; }
        | Tail Tails                           //{$$ = $1 $2; }
        ;
Tail : TOKEN_DOT TOKEN_INT_LITERAL                   //{$$ = $1 $2; }
     | TOKEN_DOT TOKEN_IDENTIFIER               //{$$ = $1 $2; }
     | TOKEN_LSQUARE Expression TOKEN_RSQUARE   //{$$ = [ $2 ]; }
     | TOKEN_LPAREN Expressions TOKEN_RPAREN    //{$$ = ( $2 ); }//Add support for tuples
     ;
Statement : Assignment                         //{$$}
          | Print                              //{$$}
          | Return                             //{$$}
          | If                                 //{$$}
          | Loop                               //{$$}
          ;
Assignment : Primary TOKEN_ASSIGNMENT Expression TOKEN_SEMI      //{$$ = $1 = $3; }
           ;
Print : TOKEN_PRINT Expressions TOKEN_SEMI                //{$$ = printf("%s", $2); }
      ;
Expressions : Expression                        //{$$}
            | Expression TOKEN_COMMA Expressions      //{$$ = $1, $3; }
            ;
Return : TOKEN_RETURN Expression TOKEN_SEMI               //{$$ = return $2; }
       | TOKEN_RETURN                           //{$$ = return; }
       ;
If : TOKEN_IF Expression TOKEN_THEN Body TOKEN_END        //{$$ = if($2) {$4}; }
   | TOKEN_IF Expression TOKEN_THEN Body TOKEN_ELSE Body TOKEN_END      //{$$ = if($2) {$4} else {$6}; }
   ;
Loop : TOKEN_WHILE Expression LoopBody          //{$$ = while_loop($2, $3); }
     | TOKEN_FOR TOKEN_IDENTIFIER TOKEN_IN TypeIndicator LoopBody             //{$$ = for_loop($2, $4, $5); }
     ;
LoopBody : TOKEN_LOOP Body TOKEN_END            //{$$ = $1 $2 $3; }
         ;
TypeIndicator : TOKEN_INT                       //{$$}
              | TOKEN_REAL                      //{$$}
              | TOKEN_BOOL                      //{$$}
              | TOKEN_STRING                    //{$$}
              | TOKEN_EMPTY                     //{$$}
              | ArrayLiteral                    //{$$}
              | TupleLiteral                    //{$$}
              | TOKEN_FUNC                      //{$$}
              ;
Literal : TOKEN_INT_LITERAL                     //{$$}
        | TOKEN_REAL_LITERAL                    //{$$}
        | TOKEN_TRUE                            //{$$}
        | TOKEN_FALSE                           //{$$}
        | TOKEN_STRING_LITERAL                  //{$$}
        | ArrayLiteral                          //{$$}
        | TupleLiteral
        | FunctionLiteral                          //{$$}
        ;
ArrayLiteral : TOKEN_LSQUARE TOKEN_RSQUARE      //{$$ = [ ]; }
             | TOKEN_LSQUARE Expressions TOKEN_RSQUARE      //{$$ = [ $2 ]; }
             ;
TupleLiteral : TOKEN_LCURLY TOKEN_RCURLY
             | TOKEN_LCURLY TOKEN_IDENTIFIER TupleTail
             | TOKEN_LCURLY TOKEN_IDENTIFIER TOKEN_ASSIGNMENT Expression TupleTail
             ;
TupleTail : TOKEN_RCURLY
          | TOKEN_COMMA TOKEN_IDENTIFIER TupleTail
          | TOKEN_COMMA TOKEN_IDENTIFIER TOKEN_ASSIGNMENT Expression TupleTail

FunctionLiteral : TOKEN_FUNC FunBody            
                | TOKEN_FUNC Parameters FunBody 
                ;
Parameters : TOKEN_LPAREN Identifiers TOKEN_RPAREN        //{$$ = ( $2 ); }
           ;
Identifiers : TOKEN_IDENTIFIER                  //{$$}
            | TOKEN_IDENTIFIER TOKEN_COMMA Identifiers            //{$$ = $1, $3; }
FunBody : TOKEN_IS Body TOKEN_END               //{$$ = { $2 }; }
        | TOKEN_FUNCTOR Expression              //{$$ = {return $2;}; }
        ;

%%
std::string srcInput;
std::vector<Token> list;
std::vector<Token>::iterator it;
int main(int argc, char *argv[]) {
    
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
        sourceCode += (str + "\n"); // reading data
    }
    sourceFile.close();
    
    Lexer sas = Lexer(sourceCode);
    
    while (sas.getNextToken().type != YYEOF);
    list = sas.getTokenList();
    return yyparse();
}

void yyerror(const char *error){
    std::cout << error << std::endl;
}



int yylex (YYSTYPE *lvalp) {
  it = list.begin();
  unsigned int _type = (*it).type;
  std::string _value = (*it).value;
  unsigned int _lineNo = (*it).line;
  unsigned int _column = (*it).position;
  if (_type == YYEOF) {
    return YYEOF;
  }
  if (_type == YYUNDEF) {
    std::cout << _type << " Undefined token " << _value << std::endl;
    return _type;
  }
  list.erase(it);
  std::cout << _type << " - " << _value << " [ " << _lineNo << ", " << _column << " ] " << std::endl;
  return _type;
}
