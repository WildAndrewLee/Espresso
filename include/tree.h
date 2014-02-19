#include <stdlib.h>
#include "types.h"

#ifndef _TREE_H_
#define _TREE_H_
typedef struct treeNode* node;

struct treeNode {
	int size;
	string token;
	node* children;
};

node newNode(string token, size_t size);
#endif