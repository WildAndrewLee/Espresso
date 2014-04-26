#include <stdlib.h>

#ifndef _TREE_H_
#define _TREE_H_
typedef struct treeNode* node;

struct treeNode {
	int size;
	node next;
	void* token;
	node* children;
};

node newNode(void* token, size_t size);
#endif