#include <string.h>
#include "types.h"
#include "linkedlist.h"
#include "espresso.h"
#include "keys.h"
#include "processor.h"

bool isDelimiter(char c){
	size_t n;

	for(n = 0; n < WHITESPACE_DELIMITERS_SIZE; n++){
		if(WHITESPACE_DELIMITERS[n] == c){
			return true;
		}
	}

	for(n = 0; n < TOKEN_DELIMITERS_SIZE; n++){
		if(TOKEN_DELIMITERS[n] == c){
			return true;
		}
	}

	return false;
}

string getNextToken(int index, string buffer){
	string token = (string) emalloc(sizeof(char) * 256);
	size_t pos = 0;

	while(buffer[index]){
		if(isDelimiter(buffer[index])){
			if(pos > 0){
				token[pos] = '\0';
				return token;
			}
			else{
				string s = (string) emalloc(sizeof(char) * 2);
				s[0] = buffer[index];
				s[1] = '\0';

				return s;
			}
		}

		token[pos++] = buffer[index++];
	}

	return token;
}

void process(string buffer){
	linkedList tokens = newLinkedList(NULL);
	size_t index;

	for(index = 0; index < strlen(buffer); index++){
		string token = getNextToken(index, buffer);

		index += strlen(token) - 1;

		linkedNode node = newLinkedNode(token);
		appendLinkedNode(node, tokens);
	}

	parse(tokens);

	while(!linkedListIsEmpty(tokens)){
		efree(removeLinkedListHead(tokens));
	}

	efree(tokens);
}