/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 6 "grammar.yy"

    #include "ast_nodes.h"
    #include <fstream>
    #include "Lexer.h"
    #include <sstream>
    #include <iostream>
    int yylex (YYSTYPE *lvalp);
    void yyerror(const char *error);
    NBlock *programBlock;

#line 82 "grammar.tab.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "grammar.tab.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_ASSIGNMENT = 3,           /* TOKEN_ASSIGNMENT  */
  YYSYMBOL_TOKEN_FUNCTOR = 4,              /* TOKEN_FUNCTOR  */
  YYSYMBOL_TOKEN_EOF = 5,                  /* TOKEN_EOF  */
  YYSYMBOL_TOKEN_UNKNOWN = 6,              /* TOKEN_UNKNOWN  */
  YYSYMBOL_TOKEN_IDENTIFIER = 7,           /* TOKEN_IDENTIFIER  */
  YYSYMBOL_TOKEN_INT_LITERAL = 8,          /* TOKEN_INT_LITERAL  */
  YYSYMBOL_TOKEN_REAL_LITERAL = 9,         /* TOKEN_REAL_LITERAL  */
  YYSYMBOL_TOKEN_STRING_LITERAL = 10,      /* TOKEN_STRING_LITERAL  */
  YYSYMBOL_TOKEN_TRUE = 11,                /* TOKEN_TRUE  */
  YYSYMBOL_TOKEN_FALSE = 12,               /* TOKEN_FALSE  */
  YYSYMBOL_TOKEN_FUNC = 13,                /* TOKEN_FUNC  */
  YYSYMBOL_TOKEN_END = 14,                 /* TOKEN_END  */
  YYSYMBOL_TOKEN_IF = 15,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_THEN = 16,                /* TOKEN_THEN  */
  YYSYMBOL_TOKEN_ELSE = 17,                /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_PRINT = 18,               /* TOKEN_PRINT  */
  YYSYMBOL_TOKEN_RETURN = 19,              /* TOKEN_RETURN  */
  YYSYMBOL_TOKEN_LOOP = 20,                /* TOKEN_LOOP  */
  YYSYMBOL_TOKEN_VAR = 21,                 /* TOKEN_VAR  */
  YYSYMBOL_TOKEN_WHILE = 22,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_FOR = 23,                 /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_IN = 24,                  /* TOKEN_IN  */
  YYSYMBOL_TOKEN_AND = 25,                 /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 26,                  /* TOKEN_OR  */
  YYSYMBOL_TOKEN_XOR = 27,                 /* TOKEN_XOR  */
  YYSYMBOL_TOKEN_NOT = 28,                 /* TOKEN_NOT  */
  YYSYMBOL_TOKEN_IS = 29,                  /* TOKEN_IS  */
  YYSYMBOL_TOKEN_EMPTY = 30,               /* TOKEN_EMPTY  */
  YYSYMBOL_TOKEN_INT = 31,                 /* TOKEN_INT  */
  YYSYMBOL_TOKEN_REAL = 32,                /* TOKEN_REAL  */
  YYSYMBOL_TOKEN_BOOL = 33,                /* TOKEN_BOOL  */
  YYSYMBOL_TOKEN_STRING = 34,              /* TOKEN_STRING  */
  YYSYMBOL_TOKEN_ARRAY = 35,               /* TOKEN_ARRAY  */
  YYSYMBOL_TOKEN_TUPLE = 36,               /* TOKEN_TUPLE  */
  YYSYMBOL_TOKEN_LPAREN = 37,              /* TOKEN_LPAREN  */
  YYSYMBOL_TOKEN_RPAREN = 38,              /* TOKEN_RPAREN  */
  YYSYMBOL_TOKEN_LSQUARE = 39,             /* TOKEN_LSQUARE  */
  YYSYMBOL_TOKEN_RSQUARE = 40,             /* TOKEN_RSQUARE  */
  YYSYMBOL_TOKEN_LCURLY = 41,              /* TOKEN_LCURLY  */
  YYSYMBOL_TOKEN_RCURLY = 42,              /* TOKEN_RCURLY  */
  YYSYMBOL_TOKEN_SEMI = 43,                /* TOKEN_SEMI  */
  YYSYMBOL_TOKEN_COMMA = 44,               /* TOKEN_COMMA  */
  YYSYMBOL_TOKEN_DOT = 45,                 /* TOKEN_DOT  */
  YYSYMBOL_TOKEN_PLUS = 46,                /* TOKEN_PLUS  */
  YYSYMBOL_TOKEN_MINUS = 47,               /* TOKEN_MINUS  */
  YYSYMBOL_TOKEN_MULT = 48,                /* TOKEN_MULT  */
  YYSYMBOL_TOKEN_DIV = 49,                 /* TOKEN_DIV  */
  YYSYMBOL_TOKEN_EQUAL = 50,               /* TOKEN_EQUAL  */
  YYSYMBOL_TOKEN_NEQ = 51,                 /* TOKEN_NEQ  */
  YYSYMBOL_TOKEN_LESS = 52,                /* TOKEN_LESS  */
  YYSYMBOL_TOKEN_LEQ = 53,                 /* TOKEN_LEQ  */
  YYSYMBOL_TOKEN_GREAT = 54,               /* TOKEN_GREAT  */
  YYSYMBOL_TOKEN_GEQ = 55,                 /* TOKEN_GEQ  */
  YYSYMBOL_TOKEN_INCREMENT = 56,           /* TOKEN_INCREMENT  */
  YYSYMBOL_TOKEN_READINT = 57,             /* TOKEN_READINT  */
  YYSYMBOL_TOKEN_READREAL = 58,            /* TOKEN_READREAL  */
  YYSYMBOL_TOKEN_READSTRING = 59,          /* TOKEN_READSTRING  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_Program = 61,                   /* Program  */
  YYSYMBOL_Body = 62,                      /* Body  */
  YYSYMBOL_ProgramBody = 63,               /* ProgramBody  */
  YYSYMBOL_Declaration = 64,               /* Declaration  */
  YYSYMBOL_Expression = 65,                /* Expression  */
  YYSYMBOL_Relation = 66,                  /* Relation  */
  YYSYMBOL_Factor = 67,                    /* Factor  */
  YYSYMBOL_Term = 68,                      /* Term  */
  YYSYMBOL_Unary = 69,                     /* Unary  */
  YYSYMBOL_Primary = 70,                   /* Primary  */
  YYSYMBOL_Tail = 71,                      /* Tail  */
  YYSYMBOL_Statement = 72,                 /* Statement  */
  YYSYMBOL_Assignment = 73,                /* Assignment  */
  YYSYMBOL_Print = 74,                     /* Print  */
  YYSYMBOL_Expressions = 75,               /* Expressions  */
  YYSYMBOL_Return = 76,                    /* Return  */
  YYSYMBOL_If = 77,                        /* If  */
  YYSYMBOL_Loop = 78,                      /* Loop  */
  YYSYMBOL_LoopBody = 79,                  /* LoopBody  */
  YYSYMBOL_TypeIndicator = 80,             /* TypeIndicator  */
  YYSYMBOL_Literal = 81,                   /* Literal  */
  YYSYMBOL_ArrayLiteral = 82,              /* ArrayLiteral  */
  YYSYMBOL_TupleLiteral = 83,              /* TupleLiteral  */
  YYSYMBOL_TupleTail = 84,                 /* TupleTail  */
  YYSYMBOL_FunctionLiteral = 85,           /* FunctionLiteral  */
  YYSYMBOL_Parameters = 86,                /* Parameters  */
  YYSYMBOL_Identifiers = 87                /* Identifiers  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
# define YYCOPY_NEEDED 1
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  54
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   212

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    93,    93,    95,    96,    97,    99,   100,   101,   103,
     104,   106,   107,   108,   109,   111,   112,   113,   114,   115,
     116,   117,   119,   120,   121,   123,   124,   125,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   138,   139,
     140,   141,   143,   144,   145,   146,   147,   149,   150,   151,
     152,   153,   155,   157,   159,   160,   162,   163,   165,   166,
     168,   169,   171,   173,   174,   175,   176,   177,   178,   179,
     181,   182,   183,   184,   185,   186,   187,   188,   190,   191,
     193,   194,   195,   197,   198,   199,   201,   202,   203,   204,
     206,   208,   209
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_ASSIGNMENT",
  "TOKEN_FUNCTOR", "TOKEN_EOF", "TOKEN_UNKNOWN", "TOKEN_IDENTIFIER",
  "TOKEN_INT_LITERAL", "TOKEN_REAL_LITERAL", "TOKEN_STRING_LITERAL",
  "TOKEN_TRUE", "TOKEN_FALSE", "TOKEN_FUNC", "TOKEN_END", "TOKEN_IF",
  "TOKEN_THEN", "TOKEN_ELSE", "TOKEN_PRINT", "TOKEN_RETURN", "TOKEN_LOOP",
  "TOKEN_VAR", "TOKEN_WHILE", "TOKEN_FOR", "TOKEN_IN", "TOKEN_AND",
  "TOKEN_OR", "TOKEN_XOR", "TOKEN_NOT", "TOKEN_IS", "TOKEN_EMPTY",
  "TOKEN_INT", "TOKEN_REAL", "TOKEN_BOOL", "TOKEN_STRING", "TOKEN_ARRAY",
  "TOKEN_TUPLE", "TOKEN_LPAREN", "TOKEN_RPAREN", "TOKEN_LSQUARE",
  "TOKEN_RSQUARE", "TOKEN_LCURLY", "TOKEN_RCURLY", "TOKEN_SEMI",
  "TOKEN_COMMA", "TOKEN_DOT", "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_MULT",
  "TOKEN_DIV", "TOKEN_EQUAL", "TOKEN_NEQ", "TOKEN_LESS", "TOKEN_LEQ",
  "TOKEN_GREAT", "TOKEN_GEQ", "TOKEN_INCREMENT", "TOKEN_READINT",
  "TOKEN_READREAL", "TOKEN_READSTRING", "$accept", "Program", "Body",
  "ProgramBody", "Declaration", "Expression", "Relation", "Factor", "Term",
  "Unary", "Primary", "Tail", "Statement", "Assignment", "Print",
  "Expressions", "Return", "If", "Loop", "LoopBody", "TypeIndicator",
  "Literal", "ArrayLiteral", "TupleLiteral", "TupleTail",
  "FunctionLiteral", "Parameters", "Identifiers", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
#endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     153,   -26,   120,   120,    37,    10,   120,    14,   -76,   -76,
     -76,     5,   -76,   153,    31,   153,   -76,   -76,   -76,   -76,
     -76,   120,   120,    32,   -76,   -76,   -76,   -76,   -76,   -76,
      71,     2,   120,   106,    -1,     2,     2,    12,    63,   130,
     103,   107,    42,   -76,   -76,   -76,   -76,    41,    38,   -76,
      62,    26,    35,    74,   -76,   -76,   153,   153,   120,   -76,
      69,    72,   -76,   -76,   120,   153,   102,     4,   115,   113,
     -76,   114,    28,   -76,   144,   157,   153,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
      90,   120,   -76,   -76,   120,   -76,   153,   -76,    90,   -76,
     -76,   145,   -76,   -76,   -76,   173,   146,   151,   120,   153,
      90,   -76,   -76,   120,   -76,   184,   -76,    90,    90,    65,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   149,   179,    35,   -76,   -76,   102,   -76,   -76,
     180,   -76,   -17,    49,   -76,   -76,   -76,   153,   -76,   -76,
     -76,   -76,   -76,   -76,   120,   -76,   181,   -17,   -76,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    42,     0,     0,     0,     0,     0,     0,    39,    40,
      41,     0,     2,     6,     0,     6,    47,    48,    49,    50,
      51,     0,     0,     0,    38,    70,    71,    74,    72,    73,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    15,
      22,    25,    28,    32,    75,    76,    77,    54,     0,    57,
       0,     0,     0,     0,     1,     4,     6,     6,     0,     5,
       0,     0,    44,    43,     0,     3,     0,     0,    31,     0,
      78,     0,     0,    80,    29,    30,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    56,     0,     9,     3,    60,     0,     7,
       8,     0,    46,    45,    87,     0,    91,     0,     0,     3,
       0,    33,    79,     0,    83,     0,    81,     0,     0,     0,
      12,    13,    14,    20,    21,    16,    17,    18,    19,    23,
      24,    26,    27,    67,    63,    64,    65,    66,    68,    69,
      37,    55,     0,     0,     0,    52,    86,     0,    90,    89,
       0,    36,     0,     0,    34,    35,    58,     3,    10,    62,
      61,    92,    88,    82,     0,    84,     0,     0,    59,    85
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,   -58,     7,    -3,    -2,    25,    55,    81,   -76,
       1,   -76,    11,   -76,   -76,   -18,   -76,   -76,   -76,    52,
     -75,   -76,   -76,   -76,   -66,   -76,   -76,    50
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    55,    13,    47,    38,    39,    40,    41,
      42,    24,    15,    16,    17,    48,    18,    19,    20,    97,
     140,    43,    44,    45,   116,    46,    67,   107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      37,    14,    50,    60,    52,    54,    72,   105,   108,     1,
      56,    21,    56,    22,    14,    71,    14,    51,   119,    23,
      61,    53,    59,   144,    57,   114,    57,   115,    76,    94,
      69,   113,    68,   109,    58,   151,    74,    75,   143,    62,
      63,    73,   154,   155,     1,    25,    26,    27,    28,    29,
      30,   150,   164,    56,    56,    96,   101,    14,    14,     8,
       9,    10,   104,    99,   100,    31,    14,    57,    57,    95,
     114,    90,   115,   141,    32,    64,    33,    14,    34,   156,
      49,    92,   157,    35,    36,    91,   163,   165,    77,    78,
      79,   114,   142,   115,     8,     9,    10,    14,    98,   166,
      65,   169,   120,   121,   122,    93,   149,   102,    66,   106,
      14,   152,   103,     1,    25,    26,    27,    28,    29,    30,
     133,   134,   135,   136,   137,   138,   139,     1,    25,    26,
      27,    28,    29,    30,    31,   123,   124,   125,   126,   127,
     128,   129,   130,    32,   110,    33,    70,    34,    31,    86,
      87,   111,    35,    36,   112,    88,    89,    32,    14,    33,
       1,    34,   167,     8,     9,    10,    35,    36,     2,   131,
     132,     3,     4,   117,     5,     6,     7,     8,     9,    10,
      80,    81,    82,    83,    84,    85,   118,   146,   145,   148,
     147,   153,   158,   159,   162,   168,   160,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     9,    10
};

static const yytype_int16 yycheck[] =
{
       2,     0,     4,    21,     6,     0,     7,    65,     4,     7,
      13,    37,    15,    39,    13,    33,    15,     7,    76,    45,
      22,     7,    15,    98,    13,    42,    15,    44,    16,     3,
      32,     3,    31,    29,     3,   110,    35,    36,    96,     7,
       8,    42,   117,   118,     7,     8,     9,    10,    11,    12,
      13,   109,     3,    56,    57,    20,    58,    56,    57,    57,
      58,    59,    64,    56,    57,    28,    65,    56,    57,    43,
      42,    29,    44,    91,    37,     4,    39,    76,    41,    14,
      43,    43,    17,    46,    47,    44,   152,   153,    25,    26,
      27,    42,    94,    44,    57,    58,    59,    96,    24,   157,
      29,   167,    77,    78,    79,    43,   108,    38,    37,     7,
     109,   113,    40,     7,     8,     9,    10,    11,    12,    13,
      30,    31,    32,    33,    34,    35,    36,     7,     8,     9,
      10,    11,    12,    13,    28,    80,    81,    82,    83,    84,
      85,    86,    87,    37,    29,    39,    40,    41,    28,    46,
      47,    38,    46,    47,    40,    48,    49,    37,   157,    39,
       7,    41,   164,    57,    58,    59,    46,    47,    15,    88,
      89,    18,    19,    29,    21,    22,    23,    57,    58,    59,
      50,    51,    52,    53,    54,    55,    29,    14,    43,    38,
      44,     7,    43,    14,    14,    14,   144,   147,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    15,    18,    19,    21,    22,    23,    57,    58,
      59,    61,    62,    64,    70,    72,    73,    74,    76,    77,
      78,    37,    39,    45,    71,     8,     9,    10,    11,    12,
      13,    28,    37,    39,    41,    46,    47,    65,    66,    67,
      68,    69,    70,    81,    82,    83,    85,    65,    75,    43,
      65,     7,    65,     7,     0,    63,    64,    72,     3,    63,
      75,    65,     7,     8,     4,    29,    37,    86,    70,    65,
      40,    75,     7,    42,    70,    70,    16,    25,    26,    27,
      50,    51,    52,    53,    54,    55,    46,    47,    48,    49,
      29,    44,    43,    43,     3,    43,    20,    79,    24,    63,
      63,    65,    38,    40,    65,    62,     7,    87,     4,    29,
      29,    38,    40,     3,    42,    44,    84,    29,    29,    62,
      66,    66,    66,    67,    67,    67,    67,    67,    67,    67,
      67,    68,    68,    30,    31,    32,    33,    34,    35,    36,
      80,    75,    65,    62,    80,    43,    14,    44,    38,    65,
      62,    80,    65,     7,    80,    80,    14,    17,    43,    14,
      79,    87,    14,    84,     3,    84,    62,    65,    14,    84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    62,    62,    62,    63,    63,    63,    64,
      64,    65,    65,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    67,    67,    67,    68,    68,    68,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    70,    70,
      70,    70,    71,    71,    71,    71,    71,    72,    72,    72,
      72,    72,    73,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    79,    80,    80,    80,    80,    80,    80,    80,
      81,    81,    81,    81,    81,    81,    81,    81,    82,    82,
      83,    83,    83,    84,    84,    84,    85,    85,    85,    85,
      86,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     0,     2,     2,     3,
       5,     1,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     2,
       2,     2,     1,     3,     4,     4,     4,     3,     2,     1,
       1,     1,     0,     2,     2,     3,     3,     1,     1,     1,
       1,     1,     4,     3,     1,     3,     3,     2,     5,     7,
       3,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       2,     3,     5,     1,     3,     5,     4,     3,     5,     4,
       3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        YY_LAC_DISCARD ("YYBACKUP");                              \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return YYENOMEM if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yy_state_t **yybottom,
                      yy_state_t *yybottom_no_free,
                      yy_state_t **yytop, yy_state_t *yytop_empty)
{
  YYPTRDIFF_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYPTRDIFF_T yyalloc = 2 * yysize_new;
      yy_state_t *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        YY_CAST (yy_state_t *,
                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
                                         yyalloc * YYSIZEOF (*yybottom_new))));
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                                \
do {                                                                    \
  if (!yy_lac_established)                                              \
    {                                                                   \
      YYDPRINTF ((stderr,                                               \
                  "LAC: initial context established for %s\n",          \
                  yysymbol_name (yytoken)));                            \
      yy_lac_established = 1;                                           \
      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
        {                                                               \
        case YYENOMEM:                                                  \
          goto yyexhaustedlab;                                          \
        case 1:                                                         \
          goto yyerrlab;                                                \
        }                                                               \
    }                                                                   \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      YYDPRINTF ((stderr, "LAC: initial context discarded due to "       \
                  Event "\n"));                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return YYENOMEM if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  /* Reduce until we encounter a shift and thereby accept the token.  */
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
  if (yytoken == YYSYMBOL_YYUNDEF)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[+*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          /* Use the default action.  */
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          /* Use the action from yytable.  */
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      /* By now we know we have to simulate a reduce.  */
      YYDPRINTF ((stderr, " R%d", yyrule - 1));
      {
        /* Pop the corresponding number of values from the stack.  */
        YYPTRDIFF_T yylen = yyr2[yyrule];
        /* First pop from the LAC stack as many tokens as possible.  */
        if (yyesp != yyes_prev)
          {
            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yyesp = yyes_prev;
                yylen -= yysize;
              }
          }
        /* Only afterwards look at the main stack.  */
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      /* Push the resulting state of the reduction.  */
      {
        yy_state_fast_t yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                     ? yytable[yyi]
                     : yydefgoto[yylhs]);
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            YY_IGNORE_USELESS_CAST_BEGIN
            *yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return YYENOMEM;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}

