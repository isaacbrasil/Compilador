%{ 
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
int installID() {/* install lexeme in the symbol table */}
int installNUM() {/* install num const in aux table */}