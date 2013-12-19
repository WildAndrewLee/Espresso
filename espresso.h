#include <assert.h>

#ifndef ESPRESSO
#define ESPRESSO
/**
 * Definitions
 */
#define true 1;
#define false 0;

/**
 * Typedefs
 */
typedef char* string;
typedef FILE* file;
typedef int bool;

/**
 * Interfaces
 */

/**
 * Same as malloc but prints error and debug messages.
 * @param size The amount of memory to allocate.
 */
void* emalloc(size_t size);
void efree(void* var);

/**
 * Global Variables
 */
bool DEBUG = false;

/**
 * Interface implementations.
 */
void* emalloc(size_t size){
	assert(size > 0);

	void* p = malloc(size);

	if(!p){
		printf("<Failed to allocate %d bytes of memory.>\n", size);
		abort();
	}

	if(DEBUG){
		printf("<Allocated %d bytes in memory.>\n", size);
	}

	return p;
}

void efree(void* var){
	assert(var != NULL);

	if(!var){
		printf("<Attempting to free NULL pointer.>\n");
		abort();
	}

	free(var);
}
#endif