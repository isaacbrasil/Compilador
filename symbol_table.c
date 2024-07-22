#include "symbol_table.h"
#include <stdlib.h>
#include <string.h>

// Definição da variável global
Symbol *symbolTable[TABLE_SIZE];

// Função hash auxiliar
static unsigned int hash(const char *str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31) + *str;
        str++;
    }
    return hash % TABLE_SIZE;
}

// Implementação das funções
Symbol *findSymbol(const char *name) {
    int index = hash(name);
    Symbol *symbol = symbolTable[index];
    while (symbol) {
        if (strcmp(symbol->name, name) == 0) {
            return symbol;
        }
        symbol = symbol->next;
    }
    return NULL;
}

void insertSymbol(const char *name, Type type) {
    Symbol *existingSymbol = findSymbol(name);
    if (existingSymbol == NULL) {
        Symbol *symbol = (Symbol *)malloc(sizeof(Symbol));
        if (!symbol) {
            fprintf(stderr, "Falha na alocação de memória\n");
            return;
        }
        symbol->name = strdup(name);
        symbol->type = type;

        int index = hash(name);
        symbol->next = symbolTable[index];
        symbolTable[index] = symbol;
    }
}

void addReservedWords() {
    insertSymbol("se", T_STRING);
    insertSymbol("entao", T_STRING);
    insertSymbol("else", T_STRING);
    insertSymbol("inicioprog", T_STRING);
    insertSymbol("fimprog", T_STRING);
    insertSymbol("inicioargs", T_STRING);
    insertSymbol("fimargs", T_STRING);
    insertSymbol("iniciovars", T_STRING);
    insertSymbol("fimvars", T_STRING);
    insertSymbol("escreva", T_STRING);
    insertSymbol("inteiro", T_STRING);
    insertSymbol("real", T_STRING);
    insertSymbol("literal", T_STRING);
    insertSymbol("fimse", T_STRING);
    insertSymbol("enquanto", T_STRING);
    insertSymbol("faca", T_STRING);
    insertSymbol("fimenquanto", T_STRING);
}

void initializeSymbolTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        symbolTable[i] = NULL;
    }
}

void freeSymbolTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Symbol *symbol = symbolTable[i];
        while (symbol) {
            Symbol *next = symbol->next;
            free(symbol->name);
            free(symbol);
            symbol = next;
        }
    }
}

void showSymbolTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Symbol *symbol = symbolTable[i];
        while (symbol) {
            printf("Nome: %s, Tipo: %d\n", symbol->name, symbol->type);
            symbol = symbol->next;
        }
    }
}
