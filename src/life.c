#include <stdio.h>
#include <stdlib.h>
#include "calculate.h"

int main(int argc, char *argv[]){
	int width=30, height=30, percentage=10;

	// life is argv0, next num is argv1
	// 2nd num is argv2, 3rd num is argv3

	if(argc > 1 && argc < 3){
		percentage = atoi(argv[1]);
	} else if(argc == 3){
		height = atoi(argv[1]);
		width = atoi(argv[2]);
	} else if(argc > 3){
		percentage = atoi(argv[1]);
		height = atoi(argv[2]);
		width = atoi(argv[3]);
	}

	printf("percentage = %d, width = %d, height = %d\n", percentage, width, height);
	width += 2;
	height += 2;
	calculate(percentage, width, height);
}
