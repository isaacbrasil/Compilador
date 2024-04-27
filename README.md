Compilador que reconhece a linguagem irrisória.

Para compilar o arquivo Flex junto com o código da tabela de símbolos e inserir entrada por entrada faça:

```
flex -o lex.yy.c lex.l gcc -o mycompiler lex.yy.c symbol_table.c -lfl && ./mycompiler

```

Para compilar o arquivo Flex junto com o código da tabela de símbolos e inserir um arquivo de texto como entrada faça:

```
flex -o lex.yy.c lex.l gcc -o mycompiler lex.yy.c symbol_table.c -lfl && ./mycompiler < input.txt

```

