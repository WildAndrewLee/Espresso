#include "types.h"
#include "keys.h"

const unsigned int KEYWORDS_SIZE = 7;
string KEYWORDS[] = {
	"if",
	"else",
	"then",
	"for",
	"while",
	"lambda",
	"function"
};

const unsigned int WHITESPACE_DELIMITERS_SIZE = 4;
char WHITESPACE_DELIMITERS[] = {
	' ',
	'\n',
	'\t',
};

const unsigned int TOKEN_DELIMITERS_SIZE = 17;
char TOKEN_DELIMITERS[] = {
	'(',
	')',
	'"',
	',',
	'\'',
	'=',
	'>',
	'<',
	'^',
	'%',
	'+',
	'-',
	'*',
	'/',
	'#',
	'[',
	']',
};