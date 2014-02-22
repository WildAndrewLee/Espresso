#include <stdlib.h>
#include "types.h"
#include "str.h"

bool streq(string a, string b){
	char* ca = a;
	char* cb = b;

	while(ca && cb){
		if(*(ca++) != *(cb++))
			return false;
	}

	return true;
}

size_t strlen(string str){
	char* c = str;
	size_t len = 0;

	while(c && *(c++))
		len++;

	return len;
}