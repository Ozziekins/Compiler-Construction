/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_GRAMMAR_TAB_HH_INCLUDED
# define YY_YY_GRAMMAR_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_ASSIGNMENT = 258,        /* TOKEN_ASSIGNMENT  */
    TOKEN_FUNCTOR = 259,           /* TOKEN_FUNCTOR  */
    TOKEN_EOF = 260,               /* TOKEN_EOF  */
    TOKEN_UNKNOWN = 261,           /* TOKEN_UNKNOWN  */
    TOKEN_IDENTIFIER = 262,        /* TOKEN_IDENTIFIER  */
    TOKEN_INT_LITERAL = 263,       /* TOKEN_INT_LITERAL  */
    TOKEN_REAL_LITERAL = 264,      /* TOKEN_REAL_LITERAL  */
    TOKEN_STRING_LITERAL = 265,    /* TOKEN_STRING_LITERAL  */
    TOKEN_TRUE = 266,              /* TOKEN_TRUE  */
    TOKEN_FALSE = 267,             /* TOKEN_FALSE  */
    TOKEN_FUNC = 268,              /* TOKEN_FUNC  */
    TOKEN_END = 269,               /* TOKEN_END  */
    TOKEN_IF = 270,                /* TOKEN_IF  */
    TOKEN_THEN = 271,              /* TOKEN_THEN  */
    TOKEN_ELSE = 272,              /* TOKEN_ELSE  */
    TOKEN_PRINT = 273,             /* TOKEN_PRINT  */
    TOKEN_RETURN = 274,            /* TOKEN_RETURN  */
    TOKEN_LOOP = 275,              /* TOKEN_LOOP  */
    TOKEN_VAR = 276,               /* TOKEN_VAR  */
    TOKEN_WHILE = 277,             /* TOKEN_WHILE  */
    TOKEN_FOR = 278,               /* TOKEN_FOR  */
    TOKEN_IN = 279,                /* TOKEN_IN  */
    TOKEN_AND = 280,               /* TOKEN_AND  */
    TOKEN_OR = 281,                /* TOKEN_OR  */
    TOKEN_XOR = 282,               /* TOKEN_XOR  */
    TOKEN_NOT = 283,               /* TOKEN_NOT  */
    TOKEN_IS = 284,                /* TOKEN_IS  */
    TOKEN_EMPTY = 285,             /* TOKEN_EMPTY  */
    TOKEN_INT = 286,               /* TOKEN_INT  */
    TOKEN_REAL = 287,              /* TOKEN_REAL  */
    TOKEN_BOOL = 288,              /* TOKEN_BOOL  */
    TOKEN_STRING = 289,            /* TOKEN_STRING  */
    TOKEN_ARRAY = 290,             /* TOKEN_ARRAY  */
    TOKEN_TUPLE = 291,             /* TOKEN_TUPLE  */
    TOKEN_LPAREN = 292,            /* TOKEN_LPAREN  */
    TOKEN_RPAREN = 293,            /* TOKEN_RPAREN  */
    TOKEN_LSQUARE = 294,           /* TOKEN_LSQUARE  */
    TOKEN_RSQUARE = 295,           /* TOKEN_RSQUARE  */
    TOKEN_LCURLY = 296,            /* TOKEN_LCURLY  */
    TOKEN_RCURLY = 297,            /* TOKEN_RCURLY  */
    TOKEN_SEMI = 298,              /* TOKEN_SEMI  */
    TOKEN_COMMA = 299,             /* TOKEN_COMMA  */
    TOKEN_DOT = 300,               /* TOKEN_DOT  */
    TOKEN_PLUS = 301,              /* TOKEN_PLUS  */
    TOKEN_MINUS = 302,             /* TOKEN_MINUS  */
    TOKEN_MULT = 303,              /* TOKEN_MULT  */
    TOKEN_DIV = 304,               /* TOKEN_DIV  */
    TOKEN_EQUAL = 305,             /* TOKEN_EQUAL  */
    TOKEN_NEQ = 306,               /* TOKEN_NEQ  */
    TOKEN_LESS = 307,              /* TOKEN_LESS  */
    TOKEN_LEQ = 308,               /* TOKEN_LEQ  */
    TOKEN_GREAT = 309,             /* TOKEN_GREAT  */
    TOKEN_GEQ = 310,               /* TOKEN_GEQ  */
    TOKEN_INCREMENT = 311,         /* TOKEN_INCREMENT  */
    TOKEN_READINT = 312,           /* TOKEN_READINT  */
    TOKEN_READREAL = 313,          /* TOKEN_READREAL  */
    TOKEN_READSTRING = 314         /* TOKEN_READSTRING  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "grammar.yy"

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

#line 145 "grammar.tab.hh"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_HH_INCLUDED  */
