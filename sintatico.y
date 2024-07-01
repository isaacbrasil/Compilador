%{
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"
#include "sintatico.tab.h"
extern int yylineno; 
int yylex(void);
extern int yylval;
int yyerror (char *);  

%}

%token AP FP VIRG PVIRG COMM INICIOPROG FIMPROG INICIOARGS FIMARGS INICIOVARS FIMVARS ESCREVA INTEIRO  
%token REAL SE ENTAO FIMSE ENQUANTO FACA FIMENQUANTO ID NUMBER LITERAL SPECIALCHAR RELOP ATTR ERROR
%token LITERALSTRING


// Precedencia
%right '='
%left RELOP
%left '+' '-'
%left '*' '/'


%%
      
//Produção do programa completo
programa : INICIOPROG prog FIMPROG { printf("\nPrograma reconhecido\n");};

//Produção do codigo do programa:
prog : declara_args declara_vars statement { printf("\nProdução do codigo do programa\n");};

//Produção de argumentos e variaveis
declara_args : INICIOARGS args_list FIMARGS     {printf("\nProdução de argumentos\n");}; 
declara_vars : INICIOVARS vars_list FIMVARS     {printf("\nProdução de variaveis\n");};

//Produção de qualquer statement
statement : algebraic_expr statement            {printf("\nstatement -> algebraic_expr statement\n");}
        | logic_expr statement                  {printf("\nstatement -> logic_expr statement\n");}
        | attrib statement                      {printf("\nstatement -> attrib statement\n");}
        | expr_condicional statement            {printf("\nstatement -> expr_condicional statement\n");}
        | expr_controle statement               {printf("\nstatement -> expr_controle statement\n");}
        | expr_escreva statement                {printf("\nstatement -> expr_escreva statement\n");}
        | ;

//Produção de expressão algébrica
algebraic_expr : NUMBER rel_alg NUMBER  { printf("\nalgebraic_expr -> NUMBER rel_alg NUMBER\n");}
                | NUMBER rel_alg ID     { printf("\nalgebraic_expr -> NUMBER rel_alg ID\n");}
                | ID rel_alg ID         { printf("\nalgebraic_expr -> ID rel_alg ID\n");}
                | ID rel_alg NUMBER     { printf("\nalgebraic_expr -> ID rel_alg NUMBER\n");}
                ;

//Produção de operador algébrico
rel_alg : '-' { printf("\nrel_alg -> SUBTRAÇÃO\n");}
        | '+' { printf("\nrel_alg -> ADIÇÃO\n");}  
        | '/' { printf("\nrel_alg -> DIVISÃO\n");}
        | '*' { printf("\nrel_alg -> MULTIPLICAÇÃO\n");}
        ;

//Produção de expressão logica
logic_expr : ID RELOP ID            { printf("\nlogic_expr -> ID RELOP ID \n");}
            | ID RELOP NUMBER       { printf("\nlogic_expr -> ID RELOP NUMBER\n");}
            | NUMBER RELOP ID       { printf("\nlogic_expr -> NUMBER RELOP ID\n");}
            | NUMBER RELOP NUMBER   { printf("\nlogic_expr -> NUMBER RELOP NUMBER\n");}
            ;

//Produção de atribuição
attrib : ID ATTR ID PVIRG               { printf("\nattrib -> ID ATTR ID PVIRG\n");}
        | ID ATTR NUMBER PVIRG          { printf("\nattrib -> ID ATTR NUMBER PVIRG\n");}
        | ID ATTR algebraic_expr PVIRG  { printf("\nattrib -> ID ATTR algebraic_expr PVIRG\n");}
        | ID ATTR logic_expr PVIRG      { printf("\nattrib -> ID ATTR logic_expr PVIRG\n");}
        | ID ATTR LITERALSTRING PVIRG   { printf("\nattrib -> ID ATTR LITERALSTRING PVIRG\n");}
        ;

//Produção de expressão condicional
expr_condicional : SE AP logic_expr FP ENTAO instruction FIMSE { printf("\nProdução de expressão condicional\n");};

//Produção de expressão de controle
expr_controle : ENQUANTO AP logic_expr FP FACA instruction FIMENQUANTO { printf("\nProdução de expressão de controle\n");};

//Produção de escreva
expr_escreva : ESCREVA LITERALSTRING PVIRG    { printf("\nexpr_escreva -> ESCREVA LITERALSTRING PVIRG\n");}
            | ESCREVA REAL PVIRG        { printf("\nexpr_escreva -> ESCREVA REAL PVIRG\n");}
            | ESCREVA INTEIRO PVIRG     { printf("\nexpr_escreva -> ESCREVA INTEIRO PVIRG\n");}
            | ESCREVA ID PVIRG
            ;

//Produção de argumentos
args_list : var_decl args_list { printf("\nargs_list -> var_decl args_list\n");}
          | ;

//Produção de variaveis
vars_list :  var_decl vars_list { printf("\nvars_list -> var_decl vars_list\n");}
          | ;

//Produção de variaveis
var_decl : tipo_var ID_list PVIRG { printf("\nvar_decl -> tipo_var ID_list PVIRG\n");};
 
//Produção de lista de identificadores 
ID_list : ID_list VIRG ID   { printf("\nID_list -> ID_list VIRG ID\n");}
        | ID                { printf("\nID_list -> ID\n");};

//Produção de tipos de variaveis
tipo_var : INTEIRO          { printf("\ntipo_var -> INTEIRO\n");}
        | REAL              { printf("\ntipo_var -> REAL\n");}
        | LITERAL           { printf("\ntipo_var -> LITERAL\n");}
        ;
//Produção de uma instrução
instruction : expr_escreva instruction { printf("\ninstruction -> expr_escreva\n");}
            |  attrib instruction   { printf("\ninstruction -> attrib\n");}
            |  ;

//Produção de contagem de linhas          
lines : lines programa '\n' { printf("= %g\n", $2); }
    | lines '\n'
    | /* empty */
    | error '\n' { yyerrok; }
    ;

//Produção de valores numéricos
//numeric_value : signal value;

//Produção de sinais dos valores numéricos
//signal : '+'
//       | '-'
//       |;

//Produção de valor que uma variavel pode assumir
//value : NUMBER
//    | ID
//    ;


%%
int main() {
    initializeSymbolTable(); // Inicializa a tabela de símbolos
    addReservedWords();      // Adiciona palavras reservadas

    if (yyparse() != 0) {
        fprintf(stderr, "Abnormal exit\n");
    }
    return 0;
}

int yyerror(char *s) {
    fprintf(stderr, "Error: %s -- Line: %d\n", s, yylineno);
}
