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
#include <string.h>
#include "symbol_table.h"
#include "sintatico.tab.h"
extern int yylineno;
int yylex(void);
extern int yylval;
int yyerror(char *);

int enable_prints = 0;
int enable_lex_prints = 0;
void print_if_enabled(const char *msg);
void print_lex_with_args(const char *msg, const char *arg);



#line 91 "sintatico.tab.c"

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
  YYSYMBOL_AP = 3,                         /* AP  */
  YYSYMBOL_FP = 4,                         /* FP  */
  YYSYMBOL_VIRG = 5,                       /* VIRG  */
  YYSYMBOL_PVIRG = 6,                      /* PVIRG  */
  YYSYMBOL_COMM = 7,                       /* COMM  */
  YYSYMBOL_INICIOPROG = 8,                 /* INICIOPROG  */
  YYSYMBOL_FIMPROG = 9,                    /* FIMPROG  */
  YYSYMBOL_INICIOARGS = 10,                /* INICIOARGS  */
  YYSYMBOL_FIMARGS = 11,                   /* FIMARGS  */
  YYSYMBOL_INICIOVARS = 12,                /* INICIOVARS  */
  YYSYMBOL_FIMVARS = 13,                   /* FIMVARS  */
  YYSYMBOL_ESCREVA = 14,                   /* ESCREVA  */
  YYSYMBOL_INTEIRO = 15,                   /* INTEIRO  */
  YYSYMBOL_REAL = 16,                      /* REAL  */
  YYSYMBOL_SE = 17,                        /* SE  */
  YYSYMBOL_ENTAO = 18,                     /* ENTAO  */
  YYSYMBOL_FIMSE = 19,                     /* FIMSE  */
  YYSYMBOL_ENQUANTO = 20,                  /* ENQUANTO  */
  YYSYMBOL_FACA = 21,                      /* FACA  */
  YYSYMBOL_FIMENQUANTO = 22,               /* FIMENQUANTO  */
  YYSYMBOL_ID = 23,                        /* ID  */
  YYSYMBOL_NUMBER = 24,                    /* NUMBER  */
  YYSYMBOL_LITERAL = 25,                   /* LITERAL  */
  YYSYMBOL_SPECIALCHAR = 26,               /* SPECIALCHAR  */
  YYSYMBOL_RELOP = 27,                     /* RELOP  */
  YYSYMBOL_ATTR = 28,                      /* ATTR  */
  YYSYMBOL_ERROR = 29,                     /* ERROR  */
  YYSYMBOL_LITERALSTRING = 30,             /* LITERALSTRING  */
  YYSYMBOL_AC = 31,                        /* AC  */
  YYSYMBOL_FC = 32,                        /* FC  */
  YYSYMBOL_33_ = 33,                       /* '='  */
  YYSYMBOL_RELALGSUM = 34,                 /* RELALGSUM  */
  YYSYMBOL_RELALGSUB = 35,                 /* RELALGSUB  */
  YYSYMBOL_36_ = 36,                       /* '+'  */
  YYSYMBOL_37_ = 37,                       /* '-'  */
  YYSYMBOL_RELALGDIV = 38,                 /* RELALGDIV  */
  YYSYMBOL_RELALGTIMES = 39,               /* RELALGTIMES  */
  YYSYMBOL_40_ = 40,                       /* '*'  */
  YYSYMBOL_41_ = 41,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_programa = 43,                  /* programa  */
  YYSYMBOL_prog = 44,                      /* prog  */
  YYSYMBOL_declara_args = 45,              /* declara_args  */
  YYSYMBOL_comment = 46,                   /* comment  */
  YYSYMBOL_declara_vars = 47,              /* declara_vars  */
  YYSYMBOL_statement = 48,                 /* statement  */
  YYSYMBOL_algebraic_expr = 49,            /* algebraic_expr  */
  YYSYMBOL_rel_alg = 50,                   /* rel_alg  */
  YYSYMBOL_logic_expr = 51,                /* logic_expr  */
  YYSYMBOL_attrib = 52,                    /* attrib  */
  YYSYMBOL_expr_condicional = 53,          /* expr_condicional  */
  YYSYMBOL_expr_controle = 54,             /* expr_controle  */
  YYSYMBOL_expr_escreva = 55,              /* expr_escreva  */
  YYSYMBOL_args_list = 56,                 /* args_list  */
  YYSYMBOL_vars_list = 57,                 /* vars_list  */
  YYSYMBOL_var_decl = 58,                  /* var_decl  */
  YYSYMBOL_ID_list = 59,                   /* ID_list  */
  YYSYMBOL_tipo_var = 60,                  /* tipo_var  */
  YYSYMBOL_instruction = 61                /* instruction  */
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
#define YYLAST   124

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  106

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
       2,     2,    40,    36,     2,    37,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    33,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    34,    35,
      38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    34,    34,    36,    39,    40,    42,    44,    45,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    61,    62,
      63,    64,    69,    70,    71,    72,    76,    77,    78,    79,
      83,    84,    85,    86,    87,    91,    93,    96,    97,    98,
      99,   103,   104,   107,   108,   111,   114,   115,   119,   120,
     121,   124,   125,   126,   127
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
  "\"end of file\"", "error", "\"invalid token\"", "AP", "FP", "VIRG",
  "PVIRG", "COMM", "INICIOPROG", "FIMPROG", "INICIOARGS", "FIMARGS",
  "INICIOVARS", "FIMVARS", "ESCREVA", "INTEIRO", "REAL", "SE", "ENTAO",
  "FIMSE", "ENQUANTO", "FACA", "FIMENQUANTO", "ID", "NUMBER", "LITERAL",
  "SPECIALCHAR", "RELOP", "ATTR", "ERROR", "LITERALSTRING", "AC", "FC",
  "'='", "RELALGSUM", "RELALGSUB", "'+'", "'-'", "RELALGDIV",
  "RELALGTIMES", "'*'", "'/'", "$accept", "programa", "prog",
  "declara_args", "comment", "declara_vars", "statement", "algebraic_expr",
  "rel_alg", "logic_expr", "attrib", "expr_condicional", "expr_controle",
  "expr_escreva", "args_list", "vars_list", "var_decl", "ID_list",
  "tipo_var", "instruction", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-30)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       7,    -6,    28,    -9,    30,    13,   -30,   -30,   -30,   -30,
     -30,    31,    -7,    23,   -30,    51,     3,   -30,   -30,   -30,
       8,   -30,    32,    -7,   -30,    25,    62,    66,    16,    22,
       3,   -30,     3,     3,     3,     3,     3,     3,    58,   -30,
     -30,   -30,    48,    84,    88,    94,     6,     6,    27,    54,
     -30,   -30,   -30,   -30,    37,    56,    86,   -30,   -30,   -30,
     -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,    78,
      85,   107,   109,   -30,   -30,    -5,    -3,   108,   110,   111,
     -30,   -30,   -30,   -30,   -30,   -30,    97,    98,   -30,   -30,
     -30,   -30,   -30,    -2,    -2,    90,    -2,    -2,    -2,   101,
      99,   -30,   -30,   -30,   -30,   -30
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     1,     5,    48,    49,
      50,     0,    42,     0,     2,     0,    17,     4,    41,    47,
       0,     8,     0,    44,     6,     0,     0,     0,     0,     0,
      16,     3,    17,    17,    17,    17,    17,    17,     0,    45,
       7,    43,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    22,    25,    24,     0,     0,     0,     9,    10,    11,
      12,    13,    14,    15,    46,    39,    38,    40,    37,     0,
       0,     0,     0,    26,    27,     0,     0,     0,     0,     0,
      20,    21,    28,    29,    19,    18,     0,     0,    30,    31,
      34,    32,    33,    54,    54,     0,    54,    54,    54,     0,
       0,    53,    52,    51,    35,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -30,   -30,   -30,   -30,   -11,   -30,    38,    73,   -29,    42,
      -1,   -30,   -30,     5,   112,   100,    -4,   -30,   -30,    10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     4,     5,    30,    16,    31,    32,    54,    33,
      34,    35,    36,    37,    11,    22,    12,    20,    13,    99
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      56,    88,     7,    89,     3,    24,     8,     9,     8,     9,
      24,    23,    25,    38,    39,     1,    10,    25,    10,    23,
      26,    95,    48,    27,    55,    15,    28,    29,     6,    69,
      70,    50,    51,    50,    51,    52,    53,    52,    53,    14,
      42,    43,    17,    48,    49,    40,    19,    56,    44,    55,
      73,    74,    50,    51,    65,    45,    52,    53,    50,    51,
      80,    81,    52,    53,    21,    46,     8,     9,    57,    47,
      58,    59,    60,    61,    62,    63,    10,    75,    76,    82,
      83,    64,    96,    96,    77,    96,    96,    96,    71,    72,
      66,    79,    97,    97,    67,    97,    97,    97,    98,    98,
      68,    98,    98,    98,   100,    48,   101,   102,   103,    84,
      85,    86,    55,    87,    90,    93,    91,    92,    49,    94,
     104,   105,    78,    41,    18
};

