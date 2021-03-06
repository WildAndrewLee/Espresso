#include <assert.h>
#include <stdlib.h>
#include "linkedlist.h"

bool linkedListIsEmpty(linkedList l){
	assert(l);

	return l->head == NULL && l->tail == NULL;
}

linkedList newLinkedList(void* content){
	linkedList l = (linkedList) malloc(sizeof(*l));
	l->head = l->tail = NULL;

	if(content){
		assert(content);
		linkedNode n = newLinkedNode(content);
		l->head = l->tail = n;
	}

	return l;
}

linkedNode newLinkedNode(void* content){
	assert(content);

	linkedNode n = (linkedNode) malloc(sizeof(*n));
	n->content = content;
	n->next = NULL;

	return n;
}

void appendLinkedNode(linkedNode n, linkedList l){
	assert(l);
	assert(n);

	if(!l->tail)
		l->head = l->tail = n;
	else
		l->tail = l->tail->next = n;
}

linkedNode removeLinkedListHead(linkedList l){
	assert(l);
	assert(l->head);

	linkedNode n = l->head;
	l->head = n->next;

	if(l->tail == n)
		l->tail = NULL;

	return n;
}