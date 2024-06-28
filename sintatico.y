%{

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
extern int yylineno; 
int yylex(void);
extern int yylval;
void yyerror (char *);
    
%}

%token AP FP VIRG PVIRG COMM INICIOPROG FIMPROG INICIOARGS FIMARGS INICIOVARS FIMVARS ESCREVA INTEIRO  
%token REAL SE ENTAO FIMSE ENQUANTO FACA FIMENQUANTO ID NUMBER LITERAL SPECIALCHAR RELOP ATTR ERROR

// Precedencia
%right '='
%left MAIORG DIFERENTE MENORQ MENORG EP
%left '+' '-'
%left '*' '/'
%right '^'

%%

declara_args: INICIOARGS arg_var FIMARGS
declara_vars: INICIOVARS arg_var FIMVARS

arg_var: LITERAL ID PVIRG
| INTEIRO NUMBER PVIRG
| REAL NUMBER PVIRG





numeric_value: signal value
signal: '+'
| '-'
| VAZIO
value: NUMBER
| ID

algebraic_expr: NUMBER RELOP NUMBER
| NUMBER RELOP ID
| ID RELOP ID
| ID RELOP NUMBER

//logic_expr: 
| ID RELOP ID
| ID RELOP NUMBER

//logic_expr: 


expr_condicional: SE AP (NUMBER RELOP)

programa : INICIOPROG args { printf("Programa reconhecido\n"); }
;

args : INICIOARGS listvars FIMARGS { printf("Argumentos reconhecidos\n"); }
| codigo { printf("Código como argumento reconhecido\n"); }
;

codigo : INICIOVARS listvars FIMVARS restante { printf("Bloco de código reconhecido\n"); }
;

listvars : /* sua definição de variáveis aqui */
;

%%