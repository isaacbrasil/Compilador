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

    int enable_prints = 1; // Flag para controlar os prints

    typedef enum { TYPE_INT, TYPE_FLOAT, TYPE_BOOL, TYPE_STRING } DataType;

    typedef struct {
        DataType type;
        char* code; // código Bril gerado
    } Expr;

    void print_if_enabled(const char *msg) {
        if (enable_prints) {
            printf("%s", msg);
        }
    }

    Expr new_expr(DataType type, char* code) {
        Expr e;
        e.type = type;
        e.code = strdup(code); // assegura cópia própria da string
        return e;
    }

    // Função para gerar nomes de variáveis temporárias
    char* new_temp() {
        static int count = 0;
        char* buffer = malloc(20);
        sprintf(buffer, "temp%d", count++);
        return buffer;
    }

    // Função para verificar compatibilidade de tipos para operações aritméticas
    DataType check_arithmetic_compatibility(DataType type1, DataType type2) {
        if (type1 == TYPE_INT && type2 == TYPE_INT) {
            return TYPE_INT;
        } else if ((type1 == TYPE_FLOAT && type2 == TYPE_INT) || (type1 == TYPE_INT && type2 == TYPE_FLOAT)) {
            return TYPE_FLOAT;
        } else {
            return TYPE_ERROR; // Indica um erro de tipo
        }
    }

int insert_symbol_table(const char* lexeme, DataType type) {
    // Simulação de como você poderia lidar com os tipos de dados e símbolos
    const char* typeString;
    switch (type) {
        case TYPE_INT:
            typeString = "int";
            break;
        case TYPE_FLOAT:
            typeString = "float";
            break;
        case TYPE_STRING:
            typeString = "string";
            break;
        case TYPE_BOOL:
            typeString = "bool";
            break;
        default:
            typeString = "unknown";
    }
    // Verifica se o símbolo já existe na tabela
    if (symbolExists(lexeme)) {
        return -1; // Indica erro se o símbolo já existe
    } else {
        insertSymbol(lexeme, typeString, 0, NULL);
        return 0; // Sucesso
    }
}


%}

%union {
    int ival;
    char* sval;
    Expr expr;
    char* opval;  // Adicionar para operadores

}

%type <opval> rel_alg
%type <list> ID_list  // Suponha que `list` seja uma estrutura para transportar listas de IDs e tipos
%type <expr> expr_condicional logic_expr algebraic_expr
%token <sval> ID
%token <ival> NUMBER

%token AP FP VIRG PVIRG COMM INICIOPROG FIMPROG INICIOARGS FIMARGS INICIOVARS FIMVARS ESCREVA INTEIRO  
%token REAL SE ENTAO FIMSE ENQUANTO FACA FIMENQUANTO ID NUMBER LITERAL SPECIALCHAR RELOP ATTR ERROR
%token LITERALSTRING
%token AC FC LT LE EQ NE GT GE PLUS MINUS MULT DIV

// Precedencia
%right '=' EQ
%left RELOP LT LE NE GT GE
%left '+' '-'
%left '*' '/'


%%
      
//Produção do programa completo
programa : INICIOPROG prog FIMPROG  { print_if_enabled("\nFim do Programa\n");};

//Produção do codigo do programa:
prog : declara_args declara_vars statement { print_if_enabled("\nProdução do codigo do programa\n");};

//Produção de argumentos e variaveis
declara_args : INICIOARGS args_list FIMARGS     {print_if_enabled("\nProdução de argumentos\n");}
             | INICIOARGS FIMARGS               {print_if_enabled("\nArgumentos vazios\n");}
             ;

