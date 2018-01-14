#include <stdio.h>

#include "nextgen.h"

int i = 0, j = 0, zz = 1, vv = 1;

void nextgen(void *currentGen, int width, int height){
        char temp[height][width];
        char nextGen[height][width];
        char (*curg)[width] = currentGen;
        char *p;

        // Set temp to currentGen
        for(i = 0; i < height; i++){
                for(j = 0; j < width; j++){
                        temp[i][j] = curg[i][j];
                }
        }

	// make the casing contents correct
        for(i = 0; i < height; i++){
                for(j = 0; j < width; j++){
                        if((i == 0) && (j == 0)){
                                temp[i][j] = *(*(temp + height-2) + width-2);
                        }
                        if((i == 0) && (j == width - 1)){
                                temp[i][j] = *(*(temp + height-2) + 1);
                        }
                        if((i == 0) && (j > 0) && (j < width - 1)){
                                temp[i][j] = *(*(temp + height-2) + j);
                        }
                        if((i > 0) && (i < height - 1) && (j == 0)){
                                temp[i][j] = *(*(temp+ i) + width-2);
                        }
                        if((i > 0) && (i < height - 1) && (j == width - 1)){
                                temp[i][j] = *(*(temp + i) + 1);
                        }
                        if((i == height - 1) && (j == 0)){
                                temp[i][j] = *(*(temp + 1) + width-2);
                        }
                        if((i == height - 1) && (j == width - 1)){
                                temp[i][j] = *(*(temp + 1) + 1);
                        }
                        if((i == height - 1) && (j > 0) && (j < width - 1)){
                                temp[i][j] = *(*(temp + 1) + j);
                        }
                }
        }

	// establish nextGen array with all '*' in the fields
        for(i = 0; i < height; i++){
                for(j = 0; j < width; j++){
                        nextGen[i][j] = '*';
                }
        }

	// do really fun logic to populate nextGen array with correct cells
        for(i = 1; i < height - 1; i++){
                for(j = 1; j < width - 1; j++){
                        //conditions for checking grid neighbors
                        int count = 0;
                        for(zz = i-1; zz <= i+1; zz++){
                                for(vv = j-1; vv <= j+1; vv++){
                                        if(*(*(temp + zz) + vv) == 'X'){
                                                count++;
                                        }
                                }
                        }

                        // Set the count -1 if curent cell is 'X'
                        if(*(*(temp + i) + j) == 'X'){
                                count--;
                        }

			// conditions for dead or alive cell
                        if(count < 2 && *(*(temp + i) + j) == 'X'){ // dies of loneliness
                                nextGen[i][j] = ' ';
                        }
                        if(count < 2 && *(*(temp + i) + j) == ' '){ // doesn't birth
                                nextGen[i][j] = ' ';
                        }
                        if(count == 2 && *(*(temp + i) + j) == 'X'){ // stays alive
                                nextGen[i][j] = 'X';
                        }
                        if(count == 2 && *(*(temp + i) + j) == ' '){ // doesn't birth
                                nextGen[i][j] = ' ';
                        }
                        if(count == 3 && *(*(temp + i) + j) == 'X'){ // stays alive
                                nextGen[i][j] = 'X';
                        }
                        if(count == 3 && *(*(temp + i) + j) == ' '){ // birth
                                nextGen[i][j] = 'X';
                        }
                        if(count > 3 && *(*(temp + i) + j) == 'X'){ // dies of overcrowding
                                nextGen[i][j] = ' ';
                        }
                        if(count > 3 && *(*(temp + i) + j) == ' '){ // doesn't birth
                                nextGen[i][j] = ' ';
                        }

                }
        }

        // make nextGen the now currentGen
        for(i = 0; i < height; i++){
                for(j = 0; j < width; j++){
                        curg[i][j] = *(*(nextGen + i) + j);
                }
        }
}
