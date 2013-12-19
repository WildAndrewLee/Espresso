#include <stdlib.h>
#include <stdio.h>
#include "espresso.h"

bool DEBUG = false;

int main(int argc, string argv[]){
	//Check command line flags.
	while(argc > 2){
		if(argv[argc - 1][0] == '-'){
			switch(argv[argc - 1][1]){
				case 'd':
					DEBUG = true;
					break;

				default:
					printf("<Invalid flag supplied: %c>\n", argv[argc - 1][1]);
					abort();
			}
		}
		else{
			printf("<Invalid number of arguments supplied.>");
			abort();
		}

		argc--;
	}

	if(argc == 2){
		//Open the Expresso file in binary mode.
		file f = fopen(argv[1], "rb");

		//Get the file size to malloc.
		string contents;
		long length;

		if(f){
			fseek(f, 0, SEEK_END);
			length = ftell(f);
			fseek(f, 0, SEEK_SET);

			contents = emalloc(length + 1);

			fread(contents, length, 1, f);
			fclose(f);

			contents[length] = 0;

			printf("%s", contents);

			efree(contents);
		}
	}
	else{
		printf("<Invalid number of arguments supplied.>\n");
		abort();
	}

	return 0;
}