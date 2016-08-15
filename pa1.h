// pa1.h
//  Created by Charles "Chandler" Griffin on 2/6/16
//  Turned in February 18th, 2016.

#ifndef pa1_h
#define pa1_h

#include <stdio.h>
#include <iostream>
#include <limits>
#include <math.h>

using namespace std;

//The count function prints out the sums of the rows, columns, and diagonals.
void count(int** magicSquare, int size);

//The create function creates the first magic square.
void create(int** magicSquare, int size);

//The firstFlip function creates the second magic square by flipping over the diagonal [0][0] to [size-1][size-1]
void firstFlip(int** magicSquare, int size);

//The secondFlip function creates the third magic square by inverting the previous case so that the first row is now the last row in reverse order
void secondFlip(int** magicSquare, int size);

#endif /* pa1_h */
