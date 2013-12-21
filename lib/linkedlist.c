#include <assert.h>
#include <stdio.h>
#include "types.h"
#include "linkedlist.h"

linkedList newLinkedList(void* content){
	linkedList l = (linkedList) emalloc(sizeof(*l));

	if(content){
		linkedNode n = newLinkedNode(content);

		l->head = n;
		l->tail = n;
	}

	return l;
}

linkedNode newLinkedNode(void* content){
	assert(content);

	linkedNode n = (linkedNode) emalloc(sizeof(*n));
	n->content = content;
	n->next = NULL;

	return n;
}

void appendLinkedNode(linkedNode n, linkedList l){
	assert(l);
	assert(n);

	if(!l->tail){
		l->head = l->tail = n;
	}
	else{
		l->tail->next = n;
		l->tail = n;
	}
}

linkedNode removeLinkedListHead(linkedList l){
	assert(l);
	assert(l->head);

	linkedNode n = l->head;
	l->head = n->next;

	if(l->tail == n){
		l->tail = NULL;
	}

	return n;
}

bool linkedListIsEmpty(linkedList l){
	assert(l);

	return l->head == NULL && l->tail == NULL;
}