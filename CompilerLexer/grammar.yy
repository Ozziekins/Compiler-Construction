%require "3.0"
%define parse.lac full
%define parse.error verbose

%{
    #include <fstream>
    #include <stdlib.h>
    #include "Lexer.h"
    #include <sstream>
    #include <iostream>
    int yylex ();
    void yyerror(const char *error);
    NBlock *programBlock;
%}

%union {
  Node *node;
  NBlock *block;
  NExpression *expression;
  NStatement *statement;
  NIdentifier *identifier;
  NDeclaration *declaration;
  std::vector<NDeclaration*> *variableVector;
  std::vector<NStatement*> *statementVector;
  std::vector<NExpression*> *expressionVector;
  std::vector<NIdentifier*> *paramVector;

  std::string *string;
  int token;

  // std::string string_t;
  // int integer_t; 
  // float float_t;
  // unsigned int bool_t;
  // std::string dataType;
}

// Miscellaneous
%token <token> TOKEN_ASSIGNMENT TOKEN_FUNCTOR TOKEN_EOF TOKEN_UNKNOWN

// Identifiers
%token <string> TOKEN_IDENTIFIER

// Literals
%token <string> TOKEN_INT_LITERAL TOKEN_REAL_LITERAL TOKEN_STRING_LITERAL
%token <string> TOKEN_TRUE TOKEN_FALSE

// Keywords
%token <token> TOKEN_FUNC TOKEN_END TOKEN_IF TOKEN_THEN TOKEN_ELSE
%token <token> TOKEN_PRINT TOKEN_RETURN TOKEN_LOOP TOKEN_VAR TOKEN_WHILE TOKEN_FOR 
%token <token> TOKEN_IN  TOKEN_AND  TOKEN_OR  TOKEN_XOR TOKEN_NOT TOKEN_IS

// Types
%token <string> TOKEN_EMPTY TOKEN_INT  TOKEN_REAL TOKEN_BOOL TOKEN_STRING TOKEN_ARRAY TOKEN_TUPLE 

// Delimiters
%token <token> TOKEN_LPAREN TOKEN_RPAREN TOKEN_LSQUARE TOKEN_RSQUARE        
%token <token> TOKEN_LCURLY TOKEN_RCURLY TOKEN_SEMI TOKEN_COMMA TOKEN_DOT

// Operators
%token <token> TOKEN_PLUS TOKEN_MINUS TOKEN_MULT TOKEN_DIV TOKEN_EQUAL TOKEN_NEQ             
%token <token> TOKEN_LESS TOKEN_LEQ TOKEN_GREAT TOKEN_GEQ TOKEN_INCREMENT       

// Input
%token <string> TOKEN_READINT TOKEN_READREAL TOKEN_READSTRING

// Precedence
// %left TOKEN_COMMA
// %left TOKEN_ASSIGNMENT
// %left TOKEN_OR
// %left TOKEN_AND
// %left TOKEN_XOR
// %left TOKEN_EQUAL TOKEN_NEQ
// %left TOKEN_LEQ TOKEN_LESS TOKEN_GREAT TOKEN_GEQ
// %left TOKEN_PLUS TOKEN_MINUS
// %left TOKEN_MULT TOKEN_DIV
// %right TOKEN_NOT
// %left TOKEN_LPAREN TOKEN_LSQUARE TOKEN_LCURLY TOKEN_DOT

%type <block> Body ProgramBody LoopBody
%type <declaration> Declaration 
%type <statement> Statement 
%type <expression> Expression Relation Factor Term Unary Primary Literal 
%type <expression> ArrayLiteral TupleLiteral FunctionLiteral
%type <expressionVector> Expressions 
%type <statement> Assignment Print Return If Loop
%type <paramVector> Identifiers Parameters
%type <string> TypeIndicator
%start Program

%%
Program : Body                                                   { programBlock = $1; }
        ;
Body : /* empty */                                               { $$ = NULL; }
     | Declaration ProgramBody                                   { $$ = new NBlock(); $$->declarations.push_back($<declaration>1); }
     | Statement ProgramBody                                     { $$ = new NBlock(); $$->statements.push_back($<statement>1); }
     ;                                     
