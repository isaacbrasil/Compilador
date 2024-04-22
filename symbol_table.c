#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Symbol {
    char *name;
    char *type;
    char *form;
    int size;
    int scope;
    void *memoryLocation;
    char *attributes;  // Uma string para armazenar outros atributos
    struct Symbol *next;
} Symbol;

Symbol *symbolTable[TABLE_SIZE];

unsigned int hash(char *str) {
    unsigned int hash = 0;
    for (; *str; str++) hash = hash * 31 + *str;
    return hash % TABLE_SIZE;
}

void insertSymbol(char *name, char *type, char *form, int size, int scope, void *memoryLocation, char *attributes) {
    Symbol *symbol = (Symbol *)malloc(sizeof(Symbol));
    symbol->name = strdup(name);
    symbol->type = strdup(type);
    symbol->form = strdup(form);
    symbol->size = size;
    symbol->scope = scope;
    symbol->memoryLocation = memoryLocation;
    symbol->attributes = strdup(attributes);

    int index = hash(name);
    symbol->next = symbolTable[index];
    symbolTable[index] = symbol;
}

Symbol *findSymbol(char *name) {
    int index = hash(name);
    Symbol *symbol = symbolTable[index];
    while (symbol) {
        if (strcmp(symbol->name, name) == 0) return symbol;
        symbol = symbol->next;
    }
    return NULL;
}

void initializeSymbolTable() {
    for (int i = 0; i < TABLE_SIZE; i++) symbolTable[i] = NULL;
}

void freeSymbolTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Symbol *symbol = symbolTable[i];
        while (symbol) {
            Symbol *next = symbol->next;
            free(symbol->name);
            free(symbol->type);
            free(symbol->form);
            free(symbol->attributes);
            free(symbol);
            symbol = next;
        }
    }
}
