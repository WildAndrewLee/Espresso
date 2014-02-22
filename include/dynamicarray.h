#include <stdlib.h>

#ifndef _DYNAMICARRAY_H_
#define _DYNAMICARRAY_H_
typedef struct array* array;

struct array {
	void** values;
	size_t size;
	size_t length;
};

array newArray(size_t size);
void resizeArray(array arr);
void* getArrayValue(size_t index, array arr);
void insertArrayValue(void* val, array arr);
void setArrayValue(size_t index, void* val, array arr);
#endif