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
%token REAL SE ENTAO FIMSE ENQUANTO FACA FIMENQUANTO ID NUMBER LITERAL SPECIALCHAR RELOP ATTR ERROR RELALG


// Precedencia
%right '='
%left MAIORG DIFERENTE MENORQ MENORG EP
%left '+' '-'
%left '*' '/'
%right '^'

%%

//Produção de argumentos e variaveis
declara_args: INICIOARGS arg_var FIMARGS;
declara_vars: INICIOVARS arg_var FIMVARS;

//Produção de variaveis
arg_var: tipo_var ID itera_vars PVIRG;

//Produção de variaveis separadas por virgula
itera_vars: VIRG ID itera_vars
        | //VAZIO
        ;

//Produção de tipos de variaveis
tipo_var: INTEIRO
        | REAL
        | LITERAL
        ;

//Produção de valores numéricos
numeric_value: signal value;

//Produção de sinais dos valores numéricos
signal: '+'
    | '-'
    | //VAZIO
    ;

//Produção de valor que uma variavel pode assumir
value: NUMBER
    | ID
    ;

//Produção de expressão algébrica
algebraic_expr: NUMBER RELALG NUMBER
            | NUMBER RELALG ID
            | ID RELALG ID
            | ID RELALG NUMBER
            ;

//Produção de expressão logica
logic_expr: ID RELOP ID
        | ID RELOP NUMBER
        | NUMBER RELOP ID
        | NUMBER RELOP NUMBER
        ;

//Produção de atribuição
attrib: ID ATTR ID PVIRG
    | ID ATTR NUMBER PVIRG
    | ID ATTR algebraic_expr PVIRG
    | ID ATTR logic_expr PVIRG
    ;

//Produção de expressão condicional
expr_condicional: SE AP logic_expr FP ENTAO instruction FIMSE;

//Produção de expressão de controle
expr_controle: ENQUANTO AP logic_expr FP FACA instruction FIMENQUANTO;

//Produção de escreva
expr_escreva: ESCREVA LITERAL PVIRG
            | ESCREVA REAL PVIRG
            | ESCREVA INTEIRO PVIRG
            ;

//Produção de uma instrução
instruction: expr_escreva
        |  attrib
        ;
        
//Produção do programa completo
programa : INICIOPROG prog FIMPROG;

//Produção do codigo do programa:
prog: declara_args declara_vars statement;

//Produção de qualquer statement
statement: algebraic_expr statement
        | logic_expr statement
        | attrib statement
        | expr_condicional statement
        | expr_controle statement
        | expr_escreva statement
        | //Vazio
        ;

%%
int main()
{ 
  if (yyparse() != 0)
    fprintf(stderr, "Abnormal exit\n");
  return 0;
}

int yyerror(char *s)
{ fprintf(stderr, "Error: %s -- Line: %d\n", s, yylineno); }

