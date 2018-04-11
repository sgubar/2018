#ifndef dk_square_array_h
#define dk_square_array_h

#include <stdio.h>
#include "dk_square.h"

typedef struct tagSquareArray
{
	int number;
	int count;
	
	Square **squares;
	
}SquareArray;

// init/dealloc
SquareArray *createArray(int aNumber);
void freeArray(SquareArray *anArray);

//interface
// returns index of added element OR -1 if fail
int addElement(SquareArray *anArray, Square *aSquare);
void writeArrayToJSON(FILE *aFile, SquareArray *anArray);

#endif
