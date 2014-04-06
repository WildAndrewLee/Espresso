#include "types.h"
#include "tree.h"
#include "dynamicarray.h"
#include "hashmap.h"

#ifndef _LEX_H_
#define _LEX_H_
array getBlock(array tokens, size_t* index, string open, string close);
node analyzeIf(node programNode, array tokens, size_t* index);
node analyzeElse(node programNode, array tokens, size_t* index);
node analyzeString(node programNode, array tokens, size_t* index);
node analyze(array tokens);
#endif