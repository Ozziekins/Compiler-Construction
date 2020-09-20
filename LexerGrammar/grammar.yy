%require "3.0"
%define parse.lac full
%define parse.error verbose

%code {
    #include <fstream>
    #include "Lexer.h"
    #include <sstream>
    #include <iostream>
    #include <cstring>
    int yylex ();
    void yyerror(const char *error);
    
}

%union {
 // std::string string_t;
  int integer_t;
  double real_t;
  unsigned int bool_t;
  char string_t[500];
  //std::string dataType;
}

// Miscellaneous
%token TOKEN_ASSIGNMENT      //:=
%token TOKEN_FUNCTOR         // =>
%token TOKEN_EOF
%token TOKEN_UNKNOWN

// Identifiers
%token TOKEN_IDENTIFIER

// Literals
%nterm<integer_t> Literal
%token<integer_t> TOKEN_INT_LITERAL
%token<real_t> TOKEN_REAL_LITERAL
%token<string_t> TOKEN_STRING_LITERAL   // note that this string is different from type string which is a keyword
%token TOKEN_TRUE //TODO add
%token TOKEN_FALSE //TODO add

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
//%token<array_t> TOKEN_ARRAY
//%token<tuple_t> TOKEN_TUPLE

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


// Type declaration
%type<integer_t> Expressions Expression Relation Factor Term Unary  Primary TOKEN_IDENTIFIER
// %type<float_t> Unary
// %type<string_t> Unary 
// %type<bool_t> Expression Relation Unary
//%type <array_t> ArrayLiteral
//%type <tuple_t> TupleLiteral
//%type <func_t> FunctionLiteral



// Precedence
%left TOKEN_COMMA
%left TOKEN_ASSIGNMENT
%left TOKEN_OR
%left TOKEN_AND
%left TOKEN_XOR
%left TOKEN_EQUAL TOKEN_NEQ
%left TOKEN_LEQ TOKEN_LESS TOKEN_GREAT TOKEN_GEQ
%left TOKEN_PLUS TOKEN_MINUS
%left TOKEN_MULT TOKEN_DIV
%right TOKEN_NOT
%left TOKEN_LPAREN TOKEN_LSQUARE TOKEN_LCURLY TOKEN_DOT


%start Program

%%
Program : Body                              
        ;
Body : /* empty */                                        //{$$ = NULL; }
     | Declaration Body                                   {;}
     | Statement Body                                     {;}
     | Expression Body                                    {;}     
     ;
Declaration : TOKEN_VAR TOKEN_IDENTIFIER LineEnd          {printf(" Declared Identifier '%d'", $2);} // SYMBOL_TABLE                     
            | TOKEN_VAR TOKEN_IDENTIFIER TOKEN_ASSIGNMENT Expression LineEnd  {printf(" Initialized Identifier '%d' with %d", $2, $4);}  // SYMBOL_TABLE   
            ;
Expression : Relation                                     { $$ = $1;}
           | Relation TOKEN_AND Relation                  { $$ = $1 && $3; }
           | Relation TOKEN_OR Relation                   { $$ = $1 || $3; }
           | Relation TOKEN_XOR Relation                  { $$ = ($1 || $3)&&(!$1 || !$3); }
           ;
Relation : Factor                                         { $$ = $1;}
         | Factor TOKEN_LESS Factor                       { $$ = $1 < $3; }
         | Factor TOKEN_LEQ Factor                        { $$ = $1 <= $3; }
         | Factor TOKEN_GREAT Factor                      { $$ = $1 > $3; }
         | Factor TOKEN_GEQ Factor                        { $$ = $1 >= $3; }
         | Factor TOKEN_EQUAL Factor                      { $$ = $1 == $3; }
         | Factor TOKEN_NEQ Factor                        { $$ = $1 != $3; }
         ;  
Factor : Term                                             { $$ = $1;}
       | Term TOKEN_PLUS Factor                           {;}//$$ = $1 + $3;}
       | Term TOKEN_MINUS Factor                          {;}//$$ = $1 - $3; }
       ;
Term : Unary                                              { $$ = $1;}    
     | Unary TOKEN_MULT Term                              { $$ = $1;}//$$ = $1 * $3; }
     | Unary TOKEN_DIV Term                               { $$ = $1;}//$$ = $1 / $3; }
     ;
Unary : Primary                                           { $$ = $1;}    
      | TOKEN_PLUS Primary                                { $$ = $2; }
      | TOKEN_MINUS Primary                               { $$ = -$2;}
      | TOKEN_NOT Primary                                 { $$ = !$2;}
      | Literal                                           { $$ = $1;}               
      | TOKEN_LPAREN Expression TOKEN_RPAREN              { $$ = $2;} //Do something with Precedence??
      | TOKEN_PLUS Primary TOKEN_IS TypeIndicator         {;}       
      | TOKEN_MINUS Primary TOKEN_IS TypeIndicator        {;}        
      | TOKEN_NOT Primary TOKEN_IS TypeIndicator          {;}         
      | Primary TOKEN_IS TypeIndicator                    {;}          
      ;
