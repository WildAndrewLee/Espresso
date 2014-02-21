#include <stdlib.h>
#include "types.h"
#include "var.h"
#include "hashmap.h"
#include "linkedlist.h"

map newMap(size_t size, double load){
	map m = malloc(sizeof(*m));
	m->size = size;
	m->count = 0;
	m->load = load;

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
}

void resizeMap(map m, size_t scale){

}

int hashKey(string key){
	return 0;
}

void* getKeyValue(string key, map m){
	return NULL;
}