ProgramBody : /* empty */                                        { $$ = NULL; }
            | Declaration ProgramBody                            { $$->declarations.push_back($<declaration>1); }
            | Statement ProgramBody                              { $$->statements.push_back($<statement>1); }
            ;
Declaration : TOKEN_VAR TOKEN_IDENTIFIER TOKEN_SEMI                                       { $$ = new NDeclaration(*$2); }                                
            | TOKEN_VAR TOKEN_IDENTIFIER TOKEN_ASSIGNMENT Expression TOKEN_SEMI           { $$ = new NDeclaration(*$2, $4); }
            ;
Expression : Relation                                     { $$ = $1; }
           | Relation TOKEN_AND Relation                  { $$ = new NBinaryOperator(*$1, $2, *$3); }
           | Relation TOKEN_OR Relation                   { $$ = new NBinaryOperator(*$1, $2, *$3); }
           | Relation TOKEN_XOR Relation                  { $$ = new NBinaryOperator(*$1, $2, *$3); }
           ;
Relation : Factor                                         { $$ = $1; }
         | Factor TOKEN_LESS Factor                       { $$ = new NBinaryOperator(*$1, $2, *$3); }
         | Factor TOKEN_LEQ Factor                        { $$ = new NBinaryOperator(*$1, $2, *$3); }
         | Factor TOKEN_GREAT Factor                      { $$ = new NBinaryOperator(*$1, $2, *$3); }
         | Factor TOKEN_GEQ Factor                        { $$ = new NBinaryOperator(*$1, $2, *$3); }
         | Factor TOKEN_EQUAL Factor                      { $$ = new NBinaryOperator(*$1, $2, *$3); }
         | Factor TOKEN_NEQ Factor                        { $$ = new NBinaryOperator(*$1, $2, *$3); }
         ;
Factor : Term                                             { $$ = $1; }
       | Term TOKEN_PLUS Factor                           { $$ = new NBinaryOperator(*$1, $2, *$3); }
       | Term TOKEN_MINUS Factor                          { $$ = new NBinaryOperator(*$1, $2, *$3); }
       ;
Term : Unary                                              { $$ = $1; }
     | Unary TOKEN_MULT Term                              { $$ = new NBinaryOperator(*$1, $2, *$3); }
     | Unary TOKEN_DIV Term                               { $$ = new NBinaryOperator(*$1, $2, *$3); }
     ;
Unary : Primary                                 { $$ = $1; }
      | TOKEN_PLUS Primary                      { $$ = new NUnary($1, *$2); }
      | TOKEN_MINUS Primary                     { $$ = new NUnary($1, *$2); }
      | TOKEN_NOT Primary                       { $$ = new NUnary($1, *$2); }
      | Literal                                 { $$ = $1; }
      | TOKEN_LPAREN Expression TOKEN_RPAREN    { $$ = $2; }
      | TOKEN_PLUS Primary TOKEN_IS TypeIndicator           { $$ = new NTypeCheck($1, *$2, *$4); }
      | TOKEN_MINUS Primary TOKEN_IS TypeIndicator          { $$ = new NTypeCheck($1, *$2, *$4); }
      | TOKEN_NOT Primary TOKEN_IS TypeIndicator            { $$ = new NTypeCheck($1, *$2, *$4); }
      | Primary TOKEN_IS TypeIndicator                      { $$ = new NTypeCheck(*$1, *$3); }
      ;
Primary : //Literal                                           {;}// $$ = $1;} // Had to actually add this one
        //| TOKEN_LPAREN Expressions TOKEN_RPAREN             {;}// $$ = $2;} // This one as well 
          TOKEN_IDENTIFIER Tail                             { $$ = new NIdentifier(*$1); }
        | TOKEN_READINT                                     { $$ = new NReadInput(); }
        | TOKEN_READREAL                                    { $$ = new NReadInput(); }
        | TOKEN_READSTRING                                  { $$ = new NReadInput(); }
        ;
Tail : /* empty */
     | TOKEN_DOT TOKEN_INT_LITERAL                   
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
Assignment : Primary TOKEN_ASSIGNMENT Expression TOKEN_SEMI   { $$ = new NAssignment(*$1, *$3); }   
           ;
Print : TOKEN_PRINT Expressions TOKEN_SEMI                    { $$ = new NPrint(*$2); }         
      ;
