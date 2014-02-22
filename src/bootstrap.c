#include <stdlib.h>
#include "types.h"
#include "espresso.h"

/**
 * Global Variables
 */
bool DEBUG = false;

/**
 * Functions
 */
void checkArgs(int argc, string argv[]){
	while(argc > 2){
		if(argv[argc - 1][0] == '-'){
			switch(argv[argc - 1][1]){
				case 'd':
					DEBUG = true;
					break;

				default:
					printf("<Invalid flag supplied: %c>\n", argv[argc - 1][1]);
					EXIT(1);
			}
		}
		else{
			printf("<Invalid number of arguments supplied.>");
			EXIT(1);
		}

		argc--;
	}
}

string readFile(string path){
	file f = fopen(path, "rb");

	string contents;
	long length;

	if(f){
		fseek(f, 0, SEEK_END);
		length = ftell(f);
		fseek(f, 0, SEEK_SET);

		contents = (string) malloc(length + 1);

		fread(contents, length, 1, f);
		fclose(f);

		contents[length] = 0;

		return contents;
	}

	printf("<File Not Found: %s>", path);
	EXIT(1);
}