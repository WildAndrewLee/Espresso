#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "mem.h"

void* emalloc(size_t size){
	assert(size > 0);

	void* p = malloc(size);

	if(!p){
		printf("<Failed to allocate %d bytes of memory.>\n", size);
		abort();
	}

	return p;
}

void efree(void* var){
	assert(var != NULL);

	free(var);
}