%{
#include <stdio.h>
#include "symbol_table.h"
#include "sintatico.tab.h"

/*#define INICIOPROG 1
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

#define ID 16
#define NUMBER 17
#define RELOP 18

#define LT 60
#define LE 61
#define EQ 62
#define NE 63
#define GT 64
#define GE 65
#define SPECIALCHAR 66
#define ATTR 67
#define DELIM 68

#define AP 69
#define FP 70
#define VIRG 71
#define PVIRG 72
#define COMM 73

#define RELALG 124

#define ERROR 404
*/

int installReserved(const char *yytext, const char *tokenType);
int installID(const char *lexeme);
int installNUM(const char *num);
int installLiteral(const char *yytext);
int installEspecialChar(const char *yytext);

%}


D [0-9]
L [A-Za-z]
S [-\\~`!@#$%^&*()_+/[]|‘?><.,]
numero {D}+(\.{D}+)?([Ee][+-]?{D}+)?
literal \"([^"\\]|\\.)*\"
identificador {L}({L}|_|{D})*
delim [ \t\r\n]
vazio {delim}+
erro .|\n
abre_par [(]
fecha_par [)]
virgula [,]
ponto_e_virg [;]
comentario \{({L}|{D}|{S}|{vazio})*\}
fim_de_arq <<EOF>>

%%

{vazio} { } 

{abre_par} { installEspecialChar(yytext); printf("\nAbre parenteses: %s\n", yytext); return AP;}
{fecha_par} { installEspecialChar(yytext); printf("\nFecha parenteses: %s\n", yytext); return FP;}
{virgula} { installEspecialChar(yytext); printf("\nVírgula: %s\n", yytext); return VIRG;}
{ponto_e_virg} { installEspecialChar(yytext); printf("\nPonto & Vírgula: %s\n", yytext); return PVIRG;}
{comentario} { printf("\nComentario: %s\n", yytext); return COMM; }

inicioprog { installReserved(yytext, "keyword"); printf("\nPalavra reservada: %s\n", yytext); return INICIOPROG;  }
fimprog { installReserved(yytext, "keyword"); printf("\nPalavra reservada: %s\n", yytext); return FIMPROG; }
inicioargs { installReserved(yytext, "keyword"); printf("\nPalavra reservada: %s\n", yytext); return INICIOARGS; }
fimargs { installReserved(yytext, "keyword"); printf("\nPalavra reservada: %s\n", yytext); return FIMARGS; }
iniciovars { installReserved(yytext, "keyword"); printf("\nPalavra reservada: %s\n", yytext); return INICIOVARS; }
fimvars { installReserved(yytext, "keyword"); printf("\nPalavra reservada: %s\n", yytext); return FIMVARS; }
escreva { installReserved(yytext, "keyword"); printf("\nPalavra reservada: %s\n", yytext); return ESCREVA; }
inteiro { installReserved(yytext, "keyword"); printf("\nPalavra reservada: %s\n", yytext); return INTEIRO; }
real { installReserved(yytext, "keyword"); printf("\nPalavra reservada: %s\n", yytext); return REAL; }
se { installReserved(yytext, "keyword"); printf("\nPalavra reservada: %s\n", yytext); return SE; }
entao { installReserved(yytext, "keyword"); printf("\nPalavra reservada: %s\n", yytext); return ENTAO; }
fimse { installReserved(yytext, "keyword"); printf("\nPalavra reservada: %s\n", yytext); return FIMSE; }
enquanto { installReserved(yytext, "keyword"); printf("\nPalavra reservada: %s\n", yytext); return ENQUANTO; }
faca { installReserved(yytext, "keyword"); printf("\nPalavra reservada: %s\n", yytext); return FACA; }
fimenquanto { installReserved(yytext, "keyword"); printf("\nPalavra reservada: %s\n", yytext); return FIMENQUANTO; }

{identificador} {installID(yytext); printf("\nidentificador: %s\n", yytext); return ID;}
{numero} {installNUM(yytext); printf("\nnumero: %s\n", yytext); return NUMBER;}
{literal} { installLiteral(yytext); printf("\nliteral: %s\n", yytext); return LITERAL; } 

{S} { installEspecialChar(yytext); printf("\nCaractere especial: %s\n", yytext); return SPECIALCHAR; }


"+" { printf("\noperador relacional: %s\n", yytext); return RELALG;}
"-" { printf("\noperador relacional: %s\n", yytext); return RELALG;}
"*" { printf("\noperador relacional: %s\n", yytext); return RELALG;}
"/" { printf("\noperador relacional: %s\n", yytext); return RELALG;}


"<" { printf("\noperador relacional: %s\n", yytext); return RELOP;}
"<=" { printf("\noperador relacional: %s\n", yytext); return RELOP;}
"==" { printf("\noperador relacional: %s\n", yytext); return RELOP;}
"<>" { printf("\noperador relacional: %s\n", yytext); return RELOP;}
">" { printf("\noperador relacional: %s\n", yytext); return RELOP;}
">="  {printf("\noperador relacional: %s\n", yytext); return RELOP;}
"=" { printf("\natribuição: %s\n", yytext); return ATTR;}

.|\n { printf("\nErro: caractere desconhecido: '%s'\n", yytext); return ERROR; }
<<EOF>> { printf("\nFIM DE ARQUIVO.\n"); return 999; }

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
int installEspecialChar(const char* lexeme) {
    insertSymbol(lexeme, "specialChar", 0, NULL);
    return 0; 
}

int main(){
    initializeSymbolTable();
    addReservedWords();

    int result;
    while((result = yylex()) != 999);
    return 0;
}