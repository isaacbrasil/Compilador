#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Symbol {
    char *name;
    char *type;
    char *form;
    int size;
    void *memoryLocation;
    char *attributes;  // Uma string para armazenar outros atributos
    struct Symbol *next;
} Symbol;

Symbol *symbolTable[TABLE_SIZE];

unsigned int hash(const char *str) {
    unsigned int hash = 0;
    for (; *str; str++) hash = hash * 31 + *str;
    return hash % TABLE_SIZE;
}

void insertSymbol(const char *name, const char *type, int size, void *memoryLocation) {
    Symbol *existingSymbol = findSymbol(name);
    if (existingSymbol == NULL) { // Somente insira se o símbolo ainda não existe
        Symbol *symbol = (Symbol *)malloc(sizeof(Symbol));
        if (!symbol) {
            fprintf(stderr, "Falha na alocação de memória\n");
            return;
        }
        symbol->name = strdup(name);
        symbol->type = strdup(type);
        symbol->size = size;
        symbol->memoryLocation = memoryLocation;

        int index = hash(name);
        symbol->next = symbolTable[index];
        symbolTable[index] = symbol;
    }
}

void addReservedWords() {
    insertSymbol("se", "keyword", 0, 0);
    insertSymbol("entao", "keyword", 0, 0);
    insertSymbol("else", "keyword", 0, 0);
    insertSymbol("inicioprog", "keyword", 0, 0);
    insertSymbol("fimprog", "keyword", 0, 0);
    insertSymbol("inicioargs", "keyword", 0, 0);
    insertSymbol("fimargs", "keyword", 0, 0);
    insertSymbol("iniciovars", "keyword", 0, 0);
    insertSymbol("fimvars", "keyword", 0, 0);
    insertSymbol("escreva", "keyword", 0, 0);
    insertSymbol("inteiro", "keyword", 0, 0);
    insertSymbol("real", "keyword", 0, 0);
    insertSymbol("literal", "keyword", 0, 0);
    insertSymbol("fimse", "keyword", 0, 0);
    insertSymbol("enquanto", "keyword", 0, 0);
    insertSymbol("faca", "keyword", 0, 0);
    insertSymbol("fimenquanto", "keyword", 0, 0);

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
            free(symbol->attributes);
            free(symbol);
            symbol = next;
        }
    }
}