Expressions : Expression                                      { $1 = new NExpression(); $$->push_back($1); }
            | Expression TOKEN_COMMA Expressions              { $3->push_back($1); }
            ;
Return : TOKEN_RETURN Expression TOKEN_SEMI                   { $$ = new NReturn(*$2); }             
       | TOKEN_RETURN TOKEN_SEMI                              { $$ = new NReturn(); }  
       ;
If : TOKEN_IF Expression TOKEN_THEN Body TOKEN_END            { $$ = new NIf(*$2, *$4); }
   | TOKEN_IF Expression TOKEN_THEN Body TOKEN_ELSE Body TOKEN_END      { $$ = new NIf(*$2, *$4, *$6); }
   ;
Loop : TOKEN_WHILE Expression LoopBody                        { $$ = new NLoop(*$2, *$3); }
     | TOKEN_FOR TOKEN_IDENTIFIER TOKEN_IN TypeIndicator LoopBody             { $$ = NULL; }
     ;
LoopBody : TOKEN_LOOP Body TOKEN_END                          { $$ = $2; }
         ;
TypeIndicator : TOKEN_INT                                     { $$ = $1; }                   
              | TOKEN_REAL                                    { $$ = $1; }
              | TOKEN_BOOL                                    { $$ = $1; }
              | TOKEN_STRING                                  { $$ = $1; }
              | TOKEN_EMPTY                                   { $$ = $1; }
              | TOKEN_ARRAY                                   { $$ = $1; }
              | TOKEN_TUPLE                                   { $$ = $1; }
              ;
Literal : TOKEN_INT_LITERAL                                   { $$ = new NInteger(atol($1->c_str()));}
        | TOKEN_REAL_LITERAL                                  { $$ = new NReal(atof($1->c_str()));}
        | TOKEN_TRUE                                          { $$ = new NBool(*$1); }
        | TOKEN_FALSE                                         { $$ = new NBool(*$1); }
        | TOKEN_STRING_LITERAL                                { $$ = new NString(*$1); }
        | ArrayLiteral                                        { $$ = NULL; }
        | TupleLiteral                                        { $$ = NULL; }
        | FunctionLiteral                                     { $$ = NULL; }
        ;
ArrayLiteral : TOKEN_LSQUARE TOKEN_RSQUARE                    { $$ = new NArray(); }
             | TOKEN_LSQUARE Expressions TOKEN_RSQUARE        { $$ = new NArray(); }
             ;
TupleLiteral : TOKEN_LCURLY TOKEN_RCURLY                      { $$ = new NTuple(); } 
             | TOKEN_LCURLY TOKEN_IDENTIFIER TupleTail        { $$ = new NTuple(); }
             | TOKEN_LCURLY TOKEN_IDENTIFIER TOKEN_ASSIGNMENT Expression TupleTail      { $$ = new NTuple(); }
             ;
TupleTail : TOKEN_RCURLY
          | TOKEN_COMMA TOKEN_IDENTIFIER TupleTail
          | TOKEN_COMMA TOKEN_IDENTIFIER TOKEN_ASSIGNMENT Expression TupleTail
          ;
FunctionLiteral : TOKEN_FUNC TOKEN_IS Body TOKEN_END                          { $$ = new NFunctionDefinition(*$3); }
                | TOKEN_FUNC TOKEN_FUNCTOR Expression                         { $$ = new NFunctionDefinition(*$3); }
                | TOKEN_FUNC Parameters TOKEN_IS Body TOKEN_END               { $$ = new NFunctionDefinition(*$2, *$4); }
                | TOKEN_FUNC Parameters TOKEN_FUNCTOR Expression              { $$ = new NFunctionDefinition(*$2, *$4); }
                ;
Parameters : TOKEN_LPAREN Identifiers TOKEN_RPAREN                            { $$ = $2; }
           ;
Identifiers : TOKEN_IDENTIFIER                                                { $$->push_back(new NIdentifier(*$1)); }
            | TOKEN_IDENTIFIER TOKEN_COMMA Identifiers                        { $3->push_back(new NIdentifier(*$1)); }
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
    std::cout << "No Syntax Errors\n";
    std::cout << "Tree start address: "<<programBlock << std::endl;
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

  yylval.string = new std::string( (*it).value );

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
