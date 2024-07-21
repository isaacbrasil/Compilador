/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintatico.y"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "symbol_table.h"
#include "sintatico.tab.h"
extern int yylineno;
int yylex(void);
int yyerror (char *);

// Funções auxiliares para verificação de tipo
Type checkType(Type left, Type right);
Type determineType(double num);


#line 88 "sintatico.tab.c"

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

#include "sintatico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEIRO = 3,                    /* INTEIRO  */
  YYSYMBOL_REAL = 4,                       /* REAL  */
  YYSYMBOL_LITERALSTRING = 5,              /* LITERALSTRING  */
  YYSYMBOL_AP = 6,                         /* AP  */
  YYSYMBOL_FP = 7,                         /* FP  */
  YYSYMBOL_VIRG = 8,                       /* VIRG  */
  YYSYMBOL_PVIRG = 9,                      /* PVIRG  */
  YYSYMBOL_COMM = 10,                      /* COMM  */
  YYSYMBOL_INICIOPROG = 11,                /* INICIOPROG  */
  YYSYMBOL_FIMPROG = 12,                   /* FIMPROG  */
  YYSYMBOL_INICIOARGS = 13,                /* INICIOARGS  */
  YYSYMBOL_FIMARGS = 14,                   /* FIMARGS  */
  YYSYMBOL_INICIOVARS = 15,                /* INICIOVARS  */
  YYSYMBOL_FIMVARS = 16,                   /* FIMVARS  */
  YYSYMBOL_ESCREVA = 17,                   /* ESCREVA  */
  YYSYMBOL_SE = 18,                        /* SE  */
  YYSYMBOL_ENTAO = 19,                     /* ENTAO  */
  YYSYMBOL_FIMSE = 20,                     /* FIMSE  */
  YYSYMBOL_ENQUANTO = 21,                  /* ENQUANTO  */
  YYSYMBOL_FACA = 22,                      /* FACA  */
  YYSYMBOL_FIMENQUANTO = 23,               /* FIMENQUANTO  */
  YYSYMBOL_ID = 24,                        /* ID  */
  YYSYMBOL_NUMBER = 25,                    /* NUMBER  */
  YYSYMBOL_RELOP = 26,                     /* RELOP  */
  YYSYMBOL_ATTR = 27,                      /* ATTR  */
  YYSYMBOL_ERROR = 28,                     /* ERROR  */
  YYSYMBOL_LITERAL = 29,                   /* LITERAL  */
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_31_ = 31,                       /* '+'  */
  YYSYMBOL_32_ = 32,                       /* '-'  */
  YYSYMBOL_33_ = 33,                       /* '*'  */
  YYSYMBOL_34_ = 34,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_programa = 36,                  /* programa  */
  YYSYMBOL_prog = 37,                      /* prog  */
  YYSYMBOL_declara_args = 38,              /* declara_args  */
  YYSYMBOL_declara_vars = 39,              /* declara_vars  */
  YYSYMBOL_statement = 40,                 /* statement  */
  YYSYMBOL_algebraic_expr = 41,            /* algebraic_expr  */
  YYSYMBOL_rel_alg = 42,                   /* rel_alg  */
  YYSYMBOL_logic_expr = 43,                /* logic_expr  */
  YYSYMBOL_attrib = 44,                    /* attrib  */
  YYSYMBOL_expr_condicional = 45,          /* expr_condicional  */
  YYSYMBOL_expr_controle = 46,             /* expr_controle  */
  YYSYMBOL_expr_escreva = 47,              /* expr_escreva  */
  YYSYMBOL_args_list = 48,                 /* args_list  */
  YYSYMBOL_vars_list = 49,                 /* vars_list  */
  YYSYMBOL_var_decl = 50,                  /* var_decl  */
  YYSYMBOL_ID_list = 51,                   /* ID_list  */
  YYSYMBOL_tipo_var = 52,                  /* tipo_var  */
  YYSYMBOL_instruction = 53                /* instruction  */
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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   121

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  109

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


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
       2,     2,    33,    31,     2,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    44,    44,    46,    48,    50,    52,    53,    54,    55,
      56,    57,    58,    60,    64,    69,    74,    79,    83,    88,
      95,    96,    97,    98,   101,   106,   111,   116,   120,   125,
     130,   136,   141,   146,   151,   156,   163,   165,   167,   168,
     169,   170,   173,   174,   176,   177,   179,   181,   182,   185,
     189,   193,   200,   201,   202
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEIRO", "REAL",
  "LITERALSTRING", "AP", "FP", "VIRG", "PVIRG", "COMM", "INICIOPROG",
  "FIMPROG", "INICIOARGS", "FIMARGS", "INICIOVARS", "FIMVARS", "ESCREVA",
  "SE", "ENTAO", "FIMSE", "ENQUANTO", "FACA", "FIMENQUANTO", "ID",
  "NUMBER", "RELOP", "ATTR", "ERROR", "LITERAL", "'='", "'+'", "'-'",
  "'*'", "'/'", "$accept", "programa", "prog", "declara_args",
  "declara_vars", "statement", "algebraic_expr", "rel_alg", "logic_expr",
  "attrib", "expr_condicional", "expr_controle", "expr_escreva",
  "args_list", "vars_list", "var_decl", "ID_list", "tipo_var",
  "instruction", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-42)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -6,    42,    13,    -2,    47,    59,   -42,   -42,   -42,   -42,
      50,    -2,    57,   -42,    -2,    30,   -42,   -42,   -42,     0,
      66,    -2,    45,    54,    17,    69,    77,   -15,   -42,    30,
      30,    30,    30,    30,    30,    71,   -42,   -42,   -42,    41,
     -42,   -42,   -42,   -42,    43,    48,    49,    75,    87,    90,
      95,    32,    32,    39,    21,    46,   -42,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,    80,    81,    82,   102,   103,
     -42,   -42,   -42,    -3,   104,     6,   105,   106,   -42,   -42,
     -42,    92,    94,   -42,   -42,   -42,   -42,   -42,   -14,   -14,
      85,   -14,   -14,    97,    96,   -42,   -42,   -42,   -42
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    43,     0,     0,     1,    49,    50,    51,
       0,    43,     0,     2,    45,    12,     4,    42,    48,     0,
       0,    45,     0,     0,     0,     0,     0,     0,     3,    12,
      12,    12,    12,    12,    12,     0,    46,     5,    44,     0,
      21,    20,    23,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     7,     8,     9,
      10,    11,    47,    27,    26,    13,    14,    30,    29,    17,
      18,    40,    39,    38,    41,     0,     0,     0,     0,     0,
      25,    28,    24,     0,     0,     0,     0,     0,    16,    19,
      15,     0,     0,    32,    35,    31,    33,    34,    54,    54,
       0,    54,    54,     0,     0,    53,    52,    36,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -42,   -42,   -42,   -42,   -42,    60,    64,   -23,    51,   -41,
     -42,   -42,    -1,   109,   100,    -7,   -42,   -42,   -33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     4,     5,    15,    28,    29,    44,    30,    31,
      32,    33,    34,    10,    20,    11,    19,    12,   103
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      46,     7,     8,    24,    55,     1,    93,    21,    35,    36,
     100,    53,    54,     6,    21,    95,    40,    41,    42,    43,
      47,    48,    49,    39,    83,    23,    84,     9,    40,    41,
      42,    43,    53,    22,    23,    75,    76,    40,    41,    42,
      43,    50,    80,    81,    63,    85,    65,    24,    25,    88,
      89,    26,    67,    69,    27,     3,    77,   101,   101,    13,
     101,   101,    55,    82,    16,    64,   104,    66,   105,   106,
      90,    39,    68,    70,    14,    51,    40,    41,    42,    43,
      45,    18,    37,    52,    71,    40,    41,    42,    43,    56,
      57,    58,    59,    60,    61,    62,    72,   102,   102,    73,
     102,   102,    78,    79,    74,    87,    39,    45,    53,    91,
      92,    98,    54,    94,    96,    97,    99,   107,    86,   108,
      17,    38
};

