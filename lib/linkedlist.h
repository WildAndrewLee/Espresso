#include "types.h"

#ifndef LINKEDLIST
#define LINKEDLIST
typedef struct linkedList* linkedList;
typedef struct linkedNode* linkedNode;

struct linkedList {
	linkedNode head;
	linkedNode tail;
};

struct linkedNode {
	void* content;
	linkedNode next;
};

linkedList newLinkedList(void* content);
linkedNode newLinkedNode(void* content);
void appendLinkedNode(linkedNode n, linkedList l);
linkedNode removeLinkedListHead(linkedList l);
bool linkedListIsEmpty(linkedList l);
#endif