#include <assert.h>
#include <stdio.h>
#include "lib/types.h"
#include "espresso.h"

/**
 * Global Variables
 */
bool DEBUG = false;

/**
 * Functions
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

	free(var);
}

string* tokenize(string buffer){

}