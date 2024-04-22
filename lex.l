%{
#include "symbol_table.h" 
#define LT 60

%}
delim [ \t\r\n]
vazio {delim}+
L [A-Za-z]
D [0-9]
identificador {L}({L}|{D})*
literal {({L}|{D}|{S}| |\t)*}
numero {D}+(\.{D}+)?([Ee][+-]?{D}+)?
S '~`!@#$%^&*()_+\\|\'?><.,\[\]{};'

%%
{vazio} {/* não faz nada */}
if {return IF;}
then {return THEN;}
else {return ELSE;}
{identificador} {yylval = installID(); return ID;}
{numero} {yylval = installNUM(); return NUMBER;}
"<" {yylval = LT; return RELOP;}
"<=" {yylval = LE; return RELOP;}
"==" {yylval = EQ; return RELOP;}
"<>" {yylval = NE; return RELOP;}
">" {yylval = GT; return RELOP;}
">=" {yylval = GE; return RELOP;}
%%
int installID(const char* lexeme) {
    // Suponha que 'currentScope' é uma variável global que rastreia o escopo atual
    // 'attributes' pode ser uma string ou estrutura contendo outros atributos relevantes
    insertSymbol(lexeme, "identifier", "simple", 0, currentScope, NULL, "none");
    return 0; // ou outro valor apropriado
}
int installNUM(const char* num) {
    // Aqui, o tipo poderia ser determinado dinamicamente baseado no formato do número
    insertSymbol(num, "number", "simple", sizeof(num), currentScope, NULL, "constant");
    return 0; // ou outro valor apropriado
}