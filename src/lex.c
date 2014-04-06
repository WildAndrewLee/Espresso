#include <stdlib.h>
#include "types.h"
#include "str.h"
#include "dynamicarray.h"
#include "tree.h"

array getParams(array tokens, size_t* index, string open, string close){
	bool escape = false;
	size_t braces = 1;

	array params = newArray(0);

	string token = getArrayValue(*index, tokens);

	if(!streq(token, open){
		//Invalid syntax detected.
		//Whatever not proceeded by a an opening brace.
	}

	//Keep adding tokens to the array until the closing
	//brace is found.
	for(*index += 1; *index < tokens->length; (*index)++){
		token = getArrayValue(*index, tokens);

		//Check matching braces.
		if(!escape && streq(token, open){
			braces++;
		}
		else if(!escape && streq(token, close)){
			braces--;

			//If this is the closing brace just return the array.
			if(braces == 0){
				(*index)++;
				return params;
			}
		}
		else if(!escape && streq(token, "\\")){
			escape = true;
		}

		insertArrayValue(token, params);
	}

	//Invalid syntax detected.
	//Mismatched braces.
	//Report an error.

	return NULL;
}

node analyzeIf(node programNode, array tokens, size_t* index){
	node next = newNode("if", 2);
	programNode->next = next;
	programNode = next;

	//Advance index to the next token.
	*index += 1;

	array condition = getBlock(tokens, &index, "(", ")"));
	node conditionNode = analyze(condition);

	programNode->children[0] = conditionNode->next;

	free(conditionNode);

	array block = getBlock(tokens, &index, "{", "}");
	node blockNode = analyze(block);

	programNode->children[1] = blockNode->next;

	free(blockNode);

	return programNode;
}

node analyzeElse(node programNode, array tokens, size_t* index){
	node next = newNode("else", 1);
	programNode->next = next;
	programNode = next;

	//Advance index to the next token.
	*index += 1;

	array block = getBlock(tokens, &index, "{", "}");
	node blockNode = analyze(block);

	programNode->children[0] = blockNode->next;

	free(blockNode);

	return programNode;
}

node analyzeString(node programNode, array tokens, size_t* index){
	array block = getBlock(tokens, &index, "\"", "\"");

	node next = newNode("string", 1);
	node str = newNode(block, 0);

	next->children[0] = str;

	programNode->next = next;

	return next;
}

node analyzeWhile(node programNode, array tokens, size_t* index){
	node next = newNode("while", 2);
	programNode->next = next;
	programNode = next;

	//Advance index to the next token.
	*index += 1;

	array condition = getBlock(tokens, &index, "(", ")"));
	node conditionNode = analyze(condition);

	programNode->children[0] = conditionNode->next;

	free(conditionNode);

	array block = getBlock(tokens, &index, "{", "}");
	node blockNode = analyze(block);

	programNode->children[1] = blockNode->next;

	free(blockNode);

	return programNode;
}

node analyzeStatement(node programNode, array tokens, size_t* tokens){
	node next = newNode("statement", 1);
	programNode->next = next;
	programNode = next;


}

node analyze(array tokens){
	size_t index;
	bool str = false;
	node programNode = newNode("PROGRAM", 0);
	

	for(index = 0; index < tokens->length; index++){
		string token = getArrayValue(index, tokens);

		//Handle strings.
		if(str){
			programNode = analyzeString(programNode, tokens, &index);
		}
		//Handle if statements.
		else if(streq(token, "if")){
			programNode = analyzeIf(programNode, tokens, &index);
		}
		//Handle else statements.
		else if(streq(token, "else")){
			programNode = analyzeElse(programNode, tokens, &index);
		}
		//Handle while statements.
		else if(streq(token, "while")){
			programNode = analyzeWhile(programNode, tokens, &index);
		}
		//Parse other statements.
		else{
			programNode = analyzeStatement(programNode, tokens, &index);
		}
	}

	return NULL;
}