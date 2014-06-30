#include <stdlib.h>
#include "types.h"
#include "str.h"
#include "linkedlist.h"
#include "dynamicarray.h"
#include "hashmap.h"
#include "tree.h"
#include "espresso.h"
#include "keys.h"
#include "parser.h"

frame newFrame(){
	return (frame) malloc(sizeof(struct frame));
}

void parse(node tokens){
	printf("%s", (char*) tokens->token);
}