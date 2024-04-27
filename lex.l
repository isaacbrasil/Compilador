%{
#include <stdio.h>
#include "symbol_table.h"
#define INICIOPROG 1
#define FIMPROG 2
#define INICIOARGS 3
#define FIMARGS 4
#define INICIOVARS 5
#define FIMVARS 6
#define ESCREVA 7
#define INTEIRO 8
#define REAL 9
#define SE 21
#define LITERAL 10
#define ENTAO 11
#define FIMSE 12
#define ENQUANTO 13
#define FACA 14
#define FIMENQUANTO 15
#define ELSE 16

#define ID 17
#define NUMBER 18
#define RELOP 19

#define LT 60
#define LE 61
#define EQ 62
#define NE 63
#define GT 64
#define GE 65

int installReserved(const char *yytext, const char *tokenType);
int installID(const char *lexeme);
int installNUM(const char *num);
int installLiteral(const char *yytext);

%}

%option noyywrap

D [0-9]
L [A-Za-z]
S [~`!@#$%^&*()_-+\/[]|‘?><.,]
numero {D}+(\.{D}+)?([Ee][+-]?{D}+)?
literal "\"([^\"\\\\]|\\\\.)*\"".
identificador {L}({L}|{D})*
delim [ \t\r\n]
vazio {delim}+
abre_par [(]
fecha_par [)]
erro [.\n]
%%

vazio { printf("vazio"); } 
inicioprog { installReserved(yytext, "keyword"); printf("Palavra reservada: %s\n", yytext); return INICIOPROG;  }
fimprog { installReserved(yytext, "keyword"); printf("Palavra reservada: %s\n", yytext); return FIMPROG; }
inicioargs { installReserved(yytext, "keyword"); printf("Palavra reservada: %s\n", yytext); return INICIOARGS; }
fimargs { installReserved(yytext, "keyword"); printf("Palavra reservada: %s\n", yytext); return FIMARGS; }
iniciovars { installReserved(yytext, "keyword"); printf("Palavra reservada: %s\n", yytext); return INICIOVARS; }
fimvars { installReserved(yytext, "keyword"); printf("Palavra reservada: %s\n", yytext); return FIMVARS; }
escreva { installReserved(yytext, "keyword"); printf("Palavra reservada: %s\n", yytext); return ESCREVA; }
inteiro { installReserved(yytext, "keyword"); printf("Palavra reservada: %s\n", yytext); return INTEIRO; }
real { installReserved(yytext, "keyword"); printf("Palavra reservada: %s\n", yytext); return REAL; }
se { installReserved(yytext, "keyword"); printf("Palavra reservada: %s\n", yytext); return SE; }
entao { installReserved(yytext, "keyword"); printf("Palavra reservada: %s\n", yytext); return ENTAO; }
fimse { installReserved(yytext, "keyword"); printf("Palavra reservada: %s\n", yytext); return FIMSE; }
enquanto { installReserved(yytext, "keyword"); printf("Palavra reservada: %s\n", yytext); return ENQUANTO; }
faca { installReserved(yytext, "keyword"); printf("Palavra reservada: %s\n", yytext); return FACA; }
fimenquanto { installReserved(yytext, "keyword"); printf("Palavra reservada: %s\n", yytext); return FIMENQUANTO; }
else { installReserved(yytext, "keyword"); printf("Palavra reservada: %s\n", yytext); return ELSE; }

{identificador} {installID(yytext); printf("identificador: %s\n", yytext); return ID;}
{numero} {installNUM(yytext); printf("numero: %s\n", yytext); return NUMBER;}
{literal} { installLiteral(yytext); printf("literal: %s\n", yytext); return LITERAL; } 
"<" {LT; printf("operador relacional: %s\n", yytext); return RELOP;}
"<=" {LE; printf("operador relacional: %s\n", yytext); return RELOP;}
"==" {EQ; printf("operador relacional: %s\n", yytext); return RELOP;}
"<>" {NE; printf("operador relacional: %s\n", yytext); return RELOP;}
">" {GT; printf("operador relacional: %s\n", yytext); return RELOP;}
">=" {GE; printf("operador relacional: %s\n", yytext); return RELOP;}
{erro} { printf("Erro: caractere desconhecido: '%s'\n", yytext); }

%%
int installID(const char* lexeme) {
    insertSymbol(lexeme, "identifier", 0, NULL);
    return 0; 
}
int installNUM(const char* num) {
    insertSymbol(num, "number", strlen(num), NULL);
    return 0; 
}
int installReserved(const char* lexeme, const char* tokenType) {
    insertSymbol(lexeme, tokenType, 0, NULL);
    return 0; 
}
int installLiteral(const char* lexeme) {
    insertSymbol(lexeme, "literal", 0, NULL);
    return 0; 
}

int main(){
    initializeSymbolTable();
    addReservedWords();
    while(1){
        yylex();
    }
    return 0;
}