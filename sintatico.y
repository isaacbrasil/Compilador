%{

 #include <stdio.h>
#include <stdlib.h>
int yylex(void);
extern int yylval;
void yyerror (char *);
    
}%

%token AP FP VIRG PVIRG COMM INICIOPROG FIMPROG INICIOARGS FIMARGS INICIOVARS FIMVARS ESCREVA INTEIRO  
%token REAL SE ENTAO FIMSE ENQUANTO FACA FIMENQUANTO ID NUMBER LITERAL SPECIALCHAR RELOP ATTR ERROR

// Precedencia
%right '='
%left MAIORG DIFERENTE MENORQ MENORG EP
%left '+' '-'
%left '*' '/'
%right '^'

%%
ST : ST {printf("\nACEITO\n"); exit(0) ;}
ST: FOR EP Expr1 PV Expr2 PV Expr3 DP ECHAVES DCHAVES
| WHILE EP Expr2 DP ECHAVES DCHAVES
| SWITCH EP VARIAVEL DP ECHAVES E DCHAVES
| BINARIO
| HEXADECIMAL
| OCTAL

E : A
| A C
| A E

A : A B
| CASE NUM D B

B: BREAK PV

C: DEFAULT D B

D: DD VARIAVEL PV
| DD PV
| DD

RELOP : MENORQ
| MAIORQ
| IGUAL
| MENORG
| MAIORG
| DIFERENTE


Expr1 : VARIAVEL IGUAL VARIAVEL {printf("teste1 Expr1");}
| VARIAVEL IGUAL NUM {printf("teste2 Expr1");}

Expr2 : VARIAVEL RELOP VARIAVEL {printf("teste1 Expr2");}
| VARIAVEL RELOP NUM {printf("teste2 Expr2");}

Expr3 : VARIAVEL INC {printf("teste1 Expr3");}
| VARIAVEL DEC {printf("teste2 Expr3");}