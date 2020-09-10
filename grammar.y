%{

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//size for the hashtable
#define SIZE 200

struct variableItem {
   char *type;   
   char *data_type;
   char *name;
};

/* Since using handwritten lexer, Modify the next 2 lines */
extern int yylineno;//we use this variable in order to get the errors line
extern FILE* yyin;


void yyerror(char *s);
void check_declaration_and_store(char* string, char* data_type,char *type);
void check_type(char* string_1,char* string_2, char* opt);
void is_declared(char* string);
int generate_hash(char* string);
struct variableItem *search(char *name);
void insert(char *name, char *type,char *data_type);

%}


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

// Operator Precedence
%left TOKEN_INCREMENT TOKEN_LSQUARE TOKEN_RSQUARE TOKEN_LPAREN TOKEN_RPAREN TOKEN_LCURLY TOKEN_RCURLY
%right TOKEN_NOT
%left TOKEN_MULT TOKEN_DIV 
%left TOKEN_PLUS TOKEN_MINUS
%left TOKEN_GREAT TOKEN_GEQ TOKEN_LESS TOKEN_LEQ
%left TOKEN_EQUAL TOKEN_NEQ
%left TOKEN_AND TOKEN_OR
%right TOKEN_ASSIGNMENT
%left TOKEN_COMMA
%right TOKEN_ELSE
%error-verbose
%start Program

%%
Program : Body                              {$$}
        ;
Body : /* empty */                              {$$ = null; }
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
        ;
Tails : /* empty */                             //{$$ = null; }
        | Tail Tails                            //{$$ = $1 $2; }
        ;
Tail : TOKEN_DOT TOKEN_INT_LITERAL                   //{$$ = $1 $2; }
     | TOKEN_DOT TOKEN_IDENTIFIER               //{$$ = $1 $2; }
     | TOKEN_LSQUARE Expression TOKEN_RSQUARE   //{$$ = [ $2 ]; }
     | TOKEN_LPAREN Expressions TOKEN_RPAREN    //{$$ = ( $2 ); }//Add support for tuples
     ;
Statement : Assignment                         {$$}
          | Print                              {$$}
          | Return                             {$$}
          | If                                 {$$}
          | Loop                               {$$}
          ;
Assignment : Primary TOKEN_ASSIGNMENT Expression      //{$$ = $1 = $3; }
           ;
Print : TOKEN_PRINT Expressions                 //{$$ = printf("%s", $2); }
      ;
Expressions : Expression                        {$$}
            | Expression TOKEN_COMMA Expressions      //{$$ = $1, $3; }
            ;
Return : TOKEN_RETURN Expression                //{$$ = return $2; }
       | TOKEN_RETURN                           //{$$ = return; }
       ;
If : TOKEN_IF Expression TOKEN_THEN Body        //{$$ = if($2) {$4}; }
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
#include "lex.yy.c"
extern int lineCounter;
int check = 0;
int yyerror(char *s)
{
    printf ("%s on line %d\n", s, lineCounter);
    check = 1;
}

int main(void)
{
    yyparse();
    if ( check == 0 )
    {
        printf ("Input program is valid\n");
    }
}