%{
#include "symbol_table.h" 
#define LT 60

void initializeCompiler(); 

%}
L [A-Za-z]
D [0-9]
S '~`!@#$%^&*()_+\\|\'?><.,\[\]{};'
numero {D}+(\.{D}+)?([Ee][+-]?{D}+)?
literal {({L}|{D}|{S}| |\t)*}
identificador {L}({L}|{D})*
delim [ \t\r\n]
vazio {delim}+

%%

{vazio} {/* não faz nada */}
"if" { installReserved(yytext, "keyword"); return IF; }
"then" { installReserved(yytext, "keyword"); return THEN; }
"else" { installReserved(yytext, "keyword"); return ELSE; }

{identificador} {yylval = installID(); return ID;}
{numero} {yylval = installNUM(); return NUMBER;}
"<" {yylval = LT; return RELOP;}
"<=" {yylval = LE; return RELOP;}
"==" {yylval = EQ; return RELOP;}
"<>" {yylval = NE; return RELOP;}
">" {yylval = GT; return RELOP;}
">=" {yylval = GE; return RELOP;}
.|\n { printf("Erro genérico.") }

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
void installReserved(const char* lexeme, const char* tokenType) {
    // 'tokenType' poderia ser "keyword" ou um tipo mais específico se necessário
    // Suponha que 'currentScope' é uma variável global que rastreia o escopo atual
    // 'attributes' poderia ser uma string ou estrutura contendo outros atributos relevantes, como "reserved"
    insertSymbol(lexeme, tokenType, "reserved", 0, currentScope, NULL, "reserved");
}
