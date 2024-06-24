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

lines : lines expr '\n' { printf("= %g\n", $2); }
| lines '\n'
| /* empty */
;
expr : expr '+' expr { $$ = $1 + $3; }
| expr '-' expr { $$ = $1 - $3; }
| expr '*' expr { $$ = $1 * $3; }
| expr '/' expr { $$ = $1 / $3; }
| '(' expr ')' { $$ = $2; }
| '-' expr %prec UMINUS { $$ = -$2; }
| NUMBER
;

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