# Game Of Life in the C Programming Language

The Game of Life, invented by John. H. Conway, is supposed to model the genetic laws for birth, survival, and death. (See Scientific American, October, 1970, p.p. 120). This game can be played on a board that consists of say 25 squares in the horizontal and vertical directions (so a total of 625 squares). Each square can be empty, or it can contain an X indicating the presence of an organism. Each square has eight neighbors. 

The next generation of organisms is determined according to the following criteria:

a.	Birth — an organism will be born in each empty location that has exactly three neighbors;
b.	Death — an organism with four or more organisms as neighbors will die from overcrowding.  An organism with fewer than two neighbors will die from loneliness;
c.	Survival — an organism with two or three neighbors will survive to the next generation. Possible generations 2 and 3 for the sample can be found on the next page.

It is import to understand that all births, death, and survivals from the current generation to the next occur simultaneously.

It is also worth of mentioning that on the board, the top-most row is considered as the neighbor of the bottom-most row (vice versa) and the left-most column is considered as the neighbor of the right-most column (vice versa). In other words, you may think of the game board as wrapping on the surface of a ball.

How the program runs:

When the program is started from the command line, it gets the probability of initial organisms (defaults to 10%, i.e. 10% organisms, 90% empty), height of the board (defaults to 30), and width of the board (defaults to 30) from command line:

¬	gameoflife [organism probability] [height width]

E.g.

¬	gameoflife  10% organisms, 30 by 30 board

¬	gameoflife 20  20% organisms, 30 by 30 board

¬	gameoflife 24 40  10% organisms, 24 by 40 board

¬	gameoflife 15 40 35  15% organisms, 40 by 35 board

The program can be compiled using the provided Makefile.
