#include <stdio.h>
#include <stdlib.h>
#include "types.h"

#ifndef _ESPRESSO_H_
#define _ESPRESSO_H_
/**
 * Definitions
 */
extern bool DEBUG;

/**
 * Macros
 */
#define ABORT() abort()
#define EXIT(x) exit(x)
#define SIZE_OF_ARRAY(x) (sizeof(x) / sizeof(x[0]))

/**
 * Typedefs
 */
typedef FILE* file;

/**
 * Interfaces
 */
void checkArgs(int argc, string argv[]);
string readFile(string path);
void process(string buffer);
#endif