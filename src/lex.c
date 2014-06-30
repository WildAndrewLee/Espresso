#include <stdlib.h>
#include "types.h"
#include "str.h"
#include "dynamicarray.h"
#include "tree.h"
#include "lex.h"

array getBlock(array tokens, size_t* index, string open, string close){
	bool escape = false;
	size_t braces = 1;

	array params = newArray(0);

	string token = getArrayValue(*index, tokens);

	if(!streq(token, open)){
		//Invalid syntax detected.
		//Whatever not proceeded by a an opening token.
	}

	//Keep adding tokens to the array until the closing
	//token is found.
	for(*index += 1; *index < tokens->length; (*index)++){
		token = getArrayValue(*index, tokens);

		//Check matching braces.
		if(!escape && streq(token, open)){
			braces++;
		}
		else if(!escape && streq(token, close)){
			braces--;

			//If this is the closing token just return the array.
			if(braces == 0){
				(*index)++;
				return params;
			}
		}
		else if(!escape && streq(token, "\\")){
			escape = true;
		}
		else{
			escape = false;
		}

		insertArrayValue(token, params);
	}

	//Invalid syntax detected.
	//Mismatched tokens.
	//Report an error.

	return NULL;
}

array getBlockTo(array tokens, size_t* index, string stop){
	bool escape = false;
	array params = newArray(0);
	string token;

	//Keep adding tokens to the array until we reach a stopping token.
	for(*index += 1; *index < tokens->length; (*index)++){
		token = getArrayValue(*index, tokens);

		if(!escape && streq(token, stop)){
			(*index)++;
			break;			
		}
		else if(!escape && streq(token, "\\")){
			escape = true;
		}
		else{
			escape = false;
		}

		insertArrayValue(token, params);
	}

	return params;
}

node analyzeIf(node programNode, array tokens, size_t* index){
	node next = newNode("if", 2);
	programNode->next = next;
	programNode = next;

	//Advance index to the next token.
	*index += 1;

	array condition = getBlock(tokens, index, "(", ")");
	node conditionNode = analyze(condition);

	programNode->children[0] = conditionNode->next;

	free(conditionNode);

	array block = getBlock(tokens, index, "{", "}");
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

	array block = getBlock(tokens, index, "{", "}");
	node blockNode = analyze(block);

	programNode->children[0] = blockNode->next;

	free(blockNode);

	return programNode;
}

node analyzeString(node programNode, array tokens, size_t* index){
	array block = getBlock(tokens, index, "\"", "\"");

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

	array condition = getBlock(tokens, index, "(", ")");
	node conditionNode = analyze(condition);

	programNode->children[0] = conditionNode->next;

	free(conditionNode);

	array block = getBlock(tokens, index, "{", "}");
	node blockNode = analyze(block);

	programNode->children[1] = blockNode->next;

	free(blockNode);

	return programNode;
}

node analyzeFunctionCall(array tokens){
	//Get number of arguments.
	size_t index = 0;
	array args = getBlockTo(tokens, &index, ")");
	size_t argNum = ((int) (args->length / 2)) + 1;

	node call = newNode("call", 1);
	node function = newNode(getArrayValue(0, tokens), argNum);

	for(index = 0; index < argNum; index++){
		function->children[index] = getArrayValue(index * 2, tokens);
	}

	call->children[0] = function;

	return call;
}

node analyzeVariable(array tokens){
	node variable = newNode("variable", 2);
	variable->children[0] = getArrayValue(0, tokens);

	size_t* one = malloc(sizeof(size_t));
	*one = 1;

	array arr = getBlockTo(tokens, one, ";");

	free(one);

	node value = newNode(arr, 0);

	variable->children[1] = value;

	return variable;
}

node analyzeStatement(node programNode, array tokens, size_t* index){
	node next = newNode("statement", 1);
	programNode->next = next;
	programNode = next;

	array arr = getBlockTo(tokens, index, ";");

	node statement = NULL;

	//All alphabet tokens are either variable names
	//or function names.
	if(strisalpha(getArrayValue(0, arr))){
		//Check for an open parenthesis as the second
		//token which signals a function call.
		if(streq(getArrayValue(1, arr), "(")){
			statement = analyzeFunctionCall(arr);
		}
		//It's a variable declaration parse the statement
		//as a variable declaration.
		statement = analyzeVariable(arr);
	}

	if(!statement){
		//If statement is null that means we
		//failed to determine the type of statement.
	}

	programNode->children[0] = newNode(statement, 0);

	return programNode;
}

node analyze(array tokens){
	size_t index;
	bool str = false;
	node programNode = newNode("PROGRAM", 0);
	node programStart = programNode;

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

	return programStart;
}