//Produção de comentarios
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
algebraic_expr : NUMBER rel_alg NUMBER
        {
            DataType resultType = check_arithmetic_compatibility(TYPE_INT, TYPE_INT); // Simplificação, ajuste conforme necessário
            if (resultType == TYPE_ERROR) {
                yyerror("Incompatible types for arithmetic operation");
            } else {
                char* temp = new_temp();
                printf("%s = %s %d %d;\n", temp, $2, $1, $3);
                $$ = new_expr(resultType, temp);
            }
            print_if_enabled("algebraic_expr -> NUMBER rel_alg NUMBER\n");
        }
    | NUMBER rel_alg ID
        {
            DataType idType = lookup_type($3);
            DataType resultType = check_arithmetic_compatibility(TYPE_INT, idType);
            if (resultType == TYPE_ERROR) {
                yyerror("Incompatible types for arithmetic operation");
            } else {
                char* temp = new_temp();
                printf("%s = %s %d %s;\n", temp, $2, $1, $3);
                $$ = new_expr(resultType, temp);
            }
            print_if_enabled("algebraic_expr -> NUMBER rel_alg ID\n");
        }
    | ID rel_alg ID
        {
            DataType type1 = lookup_type($1);
            DataType type2 = lookup_type($3);
            DataType resultType = check_arithmetic_compatibility(type1, type2);
            if (resultType == TYPE_ERROR) {
                yyerror("Incompatible types for arithmetic operation");
            } else {
                char* temp = new_temp();
                printf("%s = %s %s %s;\n", temp, $2, $1, $3);
                $$ = new_expr(resultType, temp);
            }
            print_if_enabled("algebraic_expr -> ID rel_alg ID\n");
        }
    | ID rel_alg NUMBER
        {
            DataType idType = lookup_type($1);
            DataType resultType = check_arithmetic_compatibility(idType, TYPE_INT);
            if (resultType == TYPE_ERROR) {
                yyerror("Incompatible types for arithmetic operation");
            } else {
                char* temp = new_temp();
                printf("%s = %s %s %d;\n", temp, $2, $1, $3);
                $$ = new_expr(resultType, temp);
            }
            print_if_enabled("algebraic_expr -> ID rel_alg NUMBER\n");
        };

//Produção de operador algébrico
rel_alg
    : PLUS  { $$ = "+"; print_if_enabled("\nrel_alg -> ADIÇÃO\n");}
    | MINUS { $$ = "-"; print_if_enabled("\nrel_alg -> SUBTRAÇÃO\n");}
    | MULT  { $$ = "*"; print_if_enabled("\nrel_alg -> MULTIPLICAÇÃO\n");}
    | DIV   { $$ = "/"; print_if_enabled("\nrel_alg -> DIVISÃO\n");}
    ;
//Produção de expressão logica
logic_expr : ID RELOP ID
                {
                        // Exemplo: geração de código Bril para uma comparação
                        char* op_bril;
                        switch ($2) { // Aqui $2 representa o token do operador relacional
                                case LT: op_bril = "lt"; break;
                                case LE: op_bril = "le"; break;
                                case EQ: op_bril = "eq"; break;
                                case NE: op_bril = "ne"; break;
                                case GT: op_bril = "gt"; break;
                                case GE: op_bril = "ge"; break;
                                default: op_bril = "eq"; // Padrão ou erro
                        }
                        char* temp = new_temp();
                        printf("%s = %s %s %s;\n", temp, op_bril, $1, $3); // Adapte conforme a operação real e os operandos
                        $$ = new_expr(TYPE_BOOL, temp);
                }
            | ID RELOP NUMBER
                {
                        char* op_bril;
                        switch ($2) { // Aqui $2 representa o token do operador relacional
                                case LT: op_bril = "lt"; break;
                                case LE: op_bril = "le"; break;
                                case EQ: op_bril = "eq"; break;
                                case NE: op_bril = "ne"; break;
                                case GT: op_bril = "gt"; break;
                                case GE: op_bril = "ge"; break;
                                default: op_bril = "eq"; // Padrão ou erro
                        }
                        char* temp = new_temp();
                        printf("%s = %s %s %d;\n", temp, op_bril, $1, $3); // Assumindo que NUMBER é traduzido diretamente para seu valor literal
                        $$ = new_expr(TYPE_BOOL, temp);
                }
            | NUMBER RELOP ID
                {
                        char* op_bril;
                        switch ($2) { // Aqui $2 representa o token do operador relacional
                                case LT: op_bril = "lt"; break;
                                case LE: op_bril = "le"; break;
                                case EQ: op_bril = "eq"; break;
                                case NE: op_bril = "ne"; break;
                                case GT: op_bril = "gt"; break;
                                case GE: op_bril = "ge"; break;
                                default: op_bril = "eq"; // Padrão ou erro
                        }
                        char* temp = new_temp();
                        printf("%s = %s %d %s;\n", temp, op_bril, $1, $3); // Troque 'cmp' pelo operador Bril apropriado
                        $$ = new_expr(TYPE_BOOL, temp);
                }
            | NUMBER RELOP NUMBER
                {
                        char* op_bril;
                        switch ($2) { // Aqui $2 representa o token do operador relacional
                                case LT: op_bril = "lt"; break;
                                case LE: op_bril = "le"; break;
                                case EQ: op_bril = "eq"; break;
                                case NE: op_bril = "ne"; break;
                                case GT: op_bril = "gt"; break;
                                case GE: op_bril = "ge"; break;
                                default: op_bril = "eq"; // Padrão ou erro
                        }
                        char* temp = new_temp();
                        printf("%s = %s %d %d;\n", temp, op_bril, $1, $3); // Números são diretamente inseridos no código
                        $$ = new_expr(TYPE_BOOL, temp);
                };

