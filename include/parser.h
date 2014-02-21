#include "types.h"
#include "linkedlist.h"
#include "hashmap.h"

#ifndef _PARSER_H_
#define _PARSER_H_
typedef struct frame* frame;

struct frame {
	map stringPool;
	map intPool;
	map floatPool;
	map boolPool;
	map functionPool;
};

frame newFrame();
void parse(array tokens);
#endif