static const yytype_int8 yycheck[] =
{
      29,     6,    11,     6,    10,     7,    15,    16,    15,    16,
       7,    15,    14,     5,     6,     8,    25,    14,    25,    23,
      17,    23,    27,    20,    27,    12,    23,    24,     0,    23,
      24,    36,    37,    36,    37,    40,    41,    40,    41,     9,
      15,    16,    11,    27,    28,    13,    23,    76,    23,    27,
      23,    24,    36,    37,     6,    30,    40,    41,    36,    37,
      23,    24,    40,    41,    13,     3,    15,    16,    30,     3,
      32,    33,    34,    35,    36,    37,    25,    23,    24,    23,
      24,    23,    93,    94,    30,    96,    97,    98,    46,    47,
       6,    49,    93,    94,     6,    96,    97,    98,    93,    94,
       6,    96,    97,    98,    94,    27,    96,    97,    98,    23,
      24,     4,    27,     4,     6,    18,     6,     6,    28,    21,
      19,    22,    49,    23,    12
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    43,    10,    44,    45,     0,    11,    15,    16,
      25,    56,    58,    60,     9,    12,    47,    11,    56,    23,
      59,    13,    57,    58,     7,    14,    17,    20,    23,    24,
      46,    48,    49,    51,    52,    53,    54,    55,     5,     6,
      13,    57,    15,    16,    23,    30,     3,     3,    27,    28,
      36,    37,    40,    41,    50,    27,    50,    48,    48,    48,
      48,    48,    48,    48,    23,     6,     6,     6,     6,    23,
      24,    51,    51,    23,    24,    23,    24,    30,    49,    51,
      23,    24,    23,    24,    23,    24,     4,     4,     6,     6,
       6,     6,     6,    18,    21,    23,    46,    52,    55,    61,
      61,    61,    61,    61,    19,    22
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    45,    45,    46,    47,    47,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    49,    49,
      49,    49,    50,    50,    50,    50,    51,    51,    51,    51,
      52,    52,    52,    52,    52,    53,    54,    55,    55,    55,
      55,    56,    56,    57,    57,    58,    59,    59,    60,    60,
      60,    61,    61,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     3,     2,     1,     3,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     0,     3,     3,
       3,     3,     1,     1,     1,     1,     3,     3,     3,     3,
       4,     4,     4,     4,     4,     7,     7,     3,     3,     3,
       3,     2,     0,     2,     0,     3,     3,     1,     1,     1,
       1,     2,     2,     2,     0
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
#line 34 "sintatico.y"
                                   { print_if_enabled("\nFim do Programa\n"); }
#line 1209 "sintatico.tab.c"
    break;

  case 3: /* prog: declara_args declara_vars statement  */
#line 36 "sintatico.y"
                                           { print_if_enabled("\nProdução do codigo do programa\n"); }
#line 1215 "sintatico.tab.c"
    break;

  case 4: /* declara_args: INICIOARGS args_list FIMARGS  */
#line 39 "sintatico.y"
                                                {print_if_enabled("\nProdução de argumentos\n");}
#line 1221 "sintatico.tab.c"
    break;

  case 5: /* declara_args: INICIOARGS FIMARGS  */
#line 40 "sintatico.y"
                                                {print_if_enabled("\nArgumentos vazios\n");}
#line 1227 "sintatico.tab.c"
    break;

  case 6: /* comment: COMM  */
#line 42 "sintatico.y"
                                                {print_if_enabled("\nProdução de comentarios\n");}
#line 1233 "sintatico.tab.c"
    break;

  case 7: /* declara_vars: INICIOVARS vars_list FIMVARS  */
#line 44 "sintatico.y"
                                                {print_if_enabled("\nProdução de variaveis\n");}
#line 1239 "sintatico.tab.c"
    break;

  case 8: /* declara_vars: INICIOVARS FIMVARS  */
#line 45 "sintatico.y"
                                                {print_if_enabled("\nVariáveis vazias\n");}
#line 1245 "sintatico.tab.c"
    break;

  case 9: /* statement: comment statement  */
#line 49 "sintatico.y"
                                                {print_if_enabled("\nstatement -> comment statement\n"); }
#line 1251 "sintatico.tab.c"
    break;

  case 10: /* statement: algebraic_expr statement  */
#line 50 "sintatico.y"
                                                {print_if_enabled("\nstatement -> algebraic_expr statement\n");}
#line 1257 "sintatico.tab.c"
    break;

  case 11: /* statement: logic_expr statement  */
#line 51 "sintatico.y"
                                                {print_if_enabled("\nstatement -> logic_expr statement\n");}
#line 1263 "sintatico.tab.c"
    break;

  case 12: /* statement: attrib statement  */
#line 52 "sintatico.y"
                                                {print_if_enabled("\nstatement -> attrib statement\n");}
#line 1269 "sintatico.tab.c"
    break;

  case 13: /* statement: expr_condicional statement  */
#line 53 "sintatico.y"
                                                {print_if_enabled("\nstatement -> expr_condicional statement\n");}
#line 1275 "sintatico.tab.c"
    break;

  case 14: /* statement: expr_controle statement  */
#line 54 "sintatico.y"
                                                {print_if_enabled("\nstatement -> expr_controle statement\n");}
#line 1281 "sintatico.tab.c"
    break;

  case 15: /* statement: expr_escreva statement  */
#line 55 "sintatico.y"
                                                {print_if_enabled("\nstatement -> expr_escreva statement\n");}
#line 1287 "sintatico.tab.c"
    break;

  case 16: /* statement: comment  */
#line 56 "sintatico.y"
                                                { print_if_enabled("\nstatement -> comment\n"); }
#line 1293 "sintatico.tab.c"
    break;

  case 18: /* algebraic_expr: NUMBER rel_alg NUMBER  */
#line 61 "sintatico.y"
                                        { print_if_enabled("\nalgebraic_expr -> NUMBER rel_alg NUMBER\n");}
#line 1299 "sintatico.tab.c"
    break;

  case 19: /* algebraic_expr: NUMBER rel_alg ID  */
#line 62 "sintatico.y"
                                        { print_if_enabled("\nalgebraic_expr -> NUMBER rel_alg ID\n");}
#line 1305 "sintatico.tab.c"
    break;

  case 20: /* algebraic_expr: ID rel_alg ID  */
#line 63 "sintatico.y"
                                        { print_if_enabled("\nalgebraic_expr -> ID rel_alg ID\n");}
#line 1311 "sintatico.tab.c"
    break;

  case 21: /* algebraic_expr: ID rel_alg NUMBER  */
#line 64 "sintatico.y"
                                        { print_if_enabled("\nalgebraic_expr -> ID rel_alg NUMBER\n");}
#line 1317 "sintatico.tab.c"
    break;

  case 22: /* rel_alg: '-'  */
#line 69 "sintatico.y"
              { print_if_enabled("\nrel_alg -> SUBTRAÇÃO\n"); }
#line 1323 "sintatico.tab.c"
    break;

  case 23: /* rel_alg: '+'  */
#line 70 "sintatico.y"
              { print_if_enabled("\nrel_alg -> ADIÇÃO\n"); }
#line 1329 "sintatico.tab.c"
    break;

  case 24: /* rel_alg: '/'  */
#line 71 "sintatico.y"
              { print_if_enabled("\nrel_alg -> DIVISÃO\n"); }
#line 1335 "sintatico.tab.c"
    break;

  case 25: /* rel_alg: '*'  */
#line 72 "sintatico.y"
              { print_if_enabled("\nrel_alg -> MULTIPLICAÇÃO\n"); }
#line 1341 "sintatico.tab.c"
    break;

  case 26: /* logic_expr: ID RELOP ID  */
#line 76 "sintatico.y"
                                    { print_if_enabled("\nlogic_expr -> ID RELOP ID \n");}
#line 1347 "sintatico.tab.c"
    break;

  case 27: /* logic_expr: ID RELOP NUMBER  */
#line 77 "sintatico.y"
                                    { print_if_enabled("\nlogic_expr -> ID RELOP NUMBER\n");}
#line 1353 "sintatico.tab.c"
    break;

  case 28: /* logic_expr: NUMBER RELOP ID  */
#line 78 "sintatico.y"
                                    { print_if_enabled("\nlogic_expr -> NUMBER RELOP ID\n");}
#line 1359 "sintatico.tab.c"
    break;

  case 29: /* logic_expr: NUMBER RELOP NUMBER  */
#line 79 "sintatico.y"
                                    { print_if_enabled("\nlogic_expr -> NUMBER RELOP NUMBER\n");}
#line 1365 "sintatico.tab.c"
    break;

  case 30: /* attrib: ID ATTR ID PVIRG  */
#line 83 "sintatico.y"
                                        { print_if_enabled("\nattrib -> ID ATTR ID PVIRG\n");}
#line 1371 "sintatico.tab.c"
    break;

  case 31: /* attrib: ID ATTR NUMBER PVIRG  */
#line 84 "sintatico.y"
                                        { print_if_enabled("\nattrib -> ID ATTR NUMBER PVIRG\n");}
#line 1377 "sintatico.tab.c"
    break;

  case 32: /* attrib: ID ATTR algebraic_expr PVIRG  */
#line 85 "sintatico.y"
                                        { print_if_enabled("\nattrib -> ID ATTR algebraic_expr PVIRG\n");}
#line 1383 "sintatico.tab.c"
    break;

  case 33: /* attrib: ID ATTR logic_expr PVIRG  */
#line 86 "sintatico.y"
                                        { print_if_enabled("\nattrib -> ID ATTR logic_expr PVIRG\n");}
#line 1389 "sintatico.tab.c"
    break;

  case 34: /* attrib: ID ATTR LITERALSTRING PVIRG  */
#line 87 "sintatico.y"
                                        { print_if_enabled("\nattrib -> ID ATTR LITERALSTRING PVIRG\n");}
#line 1395 "sintatico.tab.c"
    break;

  case 35: /* expr_condicional: SE AP logic_expr FP ENTAO instruction FIMSE  */
#line 91 "sintatico.y"
                                                               { print_if_enabled("\nProdução de expressão condicional\n");}
#line 1401 "sintatico.tab.c"
    break;

  case 36: /* expr_controle: ENQUANTO AP logic_expr FP FACA instruction FIMENQUANTO  */
#line 93 "sintatico.y"
                                                                       { print_if_enabled("\nProdução de expressão de controle\n");}
#line 1407 "sintatico.tab.c"
    break;

  case 37: /* expr_escreva: ESCREVA LITERALSTRING PVIRG  */
#line 96 "sintatico.y"
                                              { print_if_enabled("\nexpr_escreva -> ESCREVA LITERALSTRING PVIRG\n");}
#line 1413 "sintatico.tab.c"
    break;

  case 38: /* expr_escreva: ESCREVA REAL PVIRG  */
#line 97 "sintatico.y"
                                        { print_if_enabled("\nexpr_escreva -> ESCREVA REAL PVIRG\n");}
#line 1419 "sintatico.tab.c"
    break;

  case 39: /* expr_escreva: ESCREVA INTEIRO PVIRG  */
#line 98 "sintatico.y"
                                        { print_if_enabled("\nexpr_escreva -> ESCREVA INTEIRO PVIRG\n");}
#line 1425 "sintatico.tab.c"
    break;

  case 41: /* args_list: var_decl args_list  */
#line 103 "sintatico.y"
                               { print_if_enabled("\nargs_list -> var_decl args_list\n");}
#line 1431 "sintatico.tab.c"
    break;

  case 43: /* vars_list: var_decl vars_list  */
#line 107 "sintatico.y"
                                { print_if_enabled("\nvars_list -> var_decl vars_list\n");}
#line 1437 "sintatico.tab.c"
    break;

  case 45: /* var_decl: tipo_var ID_list PVIRG  */
#line 111 "sintatico.y"
                                  { print_if_enabled("\nvar_decl -> tipo_var ID_list PVIRG\n");}
#line 1443 "sintatico.tab.c"
    break;

  case 46: /* ID_list: ID_list VIRG ID  */
#line 114 "sintatico.y"
                            { print_if_enabled("\nID_list -> ID_list VIRG ID\n");}
#line 1449 "sintatico.tab.c"
    break;

  case 47: /* ID_list: ID  */
#line 115 "sintatico.y"
                            { print_if_enabled("\nID_list -> ID\n");}
#line 1455 "sintatico.tab.c"
    break;

  case 48: /* tipo_var: INTEIRO  */
#line 119 "sintatico.y"
                            { print_if_enabled("\ntipo_var -> INTEIRO\n");}
#line 1461 "sintatico.tab.c"
    break;

  case 49: /* tipo_var: REAL  */
#line 120 "sintatico.y"
                            { print_if_enabled("\ntipo_var -> REAL\n");}
#line 1467 "sintatico.tab.c"
    break;

  case 50: /* tipo_var: LITERAL  */
#line 121 "sintatico.y"
                            { print_if_enabled("\ntipo_var -> LITERAL\n");}
#line 1473 "sintatico.tab.c"
    break;

  case 51: /* instruction: expr_escreva instruction  */
#line 124 "sintatico.y"
                                       { print_if_enabled("\ninstruction -> expr_escreva\n");}
#line 1479 "sintatico.tab.c"
    break;

  case 52: /* instruction: attrib instruction  */
#line 125 "sintatico.y"
                                    { print_if_enabled("\ninstruction -> attrib\n");}
#line 1485 "sintatico.tab.c"
    break;

  case 53: /* instruction: comment instruction  */
#line 126 "sintatico.y"
                                       { print_if_enabled("\ninstruction -> comment\n");}
#line 1491 "sintatico.tab.c"
    break;


#line 1495 "sintatico.tab.c"

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

#line 129 "sintatico.y"

int main(int argc, char **argv) {

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--verbose") == 0) {
            enable_prints = 1;
        }
        if (strcmp(argv[i], "--lex") == 0) {
            enable_lex_prints = 1;
        }
    }

    initializeSymbolTable();
    addReservedWords();

    if (yyparse() != 0) {
        fprintf(stderr, "Abnormal exit\n");
    }
    return 0;
}

void print_if_enabled(const char *msg) {
    if (enable_prints) {
        printf("%s", msg);
    }
}

void print_lex_with_args(const char *msg, const char *arg) {
    if (enable_lex_prints) {
        printf(msg, arg);
    }
}

int yyerror(char *s) {
    fprintf(stderr, "Error: %s -- Line: %d\n", s, yylineno);
    return 0;
}
