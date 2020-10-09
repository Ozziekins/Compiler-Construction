%require "3.0"
%define parse.lac full
%define parse.error verbose

%{
    #include <fstream>
    #include <stdlib.h>
    #include "Lexer.h"
    #include <sstream>
    #include <iostream>
    #include <new>
    int yylex ();
    void yyerror(const char *error);
    NBlock *programBlock;

%}

%union {
  //Node *node;
  NProgram *program;
  NInstruction *instruction;
  NBlock *block;
  NDeclaration *declaration;
  NArray *array;
  NTuple *tuple;
  NStatement *statement;
  NAssignment *assignment;
  NTAssignments *tassign;
  NPrint *print;
  NFunctionDefinition *funcdef;
  NParameters *param;
  NIf *ifstmt;
  NIfElse *ifelse;
  NLoop *loop;
  NReturn *returnstmt;

  NExpression *expression;
  NIdentifier *identifier;
  NIntegerLiteral *integer_lit;
  NReal *real;
  NBool *boolstmt;
  NStringLiteral *string_lit;
  NBinaryOperator *binaryop;
  NTypeCheck *typecheck;
  NUnary *unary;
  // NReadInput *readinput;
  NExpressions *expressions;
  std::string *string;
  int token;
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
%token <token> TOKEN_PLUS TOKEN_MINUS TOKEN_MULT TOKEN_DIV TOKEN_EQUAL TOKEN_NEQ TOKEN_RANGE             
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

%type <block> Body LoopBody Program
%type <declaration> Declaration 
%type <statement> Statement 
%type <expression> Expression Relation Factor Term Unary Primary Literal 
%type <funcdef> FunctionLiteral
%type <expression> ArrayLiteral TupleLiteral
%type <tassign> TupleTail 
%type <statement> Assignment Return If Loop
%type <print> Print 
%type <expressions> Expressions 
%type <param> Identifiers Parameters
%type <token> TypeIndicator
%start Program

%%
Program : Body                                      { programBlock = $1; }
        ;                                   
Body : /* empty */                                  { $$ = new NBlock(); }
      | Declaration Body                            { $$ = $2; $$->push_back($1);  }
      | Statement Body                              { $$ = $2; $$->push_back($1); }
      ;
Declaration : TOKEN_VAR TOKEN_IDENTIFIER TOKEN_SEMI                                       { $$ = new NDeclaration(new NIdentifier($2)); }
            | TOKEN_VAR TOKEN_IDENTIFIER TOKEN_ASSIGNMENT Expression TOKEN_SEMI           { $$ = new NDeclaration(new NIdentifier($2), $4); }
            ;
Expression : Relation                                     { $$ = $1; }
           | Relation TOKEN_AND Relation                  { $$ = new NBinaryOperator($1, AND, $3); }
           | Relation TOKEN_OR Relation                   { $$ = new NBinaryOperator($1, OR, $3); }
           | Relation TOKEN_XOR Relation                  { $$ = new NBinaryOperator($1, XOR, $3); }
           ;
Relation : Factor                                         { $$ = $1; }
         | Factor TOKEN_LESS Factor                       { $$ = new NBinaryOperator($1, LESS, $3); }
         | Factor TOKEN_LEQ Factor                        { $$ = new NBinaryOperator($1, LEQ, $3); }
         | Factor TOKEN_GREAT Factor                      { $$ = new NBinaryOperator($1, GREAT, $3); }
         | Factor TOKEN_GEQ Factor                        { $$ = new NBinaryOperator($1, GEQ, $3); }
         | Factor TOKEN_EQUAL Factor                      { $$ = new NBinaryOperator($1, EQUAL, $3); }
         | Factor TOKEN_NEQ Factor                        { $$ = new NBinaryOperator($1, NEQ, $3); }
         ;
Factor : Term                                             { $$ = $1; }
       | Term TOKEN_PLUS Factor                           { $$ = new NBinaryOperator($1, PLUS, $3); }
       | Term TOKEN_MINUS Factor                          { $$ = new NBinaryOperator($1, MINUS, $3); }
       ;
Term : Unary                                              { $$ = $1; }
     | Unary TOKEN_MULT Term                              { $$ = new NBinaryOperator($1, MULT, $3); }
     | Unary TOKEN_DIV Term                               { $$ = new NBinaryOperator($1, DIV, $3); }
     ;
Unary : Primary                                 { $$ = $1; }
      | TOKEN_PLUS Primary                      { $$ = new NUnary(PLUS, $2); }
      | TOKEN_MINUS Primary                     { $$ = new NUnary(MINUS, $2); }
      | TOKEN_NOT Primary                       { $$ = new NUnary(NOT, $2); }
      | TOKEN_PLUS TOKEN_INT_LITERAL            { $$ = new NUnary(PLUS, new NIntegerLiteral(atol($2->c_str()))); }
      | TOKEN_MINUS TOKEN_INT_LITERAL           { $$ = new NUnary(MINUS, new NIntegerLiteral(atol($2->c_str()))); }
      | TOKEN_PLUS TOKEN_REAL_LITERAL           { $$ = new NUnary(PLUS, new NReal(atof($2->c_str()))); }
      | TOKEN_MINUS TOKEN_REAL_LITERAL          { $$ = new NUnary(MINUS, new NReal(atof($2->c_str()))); }
      | TOKEN_NOT TOKEN_TRUE                    { $$ = new NUnary(NOT, new NBool($2)); }
      | TOKEN_NOT TOKEN_FALSE                   { $$ = new NUnary(NOT, new NBool($2)); }
      | TOKEN_READINT                           { $$ = new NReadIntInput(); }
      | TOKEN_READREAL                          { $$ = new NReadRealInput(); }
      | TOKEN_READSTRING                        { $$ = new NReadStringInput(); }
      | Literal                                 { $$ = $1; }
      | TOKEN_LPAREN Expression TOKEN_RPAREN    { $$ = $2; }
      | TOKEN_PLUS Primary TOKEN_IS TypeIndicator           { $$ = new NTypeCheck(PLUS, $2, $4); }
      | TOKEN_MINUS Primary TOKEN_IS TypeIndicator          { $$ = new NTypeCheck(MINUS, $2, $4); }
      | TOKEN_NOT Primary TOKEN_IS TypeIndicator            { $$ = new NTypeCheck(NOT, $2, $4); }
      | Primary TOKEN_IS TypeIndicator                      { $$ = new NTypeCheck($1, $3); }
      ;
Primary : TOKEN_IDENTIFIER                                              { $$ = new NIdentifier($1); }
        | TOKEN_IDENTIFIER TOKEN_DOT TOKEN_INT_LITERAL                  //{ $$ = new NTupleElementIndex(new NIdentifier($1), $3); }
        | TOKEN_IDENTIFIER TOKEN_DOT TOKEN_IDENTIFIER                   //{ $$ = new NTupleElementName(new NIdentifier($1), $3); }
        | TOKEN_IDENTIFIER TOKEN_LSQUARE Expression TOKEN_RSQUARE       //{ $$ = new NArrayElement(new NIdentifier($1), $3); }
        | TOKEN_IDENTIFIER TOKEN_LPAREN Expressions TOKEN_RPAREN          { $$ = new NFunctionCall(new NIdentifier($1), $3); }
        | TOKEN_IDENTIFIER TOKEN_LPAREN TOKEN_RPAREN                      { $$ = new NFunctionCall(new NIdentifier($1), new NExpressions() ); }
        ;
Statement : Assignment                                  { $$ = $1; }
          | Print                                       { $$ = $1; }
          | Return                                      { $$ = $1; }
          | If                                          { $$ = $1; }
          | Loop                                        { $$ = $1; }
          // | TOKEN_IDENTIFIER TOKEN_LPAREN Expressions TOKEN_RPAREN    TOKEN_SEMI   { $$ = new NFunctionCall(new NIdentifier($1), $3); }
          ;
Assignment : Primary TOKEN_ASSIGNMENT Expression TOKEN_SEMI   { $$ = new NAssignment($1, $3); }   
           ;
Print : TOKEN_PRINT Expressions TOKEN_SEMI                    { $$ = new NPrint($2); }         
      ;
Expressions : Expression                                      { $$ = new NExpressions(); $$->push_argument($1); }
            | Expression TOKEN_COMMA Expressions              { $$ = $3; $$->push_argument($1); }
            ;
Return : TOKEN_RETURN Expression TOKEN_SEMI                   { $$ = new NReturn($2); }             
       | TOKEN_RETURN TOKEN_SEMI                              { $$ = new NReturn(); }  
       ;
If : TOKEN_IF Expression TOKEN_THEN Body TOKEN_END                      { $$ = new NIf($2, $4); }
   | TOKEN_IF Expression TOKEN_THEN Body TOKEN_ELSE Body TOKEN_END      { $$ = new NIfElse($2, $4, $6); }
   ;
Loop : TOKEN_WHILE Expression LoopBody                                                    { $$ = new NLoop($2, $3); }
    //  | TOKEN_FOR TOKEN_IDENTIFIER TOKEN_IN TypeIndicator LoopBody                         { $$ = NULL; }
     | TOKEN_FOR TOKEN_IDENTIFIER TOKEN_IN Expression TOKEN_RANGE Expression  LoopBody    { $$ = new NRangeLoop(new NIdentifier($2), $4, $6, $7); } 
     ; 
LoopBody : TOKEN_LOOP Body TOKEN_END                          { $$ = $2; }
         ;
TypeIndicator : TOKEN_INT                                     { $$ = INTEGER; }                   
              | TOKEN_REAL                                    { $$ = FLOAT; }
              | TOKEN_BOOL                                    { $$ = BOOL; }
              | TOKEN_STRING                                  { $$ = STRING; }
              | TOKEN_EMPTY                                   { $$ = EMPTY; }
              | TOKEN_ARRAY                                   { $$ = ARRAY; }
              | TOKEN_TUPLE                                   { $$ = TUPLE; }
              ;
Literal : TOKEN_INT_LITERAL                                   { $$ = new NIntegerLiteral(atol($1->c_str())); }
        | TOKEN_REAL_LITERAL                                  { $$ = new NReal(atof($1->c_str())); }
        | TOKEN_TRUE                                          { $$ = new NBool($1); }
        | TOKEN_FALSE                                         { $$ = new NBool($1); }
        | TOKEN_STRING_LITERAL                                { $$ = new NStringLiteral($1); }
        | ArrayLiteral                                        { $$ = $1; }
        | TupleLiteral                                        { $$ = $1; }
        | FunctionLiteral                                     { $$ = $1; }
        ;
ArrayLiteral : TOKEN_LSQUARE TOKEN_RSQUARE                    { $$ = new NArray(); }
             | TOKEN_LSQUARE Expressions TOKEN_RSQUARE        { $$ = new NArray($2); }
             ;
TupleLiteral : TOKEN_LCURLY TOKEN_RCURLY                      { $$ = new NTuple(); } 
             | TOKEN_LCURLY Expression TupleTail              { $3->push_assignment($2); $$ = new NTuple($3); }
             | TOKEN_LCURLY TOKEN_IDENTIFIER TOKEN_ASSIGNMENT Expression TupleTail      { $5->push_assignment($2, $4); $$ = new NTuple($5); }
             ;
TupleTail : TOKEN_RCURLY                                                            {$$ = new NTAssignments();}
          | TOKEN_COMMA Expression TupleTail                                        {$$ = $3; $$->push_assignment($2);}
          | TOKEN_COMMA TOKEN_IDENTIFIER TOKEN_ASSIGNMENT Expression TupleTail      {$$ = $5; $$->push_assignment($2, $4);}
          ;
FunctionLiteral : TOKEN_FUNC TOKEN_IS Body TOKEN_END                          { $$ = new NFunctionDefinition();  $$->setBody($3); }
                | TOKEN_FUNC TOKEN_FUNCTOR Expression                         { $$ = new NFunctionDefinition();  $$->setExpression($3); }
                | TOKEN_FUNC Parameters TOKEN_IS Body TOKEN_END               { $$ = new NFunctionDefinition();  $$->setParameters($2); $$->setBody($4); }
                | TOKEN_FUNC Parameters TOKEN_FUNCTOR Expression              { $$ = new NFunctionDefinition();  $$->setParameters($2); $$->setExpression($4); }
                ;
Parameters : TOKEN_LPAREN Identifiers TOKEN_RPAREN                            { $$ = $2; }
           ;
Identifiers : TOKEN_IDENTIFIER                                                { $$ = new NParameters(); $$->push_parameter(new NIdentifier($1)); }
            | TOKEN_IDENTIFIER TOKEN_COMMA Identifiers                        { $$ = $3; $$->push_parameter(new NIdentifier($1)); }
            ;

%%
std::string srcInput;
std::vector<Token> lst;
std::vector<Token>::iterator it;
typedef struct {
  std::string value;
  unsigned long line, column;
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
    lst = sas.getTokenList();
    yyparse();
    // std::cout << programBlock << std::endl;

    Evaluate t;
    cout << "Evaluating" << endl;
    programBlock->accept(t);
    return 0;
}

void yyerror(const char *error){
    std::cout << "\n";
    std::cout << error << " \'"<< feedback.value <<"\' on [" << feedback.line 
    << ":" << feedback.column << "]\n\n";
    exit(228);
}



int yylex () {
  it = lst.begin();
  unsigned long _type = (*it).type;
  std::string _value = (*it).value;
  unsigned long _lineNo = (*it).line;
  unsigned long _column = (*it).position;

  feedback.value = _value;
  feedback.line = _lineNo;
  feedback.column = _column;

  yylval.string = new std::string((*it).value);

  if (_type == YYEOF) {
    return YYEOF;
  }
  if (_type == YYUNDEF) {
    std::cout << _type << " Undefined token " << _value << std::endl;
    return (int)_type;
  }
  lst.erase(it);
  return (int)_type;
}
