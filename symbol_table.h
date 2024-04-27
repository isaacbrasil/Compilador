#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdio.h>

#define TABLE_SIZE 100

// Definição da estrutura Symbol
typedef struct Symbol {
    char *name;
    char *type;
    int size;
    void *memoryLocation;
    char *attributes;  // Uma string para armazenar outros atributos
    struct Symbol *next;
} Symbol;

// Declaração da variável global symbolTable
extern Symbol *symbolTable[TABLE_SIZE];

// Declarações de funções
Symbol *findSymbol(const char *name);
void insertSymbol(const char *name, const char *type, int size, void *memoryLocation);
void addReservedWords();
void initializeSymbolTable();
void freeSymbolTable();

#endif // SYMBOL_TABLE_H
