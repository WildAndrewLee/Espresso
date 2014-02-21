#include <assert.h>
#include <stdlib.h>
#include "tree.h"

node newNode(void* token, size_t size){
	assert(token);
	assert(size >= 0);

	node n = malloc(sizeof(*n));
	n->token = token;

	if(size)
		n->children = malloc(sizeof(node) * size);
	else
		n->children = NULL;

	n->size = size;

	return n;
}