/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yy_state_t *yyesa;
  yy_state_t **yyes;
  YYPTRDIFF_T *yyes_capacity;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;

  int yyx;
  for (yyx = 0; yyx < YYNTOKENS; ++yyx)
    {
      yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
      if (yysym != YYSYMBOL_YYerror && yysym != YYSYMBOL_YYUNDEF)
        switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
          {
          case YYENOMEM:
            return YYENOMEM;
          case 1:
            continue;
          default:
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else if (yyn == 0)
        YYDPRINTF ((stderr, "No expected tokens.\n"));
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store or if
   yy_lac returned YYENOMEM.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    yy_state_t yyesa[20];
    yy_state_t *yyes = yyesa;
    YYPTRDIFF_T yyes_capacity = 20 < YYMAXDEPTH ? 20 : YYMAXDEPTH;

  /* Whether LAC context is established.  A Boolean.  */
  int yy_lac_established = 0;
  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 2: /* Program: Body  */
#line 93 "grammar.yy"
                                                                 { programBlock = (yyvsp[0].block); }
#line 1799 "grammar.tab.cc"
    break;

  case 3: /* Body: %empty  */
#line 95 "grammar.yy"
                                                                 { (yyval.block) = NULL; }
#line 1805 "grammar.tab.cc"
    break;

  case 4: /* Body: Declaration ProgramBody  */
#line 96 "grammar.yy"
                                                                 { (yyval.block) = new NBlock(); (yyval.block)->declarations.push_back((yyvsp[-1].declaration)); }
#line 1811 "grammar.tab.cc"
    break;

  case 5: /* Body: Statement ProgramBody  */
#line 97 "grammar.yy"
                                                                 { (yyval.block) = new NBlock(); (yyval.block)->statements.push_back((yyvsp[-1].statement)); }
#line 1817 "grammar.tab.cc"
    break;

  case 6: /* ProgramBody: %empty  */
#line 99 "grammar.yy"
                                                                 { (yyval.block) = NULL; }
#line 1823 "grammar.tab.cc"
    break;

  case 7: /* ProgramBody: Declaration ProgramBody  */
#line 100 "grammar.yy"
                                                                 { (yyval.block)->declarations.push_back((yyvsp[-1].declaration)); }
#line 1829 "grammar.tab.cc"
    break;

  case 8: /* ProgramBody: Statement ProgramBody  */
#line 101 "grammar.yy"
                                                                 { (yyval.block)->statements.push_back((yyvsp[-1].statement)); }
#line 1835 "grammar.tab.cc"
    break;

  case 9: /* Declaration: TOKEN_VAR TOKEN_IDENTIFIER TOKEN_SEMI  */
#line 103 "grammar.yy"
                                                                                          { (yyval.declaration) = new NDeclaration(*(yyvsp[-1].string)); }
#line 1841 "grammar.tab.cc"
    break;

  case 10: /* Declaration: TOKEN_VAR TOKEN_IDENTIFIER TOKEN_ASSIGNMENT Expression TOKEN_SEMI  */
#line 104 "grammar.yy"
                                                                                          { (yyval.declaration) = new NDeclaration(*(yyvsp[-3].string), (yyvsp[-1].expression)); }
#line 1847 "grammar.tab.cc"
    break;

  case 11: /* Expression: Relation  */
#line 106 "grammar.yy"
                                                          { (yyval.expression) = (yyvsp[0].expression); }
#line 1853 "grammar.tab.cc"
    break;

  case 12: /* Expression: Relation TOKEN_AND Relation  */
#line 107 "grammar.yy"
                                                          { (yyval.expression) = new NBinaryOperator(*(yyvsp[-2].expression), (yyvsp[-1].token), *(yyvsp[0].expression)); }
#line 1859 "grammar.tab.cc"
    break;

  case 13: /* Expression: Relation TOKEN_OR Relation  */
#line 108 "grammar.yy"
                                                          { (yyval.expression) = new NBinaryOperator(*(yyvsp[-2].expression), (yyvsp[-1].token), *(yyvsp[0].expression)); }
#line 1865 "grammar.tab.cc"
    break;

  case 14: /* Expression: Relation TOKEN_XOR Relation  */
#line 109 "grammar.yy"
                                                          { (yyval.expression) = new NBinaryOperator(*(yyvsp[-2].expression), (yyvsp[-1].token), *(yyvsp[0].expression)); }
#line 1871 "grammar.tab.cc"
    break;

  case 15: /* Relation: Factor  */
#line 111 "grammar.yy"
                                                          { (yyval.expression) = (yyvsp[0].expression); }
#line 1877 "grammar.tab.cc"
    break;

  case 16: /* Relation: Factor TOKEN_LESS Factor  */
#line 112 "grammar.yy"
                                                          { (yyval.expression) = new NBinaryOperator(*(yyvsp[-2].expression), (yyvsp[-1].token), *(yyvsp[0].expression)); }
#line 1883 "grammar.tab.cc"
    break;

  case 17: /* Relation: Factor TOKEN_LEQ Factor  */
#line 113 "grammar.yy"
                                                          { (yyval.expression) = new NBinaryOperator(*(yyvsp[-2].expression), (yyvsp[-1].token), *(yyvsp[0].expression)); }
#line 1889 "grammar.tab.cc"
    break;

  case 18: /* Relation: Factor TOKEN_GREAT Factor  */
#line 114 "grammar.yy"
                                                          { (yyval.expression) = new NBinaryOperator(*(yyvsp[-2].expression), (yyvsp[-1].token), *(yyvsp[0].expression)); }
#line 1895 "grammar.tab.cc"
    break;

  case 19: /* Relation: Factor TOKEN_GEQ Factor  */
#line 115 "grammar.yy"
                                                          { (yyval.expression) = new NBinaryOperator(*(yyvsp[-2].expression), (yyvsp[-1].token), *(yyvsp[0].expression)); }
#line 1901 "grammar.tab.cc"
    break;

  case 20: /* Relation: Factor TOKEN_EQUAL Factor  */
#line 116 "grammar.yy"
                                                          { (yyval.expression) = new NBinaryOperator(*(yyvsp[-2].expression), (yyvsp[-1].token), *(yyvsp[0].expression)); }
#line 1907 "grammar.tab.cc"
    break;

  case 21: /* Relation: Factor TOKEN_NEQ Factor  */
#line 117 "grammar.yy"
                                                          { (yyval.expression) = new NBinaryOperator(*(yyvsp[-2].expression), (yyvsp[-1].token), *(yyvsp[0].expression)); }
#line 1913 "grammar.tab.cc"
    break;

  case 22: /* Factor: Term  */
#line 119 "grammar.yy"
                                                          { (yyval.expression) = (yyvsp[0].expression); }
#line 1919 "grammar.tab.cc"
    break;

  case 23: /* Factor: Term TOKEN_PLUS Factor  */
#line 120 "grammar.yy"
                                                          { (yyval.expression) = new NBinaryOperator(*(yyvsp[-2].expression), (yyvsp[-1].token), *(yyvsp[0].expression)); }
#line 1925 "grammar.tab.cc"
    break;

  case 24: /* Factor: Term TOKEN_MINUS Factor  */
#line 121 "grammar.yy"
                                                          { (yyval.expression) = new NBinaryOperator(*(yyvsp[-2].expression), (yyvsp[-1].token), *(yyvsp[0].expression)); }
#line 1931 "grammar.tab.cc"
    break;

  case 25: /* Term: Unary  */
#line 123 "grammar.yy"
                                                          { (yyval.expression) = (yyvsp[0].expression); }
#line 1937 "grammar.tab.cc"
    break;

  case 26: /* Term: Unary TOKEN_MULT Term  */
#line 124 "grammar.yy"
                                                          { (yyval.expression) = new NBinaryOperator(*(yyvsp[-2].expression), (yyvsp[-1].token), *(yyvsp[0].expression)); }
#line 1943 "grammar.tab.cc"
    break;

  case 27: /* Term: Unary TOKEN_DIV Term  */
#line 125 "grammar.yy"
                                                          { (yyval.expression) = new NBinaryOperator(*(yyvsp[-2].expression), (yyvsp[-1].token), *(yyvsp[0].expression)); }
#line 1949 "grammar.tab.cc"
    break;

  case 28: /* Unary: Primary  */
#line 127 "grammar.yy"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 1955 "grammar.tab.cc"
    break;

  case 29: /* Unary: TOKEN_PLUS Primary  */
#line 128 "grammar.yy"
                                                { (yyval.expression) = new NUnary((yyvsp[-1].token), *(yyvsp[0].expression)); }
#line 1961 "grammar.tab.cc"
    break;

  case 30: /* Unary: TOKEN_MINUS Primary  */
#line 129 "grammar.yy"
                                                { (yyval.expression) = new NUnary((yyvsp[-1].token), *(yyvsp[0].expression)); }
#line 1967 "grammar.tab.cc"
    break;

  case 31: /* Unary: TOKEN_NOT Primary  */
#line 130 "grammar.yy"
                                                { (yyval.expression) = new NUnary((yyvsp[-1].token), *(yyvsp[0].expression)); }
#line 1973 "grammar.tab.cc"
    break;

  case 32: /* Unary: Literal  */
#line 131 "grammar.yy"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 1979 "grammar.tab.cc"
    break;

  case 33: /* Unary: TOKEN_LPAREN Expression TOKEN_RPAREN  */
#line 132 "grammar.yy"
                                                { (yyval.expression) = (yyvsp[-1].expression); }
#line 1985 "grammar.tab.cc"
    break;

  case 34: /* Unary: TOKEN_PLUS Primary TOKEN_IS TypeIndicator  */
#line 133 "grammar.yy"
                                                            { (yyval.expression) = new NTypeCheck((yyvsp[-3].token), *(yyvsp[-2].expression), *(yyvsp[0].string)); }
#line 1991 "grammar.tab.cc"
    break;

  case 35: /* Unary: TOKEN_MINUS Primary TOKEN_IS TypeIndicator  */
#line 134 "grammar.yy"
                                                            { (yyval.expression) = new NTypeCheck((yyvsp[-3].token), *(yyvsp[-2].expression), *(yyvsp[0].string)); }
#line 1997 "grammar.tab.cc"
    break;

  case 36: /* Unary: TOKEN_NOT Primary TOKEN_IS TypeIndicator  */
#line 135 "grammar.yy"
                                                            { (yyval.expression) = new NTypeCheck((yyvsp[-3].token), *(yyvsp[-2].expression), *(yyvsp[0].string)); }
#line 2003 "grammar.tab.cc"
    break;

  case 37: /* Unary: Primary TOKEN_IS TypeIndicator  */
#line 136 "grammar.yy"
                                                            { (yyval.expression) = new NTypeCheck(*(yyvsp[-2].expression), *(yyvsp[0].string)); }
#line 2009 "grammar.tab.cc"
    break;

  case 38: /* Primary: TOKEN_IDENTIFIER Tail  */
#line 138 "grammar.yy"
                                                            { (yyval.expression) = new NIdentifier(*(yyvsp[-1].string)); }
#line 2015 "grammar.tab.cc"
    break;

  case 39: /* Primary: TOKEN_READINT  */
#line 139 "grammar.yy"
                                                            { (yyval.expression) = new NReadInput(); }
#line 2021 "grammar.tab.cc"
    break;

  case 40: /* Primary: TOKEN_READREAL  */
#line 140 "grammar.yy"
                                                            { (yyval.expression) = new NReadInput(); }
#line 2027 "grammar.tab.cc"
    break;

  case 41: /* Primary: TOKEN_READSTRING  */
#line 141 "grammar.yy"
                                                            { (yyval.expression) = new NReadInput(); }
#line 2033 "grammar.tab.cc"
    break;

  case 52: /* Assignment: Primary TOKEN_ASSIGNMENT Expression TOKEN_SEMI  */
#line 155 "grammar.yy"
                                                              { (yyval.statement) = new NAssignment(*(yyvsp[-3].expression), *(yyvsp[-1].expression)); }
#line 2039 "grammar.tab.cc"
    break;

  case 53: /* Print: TOKEN_PRINT Expressions TOKEN_SEMI  */
#line 157 "grammar.yy"
                                                              { (yyval.statement) = new NPrint(*(yyvsp[-1].expressionVector)); }
#line 2045 "grammar.tab.cc"
    break;

  case 54: /* Expressions: Expression  */
#line 159 "grammar.yy"
                                                              { (yyvsp[0].expression) = new NExpression(); (yyval.expressionVector)->push_back((yyvsp[0].expression)); }
#line 2051 "grammar.tab.cc"
    break;

  case 55: /* Expressions: Expression TOKEN_COMMA Expressions  */
#line 160 "grammar.yy"
                                                              { (yyvsp[0].expressionVector)->push_back((yyvsp[-2].expression)); }
#line 2057 "grammar.tab.cc"
    break;

  case 56: /* Return: TOKEN_RETURN Expression TOKEN_SEMI  */
#line 162 "grammar.yy"
                                                              { (yyval.statement) = new NReturn(*(yyvsp[-1].expression)); }
#line 2063 "grammar.tab.cc"
    break;

  case 57: /* Return: TOKEN_RETURN TOKEN_SEMI  */
#line 163 "grammar.yy"
                                                              { (yyval.statement) = new NReturn(); }
#line 2069 "grammar.tab.cc"
    break;

  case 58: /* If: TOKEN_IF Expression TOKEN_THEN Body TOKEN_END  */
#line 165 "grammar.yy"
                                                              { (yyval.statement) = new NIf(*(yyvsp[-3].expression), *(yyvsp[-1].block)); }
#line 2075 "grammar.tab.cc"
    break;

  case 59: /* If: TOKEN_IF Expression TOKEN_THEN Body TOKEN_ELSE Body TOKEN_END  */
#line 166 "grammar.yy"
                                                                        { (yyval.statement) = new NIf(*(yyvsp[-5].expression), *(yyvsp[-3].block), *(yyvsp[-1].block)); }
#line 2081 "grammar.tab.cc"
    break;

  case 60: /* Loop: TOKEN_WHILE Expression LoopBody  */
#line 168 "grammar.yy"
                                                              { (yyval.statement) = new NLoop(*(yyvsp[-1].expression), *(yyvsp[0].block)); }
#line 2087 "grammar.tab.cc"
    break;

  case 61: /* Loop: TOKEN_FOR TOKEN_IDENTIFIER TOKEN_IN TypeIndicator LoopBody  */
#line 169 "grammar.yy"
                                                                              { (yyval.statement) = NULL; }
#line 2093 "grammar.tab.cc"
    break;

  case 62: /* LoopBody: TOKEN_LOOP Body TOKEN_END  */
#line 171 "grammar.yy"
                                                              { (yyval.block) = (yyvsp[-1].block); }
#line 2099 "grammar.tab.cc"
    break;

  case 63: /* TypeIndicator: TOKEN_INT  */
#line 173 "grammar.yy"
                                                              { (yyval.string) = (yyvsp[0].string); }
#line 2105 "grammar.tab.cc"
    break;

  case 64: /* TypeIndicator: TOKEN_REAL  */
#line 174 "grammar.yy"
                                                              { (yyval.string) = (yyvsp[0].string); }
#line 2111 "grammar.tab.cc"
    break;

  case 65: /* TypeIndicator: TOKEN_BOOL  */
#line 175 "grammar.yy"
                                                              { (yyval.string) = (yyvsp[0].string); }
#line 2117 "grammar.tab.cc"
    break;

  case 66: /* TypeIndicator: TOKEN_STRING  */
#line 176 "grammar.yy"
                                                              { (yyval.string) = (yyvsp[0].string); }
#line 2123 "grammar.tab.cc"
    break;

  case 67: /* TypeIndicator: TOKEN_EMPTY  */
#line 177 "grammar.yy"
                                                              { (yyval.string) = (yyvsp[0].string); }
#line 2129 "grammar.tab.cc"
    break;

  case 68: /* TypeIndicator: TOKEN_ARRAY  */
#line 178 "grammar.yy"
                                                              { (yyval.string) = (yyvsp[0].string); }
#line 2135 "grammar.tab.cc"
    break;

  case 69: /* TypeIndicator: TOKEN_TUPLE  */
#line 179 "grammar.yy"
                                                              { (yyval.string) = (yyvsp[0].string); }
#line 2141 "grammar.tab.cc"
    break;

  case 70: /* Literal: TOKEN_INT_LITERAL  */
#line 181 "grammar.yy"
                                                              { (yyval.expression) = new NInteger(atol((yyvsp[0].string)->c_str())); }
#line 2147 "grammar.tab.cc"
    break;

  case 71: /* Literal: TOKEN_REAL_LITERAL  */
#line 182 "grammar.yy"
                                                              { (yyval.expression) = new NReal(atof((yyvsp[0].string)->c_str())); }
#line 2153 "grammar.tab.cc"
    break;

  case 72: /* Literal: TOKEN_TRUE  */
#line 183 "grammar.yy"
                                                              { (yyval.expression) = new NBool(*(yyvsp[0].string)); }
#line 2159 "grammar.tab.cc"
    break;

  case 73: /* Literal: TOKEN_FALSE  */
#line 184 "grammar.yy"
                                                              { (yyval.expression) = new NBool(*(yyvsp[0].string)); }
#line 2165 "grammar.tab.cc"
    break;

  case 74: /* Literal: TOKEN_STRING_LITERAL  */
#line 185 "grammar.yy"
                                                              { (yyval.expression) = new NString(*(yyvsp[0].string)); }
#line 2171 "grammar.tab.cc"
    break;

  case 75: /* Literal: ArrayLiteral  */
#line 186 "grammar.yy"
                                                              { (yyval.expression) = NULL; }
#line 2177 "grammar.tab.cc"
    break;

  case 76: /* Literal: TupleLiteral  */
#line 187 "grammar.yy"
                                                              { (yyval.expression) = NULL; }
#line 2183 "grammar.tab.cc"
    break;

  case 77: /* Literal: FunctionLiteral  */
#line 188 "grammar.yy"
                                                              { (yyval.expression) = NULL; }
#line 2189 "grammar.tab.cc"
    break;

  case 78: /* ArrayLiteral: TOKEN_LSQUARE TOKEN_RSQUARE  */
#line 190 "grammar.yy"
                                                              { (yyval.expression) = new NArray(); }
#line 2195 "grammar.tab.cc"
    break;

  case 79: /* ArrayLiteral: TOKEN_LSQUARE Expressions TOKEN_RSQUARE  */
#line 191 "grammar.yy"
                                                              { (yyval.expression) = new NArray(); }
#line 2201 "grammar.tab.cc"
    break;

  case 80: /* TupleLiteral: TOKEN_LCURLY TOKEN_RCURLY  */
#line 193 "grammar.yy"
                                                              { (yyval.expression) = new NTuple(); }
#line 2207 "grammar.tab.cc"
    break;

  case 81: /* TupleLiteral: TOKEN_LCURLY TOKEN_IDENTIFIER TupleTail  */
#line 194 "grammar.yy"
                                                              { (yyval.expression) = new NTuple(); }
#line 2213 "grammar.tab.cc"
    break;

  case 82: /* TupleLiteral: TOKEN_LCURLY TOKEN_IDENTIFIER TOKEN_ASSIGNMENT Expression TupleTail  */
#line 195 "grammar.yy"
                                                                                        { (yyval.expression) = new NTuple(); }
#line 2219 "grammar.tab.cc"
    break;

  case 86: /* FunctionLiteral: TOKEN_FUNC TOKEN_IS Body TOKEN_END  */
#line 201 "grammar.yy"
                                                                              { (yyval.expression) = new NFunctionDefinition(*(yyvsp[-1].block)); }
#line 2225 "grammar.tab.cc"
    break;

  case 87: /* FunctionLiteral: TOKEN_FUNC TOKEN_FUNCTOR Expression  */
#line 202 "grammar.yy"
                                                                              { (yyval.expression) = new NFunctionDefinition(*(yyvsp[0].expression)); }
#line 2231 "grammar.tab.cc"
    break;

  case 88: /* FunctionLiteral: TOKEN_FUNC Parameters TOKEN_IS Body TOKEN_END  */
#line 203 "grammar.yy"
                                                                              { (yyval.expression) = new NFunctionDefinition(*(yyvsp[-3].paramVector), *(yyvsp[-1].block)); }
#line 2237 "grammar.tab.cc"
    break;

  case 89: /* FunctionLiteral: TOKEN_FUNC Parameters TOKEN_FUNCTOR Expression  */
#line 204 "grammar.yy"
                                                                              { (yyval.expression) = new NFunctionDefinition(*(yyvsp[-2].paramVector), *(yyvsp[0].expression)); }
#line 2243 "grammar.tab.cc"
    break;

  case 90: /* Parameters: TOKEN_LPAREN Identifiers TOKEN_RPAREN  */
#line 206 "grammar.yy"
                                                                              { (yyval.paramVector) = (yyvsp[-1].paramVector); }
#line 2249 "grammar.tab.cc"
    break;

  case 91: /* Identifiers: TOKEN_IDENTIFIER  */
#line 208 "grammar.yy"
                                                                              { (yyval.paramVector)->push_back(new NIdentifier(*(yyvsp[0].string))); }
#line 2255 "grammar.tab.cc"
    break;

  case 92: /* Identifiers: TOKEN_IDENTIFIER TOKEN_COMMA Identifiers  */
#line 209 "grammar.yy"
                                                                              { (yyvsp[0].paramVector)->push_back(new NIdentifier(*(yyvsp[-2].string))); }
#line 2261 "grammar.tab.cc"
    break;


#line 2265 "grammar.tab.cc"

        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
  }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yyesa, &yyes, &yyes_capacity, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 212 "grammar.yy"

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
    std::cout << programBlock << std::endl;
    return 0;
}

void yyerror(const char *error){
    std::cout << "\n";
    std::cout << error << " \'"<< feedback.value <<"\' on [" << feedback.line 
    << ":" << feedback.column << "]\n\n";
}



int yylex (YYSTYPE *lvalp) {
  it = list.begin();
  unsigned int _type = (*it).type;
  std::string _value = (*it).value;
  unsigned int _lineNo = (*it).line;
  unsigned int _column = (*it).position;

  feedback.value = _value;
  feedback.line = _lineNo;
  feedback.column = _column;

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
