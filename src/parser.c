#include <stdlib.h>
#include "types.h"
#include "linkedlist.h"
#include "tree.h"
#include "espresso.h"
#include "keys.h"
#include "parser.h"

frame newFrame(){
	return (frame) malloc(sizeof(struct frame));
}

void parse(linkedList tokens){
	linkedNode node = tokens->head;

	while(node != NULL){
		printf("%s", (string) node->content);
		node = node->next;
	}
}