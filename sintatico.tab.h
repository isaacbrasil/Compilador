/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SINTATICO_TAB_H_INCLUDED
# define YY_YY_SINTATICO_TAB_H_INCLUDED
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
    INTEIRO = 258,                 /* INTEIRO  */
    REAL = 259,                    /* REAL  */
    LITERALSTRING = 260,           /* LITERALSTRING  */
    ID = 261,                      /* ID  */
    AP = 262,                      /* AP  */
    FP = 263,                      /* FP  */
    VIRG = 264,                    /* VIRG  */
    PVIRG = 265,                   /* PVIRG  */
    COMM = 266,                    /* COMM  */
    INICIOPROG = 267,              /* INICIOPROG  */
    FIMPROG = 268,                 /* FIMPROG  */
    INICIOARGS = 269,              /* INICIOARGS  */
    FIMARGS = 270,                 /* FIMARGS  */
    INICIOVARS = 271,              /* INICIOVARS  */
    FIMVARS = 272,                 /* FIMVARS  */
    ESCREVA = 273,                 /* ESCREVA  */
    SE = 274,                      /* SE  */
    ENTAO = 275,                   /* ENTAO  */
    FIMSE = 276,                   /* FIMSE  */
    ENQUANTO = 277,                /* ENQUANTO  */
    FACA = 278,                    /* FACA  */
    FIMENQUANTO = 279,             /* FIMENQUANTO  */
    NUMBER = 280,                  /* NUMBER  */
    RELOP = 281,                   /* RELOP  */
    ATTR = 282,                    /* ATTR  */
    ERROR = 283,                   /* ERROR  */
    LITERAL = 284,                 /* LITERAL  */
    RELALG = 285,                  /* RELALG  */
    RELALGSUM = 286,               /* RELALGSUM  */
    RELALGSUB = 287,               /* RELALGSUB  */
    RELALGDIV = 288,               /* RELALGDIV  */
    RELALGTIMES = 289              /* RELALGTIMES  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "sintatico.y"

    int ival;
    float fval;
    char *sval;
    Type type;

#line 105 "sintatico.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SINTATICO_TAB_H_INCLUDED  */
