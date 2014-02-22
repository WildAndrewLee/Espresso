#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "var.h"
#include "linkedlist.h"
#include "hashmap.h"

map newMap(size_t size, double load){
	map m = malloc(sizeof(*m));
	m->size = size;
	m->count = 0;
	m->load = load;
	m->values = malloc(sizeof(void*) * size);

	fillEmpty(m);

	return m;
}

void insertMapValue(string key, void* value, map m){
	if(m->count >= m->size * m->load)
		resizeMap(m, 2);

	size_t index = hashKey(key) % m->size;

	var v = newVar(key, value);
	linkedNode node = newLinkedNode(v);
	linkedList list = m->values[index];

	if(!list)
		list = m->values[index] = newLinkedList(NULL);

	appendLinkedNode(node, list);
	m->count++;
}

void removeMapValue(string key, map m){
	size_t index = hashKey(key) % m->size;

	linkedList list = m->values[index];

	if(list){
		linkedNode node = list->head;
		var content = (var) node->content;

		if(!strcmp(key, content->name)){
			removeLinkedListHead(list);

			free(node);
			m->count--;

			if(linkedListIsEmpty(list)){
				free(list);
				m->values[index] = NULL;
			}

			return;
		}

		content = (var) node->next->content;

		while(node->next && strcmp(key, content->name)){
			node = node->next;
			content = (var) node->next->content;
		}

		if(!strcmp(key, content->name)){
			linkedNode removed = node->next;
			node->next = removed->next;

			free(removed);
			m->count--;
		}
	}
}

void resizeMap(map m, size_t scale){
	void** old = m->values;
	size_t size = scale * m->size;
	size_t oldSize = m->size;
	size_t count = m->count;

	m->size = size;
	m->values = malloc(sizeof(void*) * size);

	fillEmpty(m);

	size_t index;

	for(index = 0; index < oldSize; index++){
		linkedList list = old[index];

		if(list){
			while(!linkedListIsEmpty(list)){
				linkedNode node = removeLinkedListHead(list);
				var v = node->content;

				m->count--; //Don't double count items.
				insertMapValue(v->name, v->content, m);
				free(v);
				free(node);
			}

			free(list);
		}
	}

	free(old);
}

int hashKey(string key){	
	int hash = 140210887;
	char* c;

	for(c = key; *c; c++){
		hash *= 84567211;
		hash ^= (int) *c;
		hash %= 2147483647;
	}

	return hash;
}

void* getKeyValue(string key, map m){
	linkedList list = m->values[hashKey(key) % m->size];

	if(!list || !list->head)
		return NULL;

	linkedNode node = list->head;
	var v = (var) node->content;

	while(node && strcmp(key, v->name)){
		node = node->next;
		v = node ? (var) node->content : NULL;
	}

	return node ? node->content : NULL;
}

void fillEmpty(map m){
	size_t index;

	for(index = 0; index < m->size; index++)
		m->values[index] = NULL;
}