Primary : Literal                                         { $$ = $1;} // Had to actually add this one
        | TOKEN_LPAREN Expressions TOKEN_RPAREN           { $$ = $2;} // This one as well 
        | TOKEN_IDENTIFIER Tails  
        | TOKEN_READINT                                     //{scanf("%d", &$1); $$ = $1; } // SYMBOL_TABLE
        | TOKEN_READREAL                                    //{scanf("%f", &$1); $$ = $1; } // SYMBOL_TABLE
        | TOKEN_READSTRING                                  //{scanf("%s", $1); $$ = $1; }  // SYMBOL_TABLE
        ;
Tails : /* empty */                                         //{$$ = NULL; }
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
Assignment : Primary TOKEN_ASSIGNMENT Expression LineEnd   //{$$ = $1 = $3; }   
           ;
Print : TOKEN_PRINT Expressions LineEnd                    {std::cout << "(Strings do not work yet) printed: " << $2 << std::endl;}            
      ;
Expressions : Expression                                           //{
                                                                   // integer_t number = $1;
                                                                   // $$ = std::vector<integer_t>();
                                                                   // $$.push_back(number);
                                                                   // std::cout << "first arg"  << number << std::endl;
                                                                  //}   
            | Expression TOKEN_COMMA Expressions                  //{
                                                                 // integer_t number = $1;
                                                                 // std::vector<integer_t> &args = $3;
                                                                 // args.push_back(number);
                                                                 // $$ = args;
                                                                 // std::cout << "next argmnt" << number << ", arg list size = " << args.size() << std::endl;
                                                                 // }
            ;
Return : TOKEN_RETURN Expression LineEnd                   //{$$ = return $2; }             
       | TOKEN_RETURN LineEnd                              //{$$ = NULL; }  
       ;
If : TOKEN_IF Expression TOKEN_THEN Body TOKEN_END            //{$$ = if_statement($2, $4, NULL); }
   | TOKEN_IF Expression TOKEN_THEN Body TOKEN_ELSE Body TOKEN_END      //{$$ = if_statement($2, $4, $6); }
   ;
Loop : TOKEN_WHILE Expression LoopBody                        
     | TOKEN_FOR TOKEN_IDENTIFIER TOKEN_IN TypeIndicator LoopBody             
     ;
LoopBody : TOKEN_LOOP Body TOKEN_END            
         ;
TypeIndicator : TOKEN_INT                                     //{$$ = "int";}                   
              | TOKEN_REAL                                    //{$$ = "float";}
              | TOKEN_BOOL                                    //{$$ = "bool";}
              | TOKEN_STRING                                  //{$$ = "string";}
              | TOKEN_EMPTY                                   //{$$ = "empty";}
              | ArrayLiteral                    
              | TupleLiteral                    
              | TOKEN_FUNC                      
              ;
Literal : TOKEN_INT_LITERAL                                  { $$ = $1; std::cout << "\n Found Int literal: " << $$ << std::endl;}
        | TOKEN_REAL_LITERAL                                 { $$ = $1; std::cout << "\n Found Real literal(dont mind the rounding): " << $$ << std::endl;}                 
        | TOKEN_TRUE                                         { $$ = 1; std::cout <<  "\n Found True " << std::endl;}
        | TOKEN_FALSE                                        { $$ = 0; std::cout <<  "\n Found False " << std::endl;}
        | TOKEN_STRING_LITERAL                               { printf("\n There are problems, so not declared string literal %s\n", $1);}
        | ArrayLiteral                          
        | TupleLiteral
        | FunctionLiteral                                    { ;}
        ;
ArrayLiteral : TOKEN_LSQUARE TOKEN_RSQUARE                  
             | TOKEN_LSQUARE Expressions TOKEN_RSQUARE      // USe std::variant
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
LineEnd : /* empty */
        |TOKEN_SEMI //Causes a lot of conflicts :(
        ;

%%
std::string srcInput;
std::vector<Token> list;
std::vector<Token>::iterator it;
typedef struct {
  std::string value;
  unsigned int line, column;
} errorfeedback;
errorfeedback feedback;
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
    yyparse();
    std::cout << "\nNo Syntax Errors\n";
    return 0;
}

void yyerror(const char *error){
    std::cout << "\n";
    std::cout << error << " \'"<< feedback.value <<"\' on [" << feedback.line 
    << ":" << feedback.column << "]\n\n";
}



int yylex () {
  it = list.begin();
  unsigned int _type = (*it).type;
  std::string _value = (*it).value;
  unsigned int _lineNo = (*it).line;
  unsigned int _column = (*it).position;

  feedback.value = _value;
  feedback.line = _lineNo;
  feedback.column = _column;

  
  if (_type == TOKEN_INT_LITERAL)
    yylval.integer_t  = atoi( _value.c_str() );
  else if ( _type == TOKEN_REAL_LITERAL)
    yylval.real_t = atof (_value.c_str());
  else{
    char* kostil = (char*)_value.c_str();
    strcpy(yylval.string_t, kostil);
  }

  if (_type == YYEOF) {
    return YYEOF;
  }
  if (_type == YYUNDEF) {
    std::cout << _type << " Undefined token " << _value << std::endl;
    return _type;
  }
  list.erase(it);
  return _type;
}
