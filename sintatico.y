%{
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "types.h"  // Inclua o arquivo de cabeçalho aqui
#include "symbol_table.h"
#include "sintatico.tab.h"
extern int yylineno;
int yylex(void);
int yyerror (char *);

// Funções auxiliares para verificação de tipo
Type checkType(Type left, Type right);
Type determineType(double num);

%}

// Definição da união deve vir após a definição do tipo `Type`
%union {
    int ival;
    float fval;
    char *sval;
    Type type;
}

%token <ival> INTEIRO
%token <fval> REAL
%token <sval> LITERALSTRING
%type <type> algebraic_expr logic_expr attrib
%type <type> tipo_var
%type <type> ID

%token AP FP VIRG PVIRG COMM INICIOPROG FIMPROG INICIOARGS FIMARGS INICIOVARS FIMVARS ESCREVA
%token SE ENTAO FIMSE ENQUANTO FACA FIMENQUANTO ID NUMBER RELOP ATTR ERROR LITERAL

// Precedencia
%right '='
%left RELOP
%left '+' '-'
%left '*' '/'

%%

programa : INICIOPROG prog FIMPROG { printf("\nFim do Programa\n"); };

prog : declara_args declara_vars statement { printf("\nProdução do codigo do programa\n"); };

declara_args : INICIOARGS args_list FIMARGS { printf("\nProdução de argumentos\n"); };

declara_vars : INICIOVARS vars_list FIMVARS { printf("\nProdução de variaveis\n"); };

statement : algebraic_expr statement { printf("\nstatement -> algebraic_expr statement\n"); }
          | logic_expr statement { printf("\nstatement -> logic_expr statement\n"); }
          | attrib statement { printf("\nstatement -> attrib statement\n"); }
          | expr_condicional statement { printf("\nstatement -> expr_condicional statement\n"); }
          | expr_controle statement { printf("\nstatement -> expr_controle statement\n"); }
          | expr_escreva statement { printf("\nstatement -> expr_escreva statement\n"); }
          | ;

algebraic_expr : INTEIRO rel_alg INTEIRO {
                    $$ = T_INT;
                    printf("\nalgebraic_expr -> INTEIRO rel_alg INTEIRO\n");
                }
                | INTEIRO rel_alg ID {
                    $$ = checkType(T_INT, $3);
                    if ($$ == T_ERROR) yyerror("Incompatibilidade de tipos na expressão aritmética");
                    printf("\nalgebraic_expr -> INTEIRO rel_alg ID\n");
                }
                | ID rel_alg ID {
                    $$ = checkType($1, $3);
                    if ($$ == T_ERROR) yyerror("Incompatibilidade de tipos na expressão aritmética");
                    printf("\nalgebraic_expr -> ID rel_alg ID\n");
                }
                | ID rel_alg INTEIRO {
                    $$ = checkType($1, T_INT);
                    if ($$ == T_ERROR) yyerror("Incompatibilidade de tipos na expressão aritmética");
                    printf("\nalgebraic_expr -> ID rel_alg INTEIRO\n");
                }
                | REAL rel_alg REAL {
                    $$ = T_FLOAT;
                    printf("\nalgebraic_expr -> REAL rel_alg REAL\n");
                }
                | REAL rel_alg ID {
                    $$ = checkType(T_FLOAT, $3);
                    if ($$ == T_ERROR) yyerror("Incompatibilidade de tipos na expressão aritmética");
                    printf("\nalgebraic_expr -> REAL rel_alg ID\n");
                }
                | ID rel_alg REAL {
                    $$ = checkType($1, T_FLOAT);
                    if ($$ == T_ERROR) yyerror("Incompatibilidade de tipos na expressão aritmética");
                    printf("\nalgebraic_expr -> ID rel_alg REAL\n");
                }
                ;

rel_alg : '-' { printf("\nrel_alg -> SUBTRAÇÃO\n"); }
        | '+' { printf("\nrel_alg -> ADIÇÃO\n"); }
        | '/' { printf("\nrel_alg -> DIVISÃO\n"); }
        | '*' { printf("\nrel_alg -> MULTIPLICAÇÃO\n"); }
        ;

