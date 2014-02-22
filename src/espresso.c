#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include "espresso.h"
#include "var.h"
#include "hashmap.h"

int main(int argc, string argv[]){
	checkArgs(argc, argv);

	if(argc >= 2){
		string contents = (string) readFile(argv[1]);

		process(contents);

		free(contents);
	}
	else{
		printf("<Invalid number of arguments supplied.>\n");
		ABORT();
	}

	return 0;
}