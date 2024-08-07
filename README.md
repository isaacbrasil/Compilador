Compilador que reconhece a linguagem irrisória.

Para compilar o arquivo Flex junto com o código da tabela de símbolos e qualquer outro código-fonte necessário para o compilador SEQUENCIALMENTE:

```
flex -o lex.yy.c lex.l && gcc -o mycompiler lex.yy.c symbol_table.c -lfl && ./mycompiler

```


Para compilar o arquivo Flex junto com o código da tabela de símbolos e qualquer outro código-fonte necessário para o compilador PASSANDO UM ARQUIVO DE TEXTO COMO TESTE:

```
flex -o lex.yy.c lex.l && gcc -o mycompiler lex.yy.c symbol_table.c -lfl && ./mycompiler < input.txt

```

Para compilar o arquivo Flex junto com o bison:


```
flex lex.l && bison -d sintatico.y && gcc sintatico.tab.c lex.yy.c symbol_table.c -o mycompiler && ./mycompiler < input.txt
ou
bison -d sintatico.y && flex lex.l && gcc sintatico.tab.c lex.yy.c  symbol_table.c -o mycompiler && ./mycompiler < input.txt

```


Para ativar o modo verbose basta passar a flag "--lex" para ativar a verbosidade do léxico e a flag "--verbose" para ativar a verbosidade do sintatico:


```
bison -d sintatico.y && flex lex.l && gcc sintatico.tab.c lex.yy.c symbol_table.c -o mycompiler && ./mycompiler --verbose --lex < exemplo01.txt


```
