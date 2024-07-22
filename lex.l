%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "symbol_table.h"
#include "sintatico.tab.h"

int installReserved(const char *yytext, const char *tokenType);
int installID(const char *lexeme);
int installNUM(const char *num, const char* type);
int installLiteral(const char *yytext);
int installEspecialChar(const char *yytext);
%}

%option noyywrap

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

\n { yylineno++; }

{vazio} { }

{abre_par} { installEspecialChar(yytext); print_lex_with_args("\nAbre parenteses: %s\n", yytext); return AP;}
{fecha_par} { installEspecialChar(yytext); print_lex_with_args("\nFecha parenteses: %s\n", yytext); return FP;}
{virgula} { installEspecialChar(yytext); print_lex_with_args("\nVírgula: %s\n", yytext); return VIRG;}
{ponto_e_virg} { installEspecialChar(yytext); print_lex_with_args("\nPonto & Vírgula: %s\n", yytext); return PVIRG;}
{comentario} { print_lex_with_args("\nComentario: %s\n", yytext); return COMM; }

inicioprog { installReserved(yytext, "keyword"); print_lex_with_args("\nPalavra reservada: %s\n", yytext); return INICIOPROG;  }
fimprog { installReserved(yytext, "keyword"); print_lex_with_args("\nPalavra reservada: %s\n", yytext); return FIMPROG; }
inicioargs { installReserved(yytext, "keyword"); print_lex_with_args("\nPalavra reservada: %s\n", yytext); return INICIOARGS; }
fimargs { installReserved(yytext, "keyword"); print_lex_with_args("\nPalavra reservada: %s\n", yytext); return FIMARGS; }
iniciovars { installReserved(yytext, "keyword"); print_lex_with_args("\nPalavra reservada: %s\n", yytext); return INICIOVARS; }
fimvars { installReserved(yytext, "keyword"); print_lex_with_args("\nPalavra reservada: %s\n", yytext); return FIMVARS; }
escreva { installReserved(yytext, "keyword"); print_lex_with_args("\nPalavra reservada: %s\n", yytext); return ESCREVA; }
inteiro { installReserved(yytext, "keyword"); print_lex_with_args("\nPalavra reservada: %s\n", yytext); return INTEIRO; }
real { installReserved(yytext, "keyword"); print_lex_with_args("\nPalavra reservada: %s\n", yytext); return REAL; }
literal { installReserved(yytext, "keyword"); print_lex_with_args("\nPalavra reservada: %s\n", yytext); return LITERAL;
}
se { installReserved(yytext, "keyword"); print_lex_with_args("\nPalavra reservada: %s\n", yytext); return SE; }
entao { installReserved(yytext, "keyword"); print_lex_with_args("\nPalavra reservada: %s\n", yytext); return ENTAO; }
fimse { installReserved(yytext, "keyword"); print_lex_with_args("\nPalavra reservada: %s\n", yytext); return FIMSE; }
enquanto { installReserved(yytext, "keyword"); print_lex_with_args("\nPalavra reservada: %s\n", yytext); return ENQUANTO; }
faca { installReserved(yytext, "keyword"); print_lex_with_args("\nPalavra reservada: %s\n", yytext); return FACA; }
fimenquanto { installReserved(yytext, "keyword"); print_lex_with_args("\nPalavra reservada: %s\n", yytext); return FIMENQUANTO; }

{identificador} {
    installID(yytext);
    print_lex_with_args("\nidentificador: %s\n", yytext);
    yylval.name = strdup(yytext);
    // yylval.type = T_UNDEFINED;
    return ID;
}

{numero} {
    const char* type = (strchr(yytext, '.') != NULL) ? T_FLOAT : T_INT;
    installNUM(yytext, type);
    if (strcmp(type, T_FLOAT) == 0) {
        print_lex_with_args("\nreal: %s\n", yytext);
        yylval.fval = atof(yytext);
        yylval.type = T_FLOAT;
        return REAL;
    } else {
        print_lex_with_args("\ninteiro: %s\n", yytext);
        yylval.ival = atoi(yytext);
        yylval.type = T_INT;
        return INTEIRO;
    }
}

{literal} {
    installLiteral(yytext);
    print_lex_with_args("\nliteral string: %s\n", yytext);
    yylval.type = T_STRING;
    yylval.sval = strdup(yytext);
    return LITERALSTRING;
}

"<" { print_lex_with_args("\noperador relacional: %s\n", yytext); return RELOP;}
"<=" { print_lex_with_args("\noperador relacional: %s\n", yytext); return RELOP;}
"==" { print_lex_with_args("\noperador relacional: %s\n", yytext); return RELOP;}
"<>" { print_lex_with_args("\noperador relacional: %s\n", yytext); return RELOP;}
">" { print_lex_with_args("\noperador relacional: %s\n", yytext); return RELOP;}
">="  {print_lex_with_args("\noperador relacional: %s\n", yytext); return RELOP;}
"=" { print_lex_with_args("\natribuição: %s\n", yytext); return ATTR;}

"+" { print_lex_with_args("\noperador aritmético: %s\n", yytext); return RELALGSUM;}
"-" { print_lex_with_args("\noperador aritmético: %s\n", yytext); return RELALGSUB;}
"/" { print_lex_with_args("\noperador aritmético: %s\n", yytext); return RELALGDIV;}
"*" { print_lex_with_args("\noperador aritmético: %s\n", yytext); return RELALGTIMES;}

. { print_lex_with_args("\nErro: caractere desconhecido: '%s'\n", yytext); return ERROR; }
<<EOF>> { showSymbolTable(); return 999; }

%%
int installID(const char* lexeme) {
    insertSymbol(lexeme, T_UNDEFINED);
    return 0;
}

int installNUM(const char* num, const char* type) {
    insertSymbol(num, T_UNDEFINED);
    return 0;
}

int installReserved(const char* lexeme, const char* tokenType) {
    insertSymbol(lexeme, T_UNDEFINED);
    return 0;
}

int installLiteral(const char* lexeme) {
    insertSymbol(lexeme, T_UNDEFINED);
    return 0;
}

int installEspecialChar(const char* lexeme) {
    insertSymbol(lexeme, T_UNDEFINED);
    return 0;
}
