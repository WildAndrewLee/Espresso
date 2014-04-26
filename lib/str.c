#include <stdlib.h>
#include "types.h"
#include "str.h"

bool streq(string a, string b){
	char* ca = a;
	char* cb = b;

	while(ca && cb)
		if(*(ca++) != *(cb++))
			return false;

	return !ca && !cb;
}

bool strcontains(string a, char b){
	char* ca = a;

	while(ca)
		if(*(ca++) == b)
			return true;

	return false;
}

size_t strlen(string str){
	char* c = str;
	size_t len = 0;

	while(c && *(c++))
		len++;

	return len;
}

bool strisalpha(string a){
	char* ca = a;

	while(ca){
		bool uppercase = (int) ca >= 65 && (int) ca <= 90;
		bool lowercase = (int) ca >= 97 && (int) ca <= 122;

		if(!(uppercase || lowercase))
			return false;
	}

	return true;
}