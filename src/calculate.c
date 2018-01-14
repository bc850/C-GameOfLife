#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

#include "calculate.h"
#include "lifedisplay.h"
#include "nextgen.h"

void calculate(int perc, int w, int h){
	int a=0, b=0, loop=0;
	int num;
	char place;

	// make a wrapper around the contents
	char currentGen[h][w];

	// have to seed rand() with time to get different
	// sequence of numbers
	srand(time(NULL));

	// making a casing around the 2d array
        // to use for copying values to mimick
        // a ball
        //
        // * * * * *   9 7 8 9 7
        // * 1 2 3 *   3 1 2 3 1
        // * 4 5 6 *   6 4 5 6 4
        // * 7 8 9 *   9 7 8 9 7
        // * * * * *   3 1 2 3 1

	for(a = 0; a < h; a++){
		for(b = 0; b < w; b++){
			num = rand() % 101;
			if(num < perc + 1){
				place = 'X';
			} else {
				place = ' ';
			}

			if(a == 0){
				currentGen[a][b] = '*';
			} else if(a == (h-1)){
				currentGen[a][b] = '*';
			} else if(b == 0 || b == (w-1)){
				currentGen[a][b] = '*';
			} else {
				currentGen[a][b] = place;
			}
		}
	}

	while(loop == 0){
		system("clear");

		// pass currentGen array to lifedisplay
		// use pointer to currentGen in lifedisplay
		// to print out 2d array
		lifedisplay(currentGen, w, h);

		// nextGen() will use pointer to currentGen
		// array to update values and lopp, passing
		// updated array to display
		nextgen(currentGen, w, h);

		usleep(200000);
	}
}
