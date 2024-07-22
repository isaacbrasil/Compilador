%{
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "symbol_table.h"
#include "sintatico.tab.h"
extern int yylineno;
int yylex(void);
int yyerror (char *);

int enable_prints = 0;
int enable_lex_prints = 0;
void print_if_enabled(const char *msg);
void print_lex_with_args(const char *msg, const char *arg);

Type checkType(Type left, Type right);
Type determineType(double num);

%}

%union {
    int ival;
    float fval;
    char *sval;
    char *name;
    Type type;
}

%token INTEIRO REAL LITERALSTRING ID
%token AP FP VIRG PVIRG COMM INICIOPROG FIMPROG INICIOARGS FIMARGS INICIOVARS FIMVARS ESCREVA
%token SE ENTAO FIMSE ENQUANTO FACA FIMENQUANTO NUMBER RELOP ATTR ERROR LITERAL RELALG

%type <type> algebraic_expr
%type <type> rel_alg
%type <type> logic_expr
%type <type> attrib

%right '='
%left RELOP
%left RELALGSUM RELALGSUB
%left RELALGDIV RELALGTIMES

%%

programa : INICIOPROG prog FIMPROG { print_if_enabled("\nFim do Programa\n"); };

prog : declara_args declara_vars statement { print_if_enabled("\nProdução do codigo do programa\n"); };

declara_args : INICIOARGS args_list FIMARGS { print_if_enabled("\nProdução de argumentos\n"); };

declara_vars : INICIOVARS vars_list FIMVARS { print_if_enabled("\nProdução de variaveis\n"); };

statement : algebraic_expr statement { print_if_enabled("\nstatement -> algebraic_expr statement\n"); }
          | logic_expr statement { print_if_enabled("\nstatement -> logic_expr statement\n"); }
          | attrib statement { print_if_enabled("\nstatement -> attrib statement\n"); }
          | expr_condicional statement { print_if_enabled("\nstatement -> expr_condicional statement\n"); }
          | expr_controle statement { print_if_enabled("\nstatement -> expr_controle statement\n"); }
          | expr_escreva statement { print_if_enabled("\nstatement -> expr_escreva statement\n"); }
          | ;

algebraic_expr : INTEIRO rel_alg INTEIRO {
                    $$ = T_INT;
                    //printa $1 e $3 e seus $n.type
                    printf("$1: %d\n, $3: %d\n, $1.type: %d\n, $3.type: %d\n", $1, $3, $1.type, $3.type);
                    print_if_enabled("\nalgebraic_expr -> INTEIRO rel_alg INTEIRO\n");
                }
                | INTEIRO rel_alg ID {
                    if ($$ == T_ERROR) yyerror("Incompatibilidade de tipos na expressão aritmética");
                    print_if_enabled("\nalgebraic_expr -> INTEIRO rel_alg ID\n");
                }
                | ID rel_alg ID {
                    if ($$ == T_ERROR) yyerror("Incompatibilidade de tipos na expressão aritmética");
                    print_if_enabled("\nalgebraic_expr -> ID rel_alg ID\n");
                }
                | ID rel_alg INTEIRO {
                    if ($$ == T_ERROR) yyerror("Incompatibilidade de tipos na expressão aritmética");
                    print_if_enabled("\nalgebraic_expr -> ID rel_alg INTEIRO\n");
                }
                | REAL rel_alg REAL {
                    $$ = T_FLOAT;
                    print_if_enabled("\nalgebraic_expr -> REAL rel_alg REAL\n");
                }
                | REAL rel_alg ID {
                    if ($$ == T_ERROR) yyerror("Incompatibilidade de tipos na expressão aritmética");
                    print_if_enabled("\nalgebraic_expr -> REAL rel_alg ID\n");
                }
                | ID rel_alg REAL {
                    if ($$ == T_ERROR) yyerror("Incompatibilidade de tipos na expressão aritmética");
                    print_if_enabled("\nalgebraic_expr -> ID rel_alg REAL\n");
                }
                ;

rel_alg : RELALGSUB { print_if_enabled("\nrel_alg -> SUBTRAÇÃO\n"); }
        | RELALGSUM { print_if_enabled("\nrel_alg -> ADIÇÃO\n"); }
        | RELALGDIV { print_if_enabled("\nrel_alg -> DIVISÃO\n"); }
        | RELALGTIMES { print_if_enabled("\nrel_alg -> MULTIPLICAÇÃO\n"); }
        ;

