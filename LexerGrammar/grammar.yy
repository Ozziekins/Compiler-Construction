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
Program : Body                              
        ;
Body : /* empty */                              
     | Declaration Body                         
     | Statement Body                           
     | Expression Body                          
     ;
Declaration : TOKEN_VAR TOKEN_IDENTIFIER TOKEN_SEMI                                 
            | TOKEN_VAR TOKEN_IDENTIFIER TOKEN_ASSIGNMENT Expression TOKEN_SEMI     
            ;
Expression : Relation                           
           | Relation TOKEN_AND Relation        
           | Relation TOKEN_OR Relation         
           | Relation TOKEN_XOR Relation         
           ;
Relation : Factor                               
         | Factor TOKEN_LESS Factor             
         | Factor TOKEN_LEQ Factor              
         | Factor TOKEN_GREAT Factor            
         | Factor TOKEN_GEQ Factor              
         | Factor TOKEN_EQUAL Factor            
         | Factor TOKEN_NEQ Factor              
         ;
Factor : Term                                   
       | Term TOKEN_PLUS Factor                 
       | Term TOKEN_MINUS Factor                
       ;
Term : Unary                                    
     | Unary TOKEN_MULT Term                    
     | Unary TOKEN_DIV Term                     
     ;
Unary : Primary                                 
      | TOKEN_PLUS Primary                      
      | TOKEN_MINUS Primary                     
      | TOKEN_NOT Primary                       
      | Literal                                 
      | TOKEN_LPAREN Expression TOKEN_RPAREN    
      | TOKEN_PLUS Primary TOKEN_IS TypeIndicator           
      | TOKEN_MINUS Primary TOKEN_IS TypeIndicator          
      | TOKEN_NOT Primary TOKEN_IS TypeIndicator            
      | Primary TOKEN_IS TypeIndicator                      
      ;
Primary : TOKEN_IDENTIFIER Tails
        | TOKEN_READINT
        | TOKEN_READREAL
        | TOKEN_READSTRING
        ;
Tails : /* empty */                             
        | Tail Tails                           
        ;
Tail : TOKEN_DOT TOKEN_INT_LITERAL                   
     | TOKEN_DOT TOKEN_IDENTIFIER               
     | TOKEN_LSQUARE Expression TOKEN_RSQUARE   
     | TOKEN_LPAREN Expressions TOKEN_RPAREN    
     ;
Statement : Assignment                         
          | Print                              
          | Return                             
          | If                                 
          | Loop                               
          ;
Assignment : Primary TOKEN_ASSIGNMENT Expression TOKEN_SEMI      
           ;
Print : TOKEN_PRINT Expressions TOKEN_SEMI                
      ;
Expressions : Expression                        
            | Expression TOKEN_COMMA Expressions      
            ;
Return : TOKEN_RETURN Expression TOKEN_SEMI               
       | TOKEN_RETURN TOKEN_SEMI                          
       ;
If : TOKEN_IF Expression TOKEN_THEN Body TOKEN_END        
   | TOKEN_IF Expression TOKEN_THEN Body TOKEN_ELSE Body TOKEN_END      
   ;
Loop : TOKEN_WHILE Expression LoopBody          
     | TOKEN_FOR TOKEN_IDENTIFIER TOKEN_IN TypeIndicator LoopBody             
     ;
LoopBody : TOKEN_LOOP Body TOKEN_END            
         ;
TypeIndicator : TOKEN_INT                       
              | TOKEN_REAL                      
              | TOKEN_BOOL                      
              | TOKEN_STRING                    
              | TOKEN_EMPTY                     
              | ArrayLiteral                    
              | TupleLiteral                    
              | TOKEN_FUNC                      
              ;
Literal : TOKEN_INT_LITERAL                     
        | TOKEN_REAL_LITERAL                    
        | TOKEN_TRUE                            
        | TOKEN_FALSE                           
        | TOKEN_STRING_LITERAL                  
        | ArrayLiteral                          
        | TupleLiteral
        | FunctionLiteral                          
        ;
ArrayLiteral : TOKEN_LSQUARE TOKEN_RSQUARE      
             | TOKEN_LSQUARE Expressions TOKEN_RSQUARE      
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
Parameters : TOKEN_LPAREN Identifiers TOKEN_RPAREN        
           ;
Identifiers : TOKEN_IDENTIFIER                  
            | TOKEN_IDENTIFIER TOKEN_COMMA Identifiers            
FunBody : TOKEN_IS Body TOKEN_END               
        | TOKEN_FUNCTOR Expression              
        ;

%%
std::string srcInput;
std::vector<Token> list;
std::vector<Token>::iterator it;
int main(int argc, char *argv[]) {
    
    if(argc==1) {
        printf("\nRun with source file: ./a.out <source_file>");
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