logic_expr : ID RELOP ID {
                printf("\nlogic_expr -> ID RELOP ID\n");
                $$ = checkType($1, $3);
                if ($$ == T_ERROR) yyerror("Incompatibilidade de tipos na expressão lógica");
            }
            | ID RELOP INTEIRO {
                printf("\nlogic_expr -> ID RELOP INTEIRO\n");
                $$ = checkType($1, T_INT);
                if ($$ == T_ERROR) yyerror("Incompatibilidade de tipos na expressão lógica");
            }
            | INTEIRO RELOP ID {
                printf("\nlogic_expr -> INTEIRO RELOP ID\n");
                $$ = checkType(T_INT, $3);
                if ($$ == T_ERROR) yyerror("Incompatibilidade de tipos na expressão lógica");
            }
            | INTEIRO RELOP INTEIRO {
                printf("\nlogic_expr -> INTEIRO RELOP INTEIRO\n");
                $$ = T_INT;
            }
            | ID RELOP REAL {
                printf("\nlogic_expr -> ID RELOP REAL\n");
                $$ = checkType($1, T_FLOAT);
                if ($$ == T_ERROR) yyerror("Incompatibilidade de tipos na expressão lógica");
            }
            | REAL RELOP ID {
                printf("\nlogic_expr -> REAL RELOP ID\n");
                $$ = checkType(T_FLOAT, $3);
                if ($$ == T_ERROR) yyerror("Incompatibilidade de tipos na expressão lógica");
            }
            | REAL RELOP REAL {
                printf("\nlogic_expr -> REAL RELOP REAL\n");
                $$ = T_FLOAT;
            }
            ;

attrib : ID ATTR ID PVIRG {
            printf("\nattrib -> ID ATTR ID PVIRG\n");
            $$ = checkType($1, $3);
            if ($$ == T_ERROR) yyerror("Incompatibilidade de tipos na atribuição");
        }
        | ID ATTR INTEIRO PVIRG {
            printf("\nattrib -> ID ATTR INTEIRO PVIRG\n");
            $$ = checkType($1, T_INT);
            if ($$ == T_ERROR) yyerror("Incompatibilidade de tipos na atribuição");
        }
        | ID ATTR algebraic_expr PVIRG {
            printf("\nattrib -> ID ATTR algebraic_expr PVIRG\n");
            $$ = checkType($1, $3);
            if ($$ == T_ERROR) yyerror("Incompatibilidade de tipos na atribuição");
        }
        | ID ATTR logic_expr PVIRG {
            printf("\nattrib -> ID ATTR logic_expr PVIRG\n");
            $$ = checkType($1, $3);
            if ($$ == T_ERROR) yyerror("Incompatibilidade de tipos na atribuição");
        }
        | ID ATTR LITERALSTRING PVIRG {
            printf("\nattrib -> ID ATTR LITERALSTRING PVIRG\n");
            $$ = checkType($1, T_STRING);
            if ($$ == T_ERROR) yyerror("Incompatibilidade de tipos na atribuição");
        }
        ;

expr_condicional : SE AP logic_expr FP ENTAO instruction FIMSE { printf("\nProdução de expressão condicional\n"); };

expr_controle : ENQUANTO AP logic_expr FP FACA instruction FIMENQUANTO { printf("\nProdução de expressão de controle\n"); };

expr_escreva : ESCREVA LITERALSTRING PVIRG { printf("\nexpr_escreva -> ESCREVA LITERALSTRING PVIRG\n"); }
              | ESCREVA REAL PVIRG { printf("\nexpr_escreva -> ESCREVA REAL PVIRG\n"); }
              | ESCREVA INTEIRO PVIRG { printf("\nexpr_escreva -> ESCREVA INTEIRO PVIRG\n"); }
              | ESCREVA ID PVIRG { printf("\nexpr_escreva -> ESCREVA ID PVIRG\n"); }
              ;

args_list : var_decl args_list { printf("\nargs_list -> var_decl args_list\n"); }
          | ;

vars_list : var_decl vars_list { printf("\nvars_list -> var_decl vars_list\n"); }
          | ;

var_decl : tipo_var ID_list PVIRG { printf("\nvar_decl -> tipo_var ID_list PVIRG\n"); };

ID_list : ID_list VIRG ID { printf("\nID_list -> ID_list VIRG ID\n"); }
        | ID { printf("\nID_list -> ID\n"); }
        ;

tipo_var : INTEIRO {
            printf("\ntipo_var -> INTEIRO\n");
            $$ = T_INT;
          }
          | REAL {
            printf("\ntipo_var -> REAL\n");
            $$ = T_FLOAT;
          }
          | LITERAL {
            printf("\ntipo_var -> LITERAL\n");
            $$ = T_STRING;
          }
          ;

//Produção de uma instrução
instruction : expr_escreva instruction { printf("\ninstruction -> expr_escreva\n");}
             | attrib instruction { printf("\ninstruction -> attrib\n");}
             | ;

%%

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
