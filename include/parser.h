#include "types.h"
#include "linkedlist.h"

#ifndef _PARSER_H_
#define _PARSER_H_
typedef struct frame* frame;

struct frame {
	linkedList stringPool;
	linkedList intPool;
	linkedList floatPool;
	linkedList boolPool;
	linkedList functionPool;
};

frame newFrame();
void parse(linkedList tokens);
#endif