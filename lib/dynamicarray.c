#include <stdlib.h>
#include "types.h"
#include "dynamicarray.h"

array newArray(size_t size){
	array a = malloc(sizeof(*a));
	a->values = malloc(sizeof(void*) * size);
	a->size = size;

	return a;
}

void resizeArray(array arr){
	size_t size = sizeof(void*) * arr->size * 2;
	arr->values = realloc(arr->values, size);

	while(++(arr->size) < size)
		arr->values[arr->size] = NULL;
}

void* getArrayValue(size_t index, array arr){
	return arr->values[index];
}

void insertArrayValue(void* val, array arr){
	if(arr->length == arr->size)
		resizeArray(arr);

	arr->values[arr->length++] = val;
}

void setArrayValue(size_t index, void* val, array arr){
	arr->values[index] = val;
}