static const yytype_int8 yycheck[] =
{
      23,     3,     4,    17,    27,    11,     9,    14,     8,     9,
      24,    26,    27,     0,    21,     9,    31,    32,    33,    34,
       3,     4,     5,    26,     3,     4,     5,    29,    31,    32,
      33,    34,    26,     3,     4,     3,     4,    31,    32,    33,
      34,    24,     3,     4,     3,    24,     3,    17,    18,     3,
       4,    21,     4,     4,    24,    13,    24,    98,    99,    12,
     101,   102,    85,    24,    14,    24,    99,    24,   101,   102,
      24,    26,    24,    24,    15,     6,    31,    32,    33,    34,
      26,    24,    16,     6,     9,    31,    32,    33,    34,    29,
      30,    31,    32,    33,    34,    24,     9,    98,    99,     9,
     101,   102,    51,    52,     9,    54,    26,    26,    26,     7,
       7,    19,    27,     9,     9,     9,    22,    20,    54,    23,
      11,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    36,    13,    37,    38,     0,     3,     4,    29,
      48,    50,    52,    12,    15,    39,    14,    48,    24,    51,
      49,    50,     3,     4,    17,    18,    21,    24,    40,    41,
      43,    44,    45,    46,    47,     8,     9,    16,    49,    26,
      31,    32,    33,    34,    42,    26,    42,     3,     4,     5,
      24,     6,     6,    26,    27,    42,    40,    40,    40,    40,
      40,    40,    24,     3,    24,     3,    24,     4,    24,     4,
      24,     9,     9,     9,     9,     3,     4,    24,    43,    43,
       3,     4,    24,     3,     5,    24,    41,    43,     3,     4,
      24,     7,     7,     9,     9,     9,     9,     9,    19,    22,
      24,    44,    47,    53,    53,    53,    53,    20,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    38,    39,    40,    40,    40,    40,
      40,    40,    40,    41,    41,    41,    41,    41,    41,    41,
      42,    42,    42,    42,    43,    43,    43,    43,    43,    43,
      43,    44,    44,    44,    44,    44,    45,    46,    47,    47,
      47,    47,    48,    48,    49,    49,    50,    51,    51,    52,
      52,    52,    53,    53,    53
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     2,     0,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     4,     4,     4,     4,     4,     7,     7,     3,     3,
       3,     3,     2,     0,     2,     0,     3,     3,     1,     1,
       1,     1,     2,     2,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
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
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
      yychar = yylex ();
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
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
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
  switch (yyn)
    {
  case 2: /* programa: INICIOPROG prog FIMPROG  */
#line 44 "sintatico.y"
                                   { printf("\nFim do Programa\n"); }
#line 1196 "sintatico.tab.c"
    break;

  case 3: /* prog: declara_args declara_vars statement  */
#line 46 "sintatico.y"
                                           { printf("\nProdução do codigo do programa\n"); }
#line 1202 "sintatico.tab.c"
    break;

  case 4: /* declara_args: INICIOARGS args_list FIMARGS  */
#line 48 "sintatico.y"
                                            { printf("\nProdução de argumentos\n"); }
#line 1208 "sintatico.tab.c"
    break;

  case 5: /* declara_vars: INICIOVARS vars_list FIMVARS  */
#line 50 "sintatico.y"
                                            { printf("\nProdução de variaveis\n"); }
#line 1214 "sintatico.tab.c"
    break;

  case 6: /* statement: algebraic_expr statement  */
#line 52 "sintatico.y"
                                     { printf("\nstatement -> algebraic_expr statement\n"); }
#line 1220 "sintatico.tab.c"
    break;

  case 7: /* statement: logic_expr statement  */
#line 53 "sintatico.y"
                                 { printf("\nstatement -> logic_expr statement\n"); }
#line 1226 "sintatico.tab.c"
    break;

  case 8: /* statement: attrib statement  */
#line 54 "sintatico.y"
                             { printf("\nstatement -> attrib statement\n"); }
#line 1232 "sintatico.tab.c"
    break;

  case 9: /* statement: expr_condicional statement  */
#line 55 "sintatico.y"
                                       { printf("\nstatement -> expr_condicional statement\n"); }
#line 1238 "sintatico.tab.c"
    break;

  case 10: /* statement: expr_controle statement  */
#line 56 "sintatico.y"
                                    { printf("\nstatement -> expr_controle statement\n"); }
#line 1244 "sintatico.tab.c"
    break;

  case 11: /* statement: expr_escreva statement  */
#line 57 "sintatico.y"
                                   { printf("\nstatement -> expr_escreva statement\n"); }
#line 1250 "sintatico.tab.c"
    break;

  case 13: /* algebraic_expr: INTEIRO rel_alg INTEIRO  */
#line 60 "sintatico.y"
                                         {
                    (yyval.type) = T_INT;
                    printf("\nalgebraic_expr -> INTEIRO rel_alg INTEIRO\n");
                }
#line 1259 "sintatico.tab.c"
    break;

  case 14: /* algebraic_expr: INTEIRO rel_alg ID  */
#line 64 "sintatico.y"
                                     {
                    (yyval.type) = checkType(T_INT, (yyvsp[0].type));
                    if ((yyval.type) == T_ERROR) yyerror("Incompatibilidade de tipos na expressão aritmética");
                    printf("\nalgebraic_expr -> INTEIRO rel_alg ID\n");
                }
#line 1269 "sintatico.tab.c"
    break;

  case 15: /* algebraic_expr: ID rel_alg ID  */
#line 69 "sintatico.y"
                                {
                    (yyval.type) = checkType((yyvsp[-2].type), (yyvsp[0].type));
                    if ((yyval.type) == T_ERROR) yyerror("Incompatibilidade de tipos na expressão aritmética");
                    printf("\nalgebraic_expr -> ID rel_alg ID\n");
                }
#line 1279 "sintatico.tab.c"
    break;

  case 16: /* algebraic_expr: ID rel_alg INTEIRO  */
#line 74 "sintatico.y"
                                     {
                    (yyval.type) = checkType((yyvsp[-2].type), T_INT);
                    if ((yyval.type) == T_ERROR) yyerror("Incompatibilidade de tipos na expressão aritmética");
                    printf("\nalgebraic_expr -> ID rel_alg INTEIRO\n");
                }
#line 1289 "sintatico.tab.c"
    break;

  case 17: /* algebraic_expr: REAL rel_alg REAL  */
#line 79 "sintatico.y"
                                    {
                    (yyval.type) = T_FLOAT;
                    printf("\nalgebraic_expr -> REAL rel_alg REAL\n");
                }
#line 1298 "sintatico.tab.c"
    break;

  case 18: /* algebraic_expr: REAL rel_alg ID  */
#line 83 "sintatico.y"
                                  {
                    (yyval.type) = checkType(T_FLOAT, (yyvsp[0].type));
                    if ((yyval.type) == T_ERROR) yyerror("Incompatibilidade de tipos na expressão aritmética");
                    printf("\nalgebraic_expr -> REAL rel_alg ID\n");
                }
#line 1308 "sintatico.tab.c"
    break;

  case 19: /* algebraic_expr: ID rel_alg REAL  */
#line 88 "sintatico.y"
                                  {
                    (yyval.type) = checkType((yyvsp[-2].type), T_FLOAT);
                    if ((yyval.type) == T_ERROR) yyerror("Incompatibilidade de tipos na expressão aritmética");
                    printf("\nalgebraic_expr -> ID rel_alg REAL\n");
                }
#line 1318 "sintatico.tab.c"
    break;

  case 20: /* rel_alg: '-'  */
#line 95 "sintatico.y"
              { printf("\nrel_alg -> SUBTRAÇÃO\n"); }
#line 1324 "sintatico.tab.c"
    break;

  case 21: /* rel_alg: '+'  */
#line 96 "sintatico.y"
              { printf("\nrel_alg -> ADIÇÃO\n"); }
#line 1330 "sintatico.tab.c"
    break;

  case 22: /* rel_alg: '/'  */
#line 97 "sintatico.y"
              { printf("\nrel_alg -> DIVISÃO\n"); }
#line 1336 "sintatico.tab.c"
    break;

  case 23: /* rel_alg: '*'  */
#line 98 "sintatico.y"
              { printf("\nrel_alg -> MULTIPLICAÇÃO\n"); }
#line 1342 "sintatico.tab.c"
    break;

  case 24: /* logic_expr: ID RELOP ID  */
#line 101 "sintatico.y"
                         {
                printf("\nlogic_expr -> ID RELOP ID\n");
                (yyval.type) = checkType((yyvsp[-2].type), (yyvsp[0].type));
                if ((yyval.type) == T_ERROR) yyerror("Incompatibilidade de tipos na expressão lógica");
            }
#line 1352 "sintatico.tab.c"
    break;

  case 25: /* logic_expr: ID RELOP INTEIRO  */
#line 106 "sintatico.y"
                               {
                printf("\nlogic_expr -> ID RELOP INTEIRO\n");
                (yyval.type) = checkType((yyvsp[-2].type), T_INT);
                if ((yyval.type) == T_ERROR) yyerror("Incompatibilidade de tipos na expressão lógica");
            }
#line 1362 "sintatico.tab.c"
    break;

  case 26: /* logic_expr: INTEIRO RELOP ID  */
#line 111 "sintatico.y"
                               {
                printf("\nlogic_expr -> INTEIRO RELOP ID\n");
                (yyval.type) = checkType(T_INT, (yyvsp[0].type));
                if ((yyval.type) == T_ERROR) yyerror("Incompatibilidade de tipos na expressão lógica");
            }
#line 1372 "sintatico.tab.c"
    break;

  case 27: /* logic_expr: INTEIRO RELOP INTEIRO  */
#line 116 "sintatico.y"
                                    {
                printf("\nlogic_expr -> INTEIRO RELOP INTEIRO\n");
                (yyval.type) = T_INT;
            }
#line 1381 "sintatico.tab.c"
    break;

  case 28: /* logic_expr: ID RELOP REAL  */
#line 120 "sintatico.y"
                            {
                printf("\nlogic_expr -> ID RELOP REAL\n");
                (yyval.type) = checkType((yyvsp[-2].type), T_FLOAT);
                if ((yyval.type) == T_ERROR) yyerror("Incompatibilidade de tipos na expressão lógica");
            }
#line 1391 "sintatico.tab.c"
    break;

  case 29: /* logic_expr: REAL RELOP ID  */
#line 125 "sintatico.y"
                            {
                printf("\nlogic_expr -> REAL RELOP ID\n");
                (yyval.type) = checkType(T_FLOAT, (yyvsp[0].type));
                if ((yyval.type) == T_ERROR) yyerror("Incompatibilidade de tipos na expressão lógica");
            }
#line 1401 "sintatico.tab.c"
    break;

  case 30: /* logic_expr: REAL RELOP REAL  */
#line 130 "sintatico.y"
                              {
                printf("\nlogic_expr -> REAL RELOP REAL\n");
                (yyval.type) = T_FLOAT;
            }
#line 1410 "sintatico.tab.c"
    break;

  case 31: /* attrib: ID ATTR ID PVIRG  */
#line 136 "sintatico.y"
                          {
            printf("\nattrib -> ID ATTR ID PVIRG\n");
            (yyval.type) = checkType((yyvsp[-3].type), (yyvsp[-1].type));
            if ((yyval.type) == T_ERROR) yyerror("Incompatibilidade de tipos na atribuição");
        }
#line 1420 "sintatico.tab.c"
    break;

  case 32: /* attrib: ID ATTR INTEIRO PVIRG  */
#line 141 "sintatico.y"
                                {
            printf("\nattrib -> ID ATTR INTEIRO PVIRG\n");
            (yyval.type) = checkType((yyvsp[-3].type), T_INT);
            if ((yyval.type) == T_ERROR) yyerror("Incompatibilidade de tipos na atribuição");
        }
#line 1430 "sintatico.tab.c"
    break;

  case 33: /* attrib: ID ATTR algebraic_expr PVIRG  */
#line 146 "sintatico.y"
                                       {
            printf("\nattrib -> ID ATTR algebraic_expr PVIRG\n");
            (yyval.type) = checkType((yyvsp[-3].type), (yyvsp[-1].type));
            if ((yyval.type) == T_ERROR) yyerror("Incompatibilidade de tipos na atribuição");
        }
#line 1440 "sintatico.tab.c"
    break;

  case 34: /* attrib: ID ATTR logic_expr PVIRG  */
#line 151 "sintatico.y"
                                   {
            printf("\nattrib -> ID ATTR logic_expr PVIRG\n");
            (yyval.type) = checkType((yyvsp[-3].type), (yyvsp[-1].type));
            if ((yyval.type) == T_ERROR) yyerror("Incompatibilidade de tipos na atribuição");
        }
#line 1450 "sintatico.tab.c"
    break;

  case 35: /* attrib: ID ATTR LITERALSTRING PVIRG  */
#line 156 "sintatico.y"
                                      {
            printf("\nattrib -> ID ATTR LITERALSTRING PVIRG\n");
            (yyval.type) = checkType((yyvsp[-3].type), T_STRING);
            if ((yyval.type) == T_ERROR) yyerror("Incompatibilidade de tipos na atribuição");
        }
#line 1460 "sintatico.tab.c"
    break;

  case 36: /* expr_condicional: SE AP logic_expr FP ENTAO instruction FIMSE  */
#line 163 "sintatico.y"
                                                               { printf("\nProdução de expressão condicional\n"); }
#line 1466 "sintatico.tab.c"
    break;

  case 37: /* expr_controle: ENQUANTO AP logic_expr FP FACA instruction FIMENQUANTO  */
#line 165 "sintatico.y"
                                                                       { printf("\nProdução de expressão de controle\n"); }
#line 1472 "sintatico.tab.c"
    break;

  case 38: /* expr_escreva: ESCREVA LITERALSTRING PVIRG  */
#line 167 "sintatico.y"
                                           { printf("\nexpr_escreva -> ESCREVA LITERALSTRING PVIRG\n"); }
#line 1478 "sintatico.tab.c"
    break;

  case 39: /* expr_escreva: ESCREVA REAL PVIRG  */
#line 168 "sintatico.y"
                                   { printf("\nexpr_escreva -> ESCREVA REAL PVIRG\n"); }
#line 1484 "sintatico.tab.c"
    break;

  case 40: /* expr_escreva: ESCREVA INTEIRO PVIRG  */
#line 169 "sintatico.y"
                                      { printf("\nexpr_escreva -> ESCREVA INTEIRO PVIRG\n"); }
#line 1490 "sintatico.tab.c"
    break;

  case 41: /* expr_escreva: ESCREVA ID PVIRG  */
#line 170 "sintatico.y"
                                 { printf("\nexpr_escreva -> ESCREVA ID PVIRG\n"); }
#line 1496 "sintatico.tab.c"
    break;

  case 42: /* args_list: var_decl args_list  */
#line 173 "sintatico.y"
                               { printf("\nargs_list -> var_decl args_list\n"); }
#line 1502 "sintatico.tab.c"
    break;

  case 44: /* vars_list: var_decl vars_list  */
#line 176 "sintatico.y"
                               { printf("\nvars_list -> var_decl vars_list\n"); }
#line 1508 "sintatico.tab.c"
    break;

  case 46: /* var_decl: tipo_var ID_list PVIRG  */
#line 179 "sintatico.y"
                                  { printf("\nvar_decl -> tipo_var ID_list PVIRG\n"); }
#line 1514 "sintatico.tab.c"
    break;

  case 47: /* ID_list: ID_list VIRG ID  */
#line 181 "sintatico.y"
                          { printf("\nID_list -> ID_list VIRG ID\n"); }
#line 1520 "sintatico.tab.c"
    break;

  case 48: /* ID_list: ID  */
#line 182 "sintatico.y"
             { printf("\nID_list -> ID\n"); }
#line 1526 "sintatico.tab.c"
    break;

  case 49: /* tipo_var: INTEIRO  */
#line 185 "sintatico.y"
                   {
            printf("\ntipo_var -> INTEIRO\n");
            (yyval.type) = T_INT;
          }
#line 1535 "sintatico.tab.c"
    break;

  case 50: /* tipo_var: REAL  */
#line 189 "sintatico.y"
                 {
            printf("\ntipo_var -> REAL\n");
            (yyval.type) = T_FLOAT;
          }
#line 1544 "sintatico.tab.c"
    break;

  case 51: /* tipo_var: LITERAL  */
#line 193 "sintatico.y"
                    {
            printf("\ntipo_var -> LITERAL\n");
            (yyval.type) = T_STRING;
          }
#line 1553 "sintatico.tab.c"
    break;

  case 52: /* instruction: expr_escreva instruction  */
#line 200 "sintatico.y"
                                       { printf("\ninstruction -> expr_escreva\n");}
#line 1559 "sintatico.tab.c"
    break;

  case 53: /* instruction: attrib instruction  */
#line 201 "sintatico.y"
                                  { printf("\ninstruction -> attrib\n");}
#line 1565 "sintatico.tab.c"
    break;


#line 1569 "sintatico.tab.c"

      default: break;
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
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

  return yyresult;
}

#line 204 "sintatico.y"


int main() {
    initializeSymbolTable(); // Inicializa a tabela de símbolos
    addReservedWords(); // Adiciona palavras reservadas

    if (yyparse() != 0) {
        fprintf(stderr, "Abnormal exit\n");
    }
    return 0;
}

int yyerror(char *s) {
    fprintf(stderr, "Error: %s -- Line: %d\n", s, yylineno);
    return 0;
}

Type checkType(Type left, Type right) {
    if (left == right) return left;
    if ((left == T_INT && right == T_FLOAT) || (left == T_FLOAT && right == T_INT)) return T_FLOAT;
    fprintf(stderr, "Error: Incompatibilidade de tipos -- Line: %d\n", yylineno);
    return T_ERROR;
}

Type determineType(double num) {
    return (num == (int)num) ? T_INT : T_FLOAT;
}
