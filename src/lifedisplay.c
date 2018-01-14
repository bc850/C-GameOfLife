#include <stdio.h>

#include "lifedisplay.h"

int x=0, y=0;

// void *currentGen is a "generic" pointer type. It can be converted
// to any pointer type without an explicit cast
void lifedisplay(void *currentGen, int width, int height){
	// we need a pointer to an array the size of width, not height because we 
        // are printing left to right on the width of 2d array and then moving
        // to the next line.
        //
        // so we will name it "cg" for current generation, cg is the name
        // *cg is the pointer
        // (*cg)[width] is a pointer "cg" to an array the size of [width]
        // char (*cg)[width] is a pointer "cg" to an array the size of [width] of type char
        //
        // set it = to the pointer to currentGen[][] 2d array in calculate.c
        char (*cg)[width] = currentGen;

	for(x = 1; x < height - 1; x++){
                for(y = 1; y < width - 1; y++){
                        //print the live cells or blank spaces
                        if(y == 1){
                                printf("%c", cg[x][y]);
                        } else if(y > 1 && y < 9){
                                printf("  %c", cg[x][y]);
                        } else if(y >= 9 && y < 99){
                                printf("  %c", cg[x][y]);
                        }

                        //print the end number
                        if(y == (width-2)){
                                printf("  %d", x);
                        }
                }
                printf("\n");
        }
        for(x = 0; x < width - 2; x++){
                if(x == 0){
                        printf("%d", x+1);
                } else if(x > 0 && x < 9){
                        printf("  %d", x+1);
                } else if(x >= 9 && x < 99){
                        printf(" %d", x+1);
                }
        }
        printf("\n");

        fflush(stdout);
}