logic_expr : ID RELOP ID {
                print_if_enabled("\nlogic_expr -> ID RELOP ID\n");
            }
            | ID RELOP INTEIRO {
                print_if_enabled("\nlogic_expr -> ID RELOP INTEIRO\n");
            }
            | INTEIRO RELOP ID {
                print_if_enabled("\nlogic_expr -> INTEIRO RELOP ID\n");
            }
            | INTEIRO RELOP INTEIRO {
                print_if_enabled("\nlogic_expr -> INTEIRO RELOP INTEIRO\n");
            }
            | ID RELOP REAL {
                print_if_enabled("\nlogic_expr -> ID RELOP REAL\n");
            }
            | REAL RELOP ID {
                print_if_enabled("\nlogic_expr -> REAL RELOP ID\n");
            }
            | REAL RELOP REAL {
                print_if_enabled("\nlogic_expr -> REAL RELOP REAL\n");
            }
            ;

attrib : ID ATTR ID PVIRG {
            print_if_enabled("\nattrib -> ID ATTR ID PVIRG\n");
        }
        | ID ATTR INTEIRO PVIRG {
            print_if_enabled("\nattrib -> ID ATTR INTEIRO PVIRG\n");
        }
        | ID ATTR REAL PVIRG {
            print_if_enabled("\nattrib -> ID ATTR REAL PVIRG\n");
        }
        | ID ATTR algebraic_expr PVIRG {
            print_if_enabled("\nattrib -> ID ATTR algebraic_expr PVIRG\n");
        }
        | ID ATTR logic_expr PVIRG {
            print_if_enabled("\nattrib -> ID ATTR logic_expr PVIRG\n");
        }
        | ID ATTR LITERALSTRING PVIRG {
            print_if_enabled("\nattrib -> ID ATTR LITERALSTRING PVIRG\n");
        }
        ;

expr_condicional : SE AP logic_expr FP ENTAO statement FIMSE { print_if_enabled("\nProdução de expressão condicional\n"); };

expr_controle : ENQUANTO AP logic_expr FP FACA statement FIMENQUANTO { print_if_enabled("\nProdução de expressão de controle\n"); };

expr_escreva : ESCREVA LITERALSTRING PVIRG { print_if_enabled("\nexpr_escreva -> ESCREVA LITERALSTRING PVIRG\n"); }
              | ESCREVA REAL PVIRG { print_if_enabled("\nexpr_escreva -> ESCREVA REAL PVIRG\n"); }
              | ESCREVA INTEIRO PVIRG { print_if_enabled("\nexpr_escreva -> ESCREVA INTEIRO PVIRG\n"); }
              | ESCREVA ID PVIRG { print_if_enabled("\nexpr_escreva -> ESCREVA ID PVIRG\n"); }
              ;

args_list : var_decl args_list { print_if_enabled("\nargs_list -> var_decl args_list\n"); }
          | ;

vars_list : var_decl vars_list { }
          | ;

var_decl : tipo_var ID_list PVIRG { print_if_enabled("\nvar_decl -> tipo_var ID_list PVIRG\n"); };

ID_list : ID_list VIRG ID { print_if_enabled("\nID_list -> ID_list VIRG ID\n"); }
        | ID { print_if_enabled("\nID_list -> ID\n"); }
        ;

tipo_var : INTEIRO {
            print_if_enabled("\ntipo_var -> INTEIRO\n");
          }
          | REAL {
            print_if_enabled("\ntipo_var -> REAL\n");
          }
          | LITERAL {
            print_if_enabled("\ntipo_var -> LITERAL\n");
          }
          ;

instruction : expr_escreva instruction { print_if_enabled("\ninstruction -> expr_escreva\n");}
             | attrib instruction { print_if_enabled("\ninstruction -> attrib\n");}
             | ;

%%
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
    // addReservedWords();

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

Type checkType(Type left, Type right) {
    if (left == right) return left;
    if ((left == T_INT && right == T_FLOAT) || (left == T_FLOAT && right == T_INT)) return T_FLOAT;
    return T_ERROR;
}

Type determineType(double num) {
    return (num == (int)num) ? T_INT : T_FLOAT;
}
