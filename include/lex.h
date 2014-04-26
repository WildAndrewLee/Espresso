#include "types.h"
#include "tree.h"
#include "dynamicarray.h"
#include "hashmap.h"

#ifndef _LEX_H_
#define _LEX_H_
array getBlock(array tokens, size_t* index, string open, string close);
array getBlockTo(array tokens, size_t* index, string stop);
node analyzeIf(node programNode, array tokens, size_t* index);
node analyzeElse(node programNode, array tokens, size_t* index);
node analyzeString(node programNode, array tokens, size_t* index);
node analyzeWhile(node programNode, array tokens, size_t* index);
node analyzeFunctionCall(array tokens);
node analyzeStatement(node programNode, array tokens, size_t* index);
node analyze(array tokens);
#endif