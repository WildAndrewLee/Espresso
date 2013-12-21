#include <stdio.h>
#include <stdlib.h>

#ifndef ESPRESSO
#define ESPRESSO
/**
 * Definitions
 */
#define keywords {"if", "else", "then", "for", "while", "lambda", "fn"};

/**
 * Typedefs
 */
typedef FILE* file;

/**
 * Interfaces
 */
void* emalloc(size_t size);
void efree(void* var);
string* tokenize(string buffer);
#endif