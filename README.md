Compilador que reconhece a linguagem irrisória.

Para compilar o arquivo Flex junto com o código da tabela de símbolos e qualquer outro código-fonte necessário para o compilador:

bash

```
flex -o lex.yy.c lex.l
gcc -o mycompiler lex.yy.c symbol_table.c -lfl && ./mycompiler

```