//Produção de atribuição
attrib : ID ATTR ID PVIRG               { print_if_enabled("\nattrib -> ID ATTR ID PVIRG\n");}
        | ID ATTR NUMBER PVIRG          { print_if_enabled("\nattrib -> ID ATTR NUMBER PVIRG\n");}
        | ID ATTR algebraic_expr PVIRG  { print_if_enabled("\nattrib -> ID ATTR algebraic_expr PVIRG\n");}
        | ID ATTR logic_expr PVIRG      { print_if_enabled("\nattrib -> ID ATTR logic_expr PVIRG\n");}
        | ID ATTR LITERALSTRING PVIRG   { print_if_enabled("\nattrib -> ID ATTR LITERALSTRING PVIRG\n");}
        ;

//Produção de expressão condicional
expr_condicional : SE AP logic_expr FP ENTAO instruction FIMSE 
    {
        if ($3.type != TYPE_BOOL) {
            yyerror("A expressão condicional deve ser booleana");
        } else {
            // código para expressão condicional verdadeira
            printf("br %s .true .false\n", $3.code);
            printf(".true:\n");
            // Gera o código Bril para instruction se verdadeira
            printf("%s\n", $5.code);
            printf(".false:\n");
        }
    };

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
vars_list : var_decl vars_list
        {
            // Implementar inserção na tabela de símbolos aqui, assumindo que 'var_decl' retorna informações sobre as variáveis declaradas
            if (!insert_symbol_table($1.name, $1.type)) {
                char error[256];
                sprintf(error, "Erro: variável '%s' já declarada neste escopo.", $1.name);
                yyerror(error);
            }
            print_if_enabled("\nvars_list -> var_decl vars_list\n");
        }
    |   // Lista vazia não faz nada, mas formaliza a base da recursão
        ;

//Produção de variaveis
var_decl : tipo_var ID_list PVIRG
        {
                current_type = $1; // Define o tipo atual antes de processar a lista de IDs
                print_if_enabled("\nvar_decl -> tipo_var ID_list PVIRG\n");
        };
//Produção de lista de identificadores 
ID_list : ID_list VIRG ID
                {
                // Adiciona o ID atual à lista com o tipo atual, inserindo na tabela de símbolos
                        if (!insert_symbol_table($3, current_type)) {
                                char error[256];
                                sprintf(error, "Erro: variável '%s' já declarada neste escopo.", $3);
                                yyerror(error);
                        }
                        print_if_enabled("\nID_list -> ID_list VIRG ID\n");
                }
        | ID
                {
                        // Insere o primeiro ID da lista na tabela de símbolos com o tipo definido por tipo_var
                        if (!insert_symbol_table($1, current_type)) {
                                char error[256];
                                sprintf(error, "Erro: variável '%s' já declarada neste escopo.", $1);
                                yyerror(error);
                        }
                        print_if_enabled("\nID_list -> ID\n");
                };

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

 // Verifica se a flag para desabilitar os prints foi passada
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--no-print") == 0) {
            enable_prints = 0;
        }
    }


    initializeSymbolTable(); // Inicializa a tabela de símbolos
    addReservedWords();      // Adiciona palavras reservadas

    if (yyparse() != 0) {
        fprintf(stderr, "Abnormal exit\n");
    }
    return 0;
}

int yyerror(char *s) {
    fprintf(stderr, "Error: %s -- Line: %d\n", s, yylineno);
    return 0;
}
