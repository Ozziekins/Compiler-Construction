%token var
%token equal
%token and
%token or
%token xor
%token if
%token then
%token else
%token end
%token less_or_equal
%token more_or_equal
%token not_equal
%token TOKEN_IDENTIFIER
%token not
%token is
%token readInt
%token readReal
%token readString
%token IntegerLiteral
%token print
%token return

%%
Program : Program Declaration ';'
        | Program Declaration
        ;
Declaration : var TOKEN_IDENTIFIER ';'
            | var TOKEN_IDENTIFIER equal Expression ';'
            | var TOKEN_IDENTIFIER equal Expression
            | var TOKEN_IDENTIFIER
            ;
Expression : Relation
           | Relation and Relation
           | Relation or Relation
           | Relation xor Relation
           ;
Relation : Factor '<' Factor
         | Factor less_or_equal Factor
         | Factor '>' Factor
         | Factor more_or_equal Factor
         | Factor '=' Factor
         | Factor not_equal Factor
         ;
Factor : Term '+' Term Term
       | Term '-' Term Term
       ;
Term : Unary '*' Unary
     | Unary '/' Unary
     ;
Unary : '+' Primary
      | '-' Primary
      | not Primary
      | Literal
      | '(' Expression ')'
      | '+' Primary is TypeIndificator
      | '-' Primary is TypeIndificator
      | not Primary is TypeIndificator
      ;
Primary : TOKEN_IDENTIFIER 
        | TOKEN_IDENTIFIER Tail Tail
        | readInt
        | readReal
        | readString
        ;
Tail : '.' IntegerLiteral
     | '.' TOKEN_IDENTIFIER
     | '[' Expression ']'
     | '(' Expression ')'
     | '(' Expression ',' Expression Expression ')'
     ;
Statement : Assignment
          | Print
          | Return
          | If
          | Loop
          ;
Assignment : Primary equal Expression
           ;
Print : print Expression
      | print Expression ',' Expression
      ;
Return : return Expression
       | return
       ;
If : if  Expression then Body
   | if Expression then Body else Body end
   ;
%%
