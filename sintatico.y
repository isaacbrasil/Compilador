%{
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


%}

%token AP FP VIRG PVIRG COMM INICIOPROG FIMPROG INICIOARGS FIMARGS INICIOVARS FIMVARS ESCREVA INTEIRO  
%token REAL SE ENTAO FIMSE ENQUANTO FACA FIMENQUANTO ID NUMBER LITERAL SPECIALCHAR RELOP ATTR ERROR
%token LITERALSTRING
%token AC FC


%right '='
%left RELOP
%left RELALGSUM RELALGSUB '+' '-'
%left RELALGDIV RELALGTIMES '*' '/'

%%

programa : INICIOPROG prog FIMPROG { print_if_enabled("\nFim do Programa\n"); };

prog : declara_args declara_vars statement { print_if_enabled("\nProdução do codigo do programa\n"); };

//Produção de argumentos e variaveis
declara_args : INICIOARGS args_list FIMARGS     {print_if_enabled("\nProdução de argumentos\n");}
             | INICIOARGS FIMARGS               {print_if_enabled("\nArgumentos vazios\n");}
             ;
comment: COMM                                   {print_if_enabled("\nProdução de comentarios\n");};

declara_vars : INICIOVARS vars_list FIMVARS     {print_if_enabled("\nProdução de variaveis\n");}
             | INICIOVARS FIMVARS               {print_if_enabled("\nVariáveis vazias\n");}
             ;

//Produção de qualquer statement
statement : comment statement                   {print_if_enabled("\nstatement -> comment statement\n"); }
        | algebraic_expr statement              {print_if_enabled("\nstatement -> algebraic_expr statement\n");}
        | logic_expr statement                  {print_if_enabled("\nstatement -> logic_expr statement\n");}
        | attrib statement                      {print_if_enabled("\nstatement -> attrib statement\n");}
        | expr_condicional statement            {print_if_enabled("\nstatement -> expr_condicional statement\n");}
        | expr_controle statement               {print_if_enabled("\nstatement -> expr_controle statement\n");}
        | expr_escreva statement                {print_if_enabled("\nstatement -> expr_escreva statement\n");}
        | comment                               { print_if_enabled("\nstatement -> comment\n"); }
        | 
        ;

        //Produção de expressão algébrica
algebraic_expr : NUMBER rel_alg NUMBER  { print_if_enabled("\nalgebraic_expr -> NUMBER rel_alg NUMBER\n");}
                | NUMBER rel_alg ID     { print_if_enabled("\nalgebraic_expr -> NUMBER rel_alg ID\n");}
                | ID rel_alg ID         { print_if_enabled("\nalgebraic_expr -> ID rel_alg ID\n");}
                | ID rel_alg NUMBER     { print_if_enabled("\nalgebraic_expr -> ID rel_alg NUMBER\n");}
                ;



rel_alg : '-' { print_if_enabled("\nrel_alg -> SUBTRAÇÃO\n"); }
        | '+' { print_if_enabled("\nrel_alg -> ADIÇÃO\n"); }
        | '/' { print_if_enabled("\nrel_alg -> DIVISÃO\n"); }
        | '*' { print_if_enabled("\nrel_alg -> MULTIPLICAÇÃO\n"); }
        ;

//Produção de expressão logica
logic_expr : ID RELOP ID            { print_if_enabled("\nlogic_expr -> ID RELOP ID \n");}
            | ID RELOP NUMBER       { print_if_enabled("\nlogic_expr -> ID RELOP NUMBER\n");}
            | NUMBER RELOP ID       { print_if_enabled("\nlogic_expr -> NUMBER RELOP ID\n");}
            | NUMBER RELOP NUMBER   { print_if_enabled("\nlogic_expr -> NUMBER RELOP NUMBER\n");}
            ;

//Produção de atribuição
attrib : ID ATTR ID PVIRG               { print_if_enabled("\nattrib -> ID ATTR ID PVIRG\n");}
        | ID ATTR NUMBER PVIRG          { print_if_enabled("\nattrib -> ID ATTR NUMBER PVIRG\n");}
        | ID ATTR algebraic_expr PVIRG  { print_if_enabled("\nattrib -> ID ATTR algebraic_expr PVIRG\n");}
        | ID ATTR logic_expr PVIRG      { print_if_enabled("\nattrib -> ID ATTR logic_expr PVIRG\n");}
        | ID ATTR LITERALSTRING PVIRG   { print_if_enabled("\nattrib -> ID ATTR LITERALSTRING PVIRG\n");}
        ;

//Produção de expressão condicional
expr_condicional : SE AP logic_expr FP ENTAO instruction FIMSE { print_if_enabled("\nProdução de expressão condicional\n");};
//Produção de expressão de controle
expr_controle : ENQUANTO AP logic_expr FP FACA instruction FIMENQUANTO { print_if_enabled("\nProdução de expressão de controle\n");};

//Produção de escreva
expr_escreva : ESCREVA LITERALSTRING PVIRG    { print_if_enabled("\nexpr_escreva -> ESCREVA LITERALSTRING PVIRG\n");}
            | ESCREVA REAL PVIRG        { print_if_enabled("\nexpr_escreva -> ESCREVA REAL PVIRG\n");}
            | ESCREVA INTEIRO PVIRG     { print_if_enabled("\nexpr_escreva -> ESCREVA INTEIRO PVIRG\n");}
            | ESCREVA ID PVIRG
            ;

//Produção de argumentos
args_list : var_decl args_list { print_if_enabled("\nargs_list -> var_decl args_list\n");}
          | ;

//Produção de variaveis
vars_list :  var_decl vars_list { print_if_enabled("\nvars_list -> var_decl vars_list\n");}
          | ;

//Produção de variaveis
var_decl : tipo_var ID_list PVIRG { print_if_enabled("\nvar_decl -> tipo_var ID_list PVIRG\n");};
 
//Produção de lista de identificadores 
ID_list : ID_list VIRG ID   { print_if_enabled("\nID_list -> ID_list VIRG ID\n");}
        | ID                { print_if_enabled("\nID_list -> ID\n");}
        ;

//Produção de tipos de variaveis
tipo_var : INTEIRO          { print_if_enabled("\ntipo_var -> INTEIRO\n");}
        | REAL              { print_if_enabled("\ntipo_var -> REAL\n");}
        | LITERAL           { print_if_enabled("\ntipo_var -> LITERAL\n");}
        ;
//Produção de uma instrução
instruction : expr_escreva instruction { print_if_enabled("\ninstruction -> expr_escreva\n");}
            |  attrib instruction   { print_if_enabled("\ninstruction -> attrib\n");}
            | comment instruction      { print_if_enabled("\ninstruction -> comment\n");}
            |
            ;
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