#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdio.h>
#include "types.h"

#define TABLE_SIZE 100

// Definição da estrutura Symbol
typedef struct Symbol {
    char *name;
    Type type;
    struct Symbol *next;
} Symbol;

// Declaração da variável global symbolTable
extern Symbol *symbolTable[TABLE_SIZE];

// Declarações de funções
Symbol *findSymbol(const char *name);
void insertSymbol(const char *name, Type type);
void addReservedWords();
void initializeSymbolTable();
void freeSymbolTable();
void showSymbolTable();

#endif // SYMBOL_TABLE_H
